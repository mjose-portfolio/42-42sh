/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 07:07:00 by mjose             #+#    #+#             */
/*   Updated: 2019/04/30 00:02:45 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

#define PREV list->prev
#define LIST list->type

t_last		*new_list(void)
{
	t_last		*new;

	new = ft_memalloc(sizeof(t_last));
	new->name = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->type = 0;
	return (new);
}

void		tokenize_arg(t_last *list)
{
	t_last	*prev;

	prev = NULL;
	if (PREV->type == FICH)
	{
		prev = PREV;
		while (prev && prev->type != CMD)
			prev = prev->prev;
		if (!prev)
			LIST = CMD;
		else
			LIST = ARG;
	}
	else
		LIST = ARG;
}

void		tokenize_opt(t_last *list)
{
	t_last	*prev;

	prev = NULL;
	if (PREV && (PREV->type == CMD || PREV->type == OPT)
			&& list->name[0] == '-')
		LIST = list->name[1] ? OPT : ARG;
	else if ((PREV && (PREV->type == CMD || PREV->type == FICH
					|| PREV->type == OPT)))
	{
		if (PREV->type == FICH)
		{
			prev = PREV;
			while (prev && prev->type != CMD)
				prev = prev->prev;
			if (!prev)
				LIST = CMD;
			else
				LIST = OPT;
		}
	}
	else if (PREV && PREV->type == ARG)
		LIST = ARG;
}

void		tokenize_list(t_last *list)
{
	if (!list)
		return ;
	if (list->name[0] == '-')
		tokenize_opt(list);
	else if (PREV && (PREV->type == FICH || PREV->type == OPT
				|| PREV->type == ARG))
		tokenize_arg(list);
	else if (its_pipe(list) || its_reddir(list) || its_fd_reddir(list))
		LIST = OP;
	else if (LIST != SEP && LIST != OP && (PREV && (PREV->type == OPT
					|| PREV->type == CMD)))
		LIST = ARG;
}

void		convert_list(t_last *list)
{
	t_last	*begin;
	t_last	*prev;

	begin = list;
	prev = NULL;
	while (list)
	{
		if (!its_indir(list->name) && !its_heredoc(list->name)
				&& !its_reddir(list) && !its_fd_reddir(list)
				&& (!PREV || (PREV && (its_pipe(PREV) || PREV->type == SEP))))
			LIST = CMD;
		else if (its_separator(list) || its_eper(list))
			LIST = SEP;
		else if (its_pipe(list) || its_reddir(list) || its_fd_reddir(list)
				|| its_heredoc(list->name) || its_indir(list->name))
			LIST = OP;
		else if (PREV && (its_reddir(PREV) || its_fd_reddir(PREV)
					|| its_indir(PREV->name) || its_heredoc(PREV->name)))
			LIST = FICH;
		else
			tokenize_list(list);
		list = list->next;
	}
}
