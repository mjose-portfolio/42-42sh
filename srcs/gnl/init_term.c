/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:29:52 by bsiche            #+#    #+#             */
/*   Updated: 2019/05/03 04:02:09 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void	init_builtin_list(void)
{
	g_tracking.builtin_list = lstcontainer_new();
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("jobs"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("fg"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("exit"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("bg"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("echo"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("set"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("test"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("hash"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("cd"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("unalias"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("alias"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("unset"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("export"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("history"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("fc"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("kirby"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("type"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("true"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("false"));
	lstcontainer_add(g_tracking.builtin_list, ft_strdup("."));
}

void	init_cpaste(void)
{
	g_tracking.cpaste->b1 = 0;
	g_tracking.cpaste->b2 = 0;
	g_tracking.cpaste->line = NULL;
}

void	init_key_list(void)
{
	g_tracking.key_list = lstcontainer_new();
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_LEFT));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_RIGHT));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_DOWN));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_UP));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_LUP));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_LDOWN));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_WLEFT));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_WRIGHT));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_DEL));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_ESC));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_FN1));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_FN2));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_FN3));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_HOME));
	lstcontainer_add(g_tracking.key_list, ft_strdup(K_END));
}

void	cursor_reset(void)
{
	if (g_tracking.cpaste)
		ft_free(g_tracking.cpaste);
	g_tracking.pos->abs = 0;
	g_tracking.pos->x = 1;
	g_tracking.pos->y = 0;
	g_tracking.pos->relx = 1;
	g_tracking.pos->rely = 0;
	g_tracking.pos->legacy = 0;
	g_tracking.swi = 0;
	g_tracking.cpaste = ft_malloc(sizeof(t_cpaste));
	g_tracking.cpaste->line = NULL;
	g_tracking.buffsize = 2;
	g_tracking.search = NULL;
	g_tracking.found = NULL;
	g_tracking.quotes = 0;
	g_tracking.herenbr = 0;
}

void	cursorinit(void)
{
	if ((g_tracking.pos = ft_malloc(sizeof(t_cursor) + 1)) == NULL)
	{
		ft_putendl("Failled to allocate memory");
		ft_exit2(EXIT_FAILURE);
	}
	cursor_reset();
	init_key_list();
	init_builtin_list();
}
