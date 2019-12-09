/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:58:59 by bsiche            #+#    #+#             */
/*   Updated: 2019/04/18 02:10:31 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

t_lstcontainer		*type_ls(int argc, char **argv)
{
	int				i;
	char			*str;
	int				flag;
	int				called;
	t_lstcontainer	*liste;

	i = 1;
	flag = 0;
	called = 0;
	str = ft_strdup("-ld");
	if (argc == 1)
	{
		liste = ft_ls(".", str);
		ft_free(str);
		return (liste);
	}
	i = ft_option(argv, &str, &flag);
	while (argc > i && flag != 1)
	{
		liste = ft_ls(argv[i], str);
		i++;
		called = 1;
	}
	ft_free(str);
	return (liste);
}

char				*get_option(void)
{
	char			*str;

	if (g_tracking.aut->hidden == 0)
		str = ft_strdup("-G");
	else
		str = ft_strdup("-aG");
	return (str);
}

t_lstcontainer		*modified_ls(int argc, char **argv)
{
	int				i;
	char			*str;
	int				flag;
	int				called;
	t_lstcontainer	*liste;

	i = 1;
	flag = 0;
	called = 0;
	str = get_option();
	if (argc == 1)
	{
		liste = ft_ls(".", str);
		ft_free(str);
		return (liste);
	}
	i = ft_option(argv, &str, &flag);
	while (argc > i && flag != 1)
	{
		liste = ft_ls(argv[i], str);
		i++;
		called = 1;
	}
	ft_free(str);
	return (liste);
}
