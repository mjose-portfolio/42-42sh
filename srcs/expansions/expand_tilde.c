/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 02:50:02 by mjose             #+#    #+#             */
/*   Updated: 2019/05/02 05:15:10 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansions.h"
#include "sh42.h"

char	*recup_expath(char **tab_path, int start)
{
	int		i;
	char	*path;

	i = start;
	if (!i)
	{
		path = ft_strdup(tab_path[i] + 1);
		ft_strdel(&tab_path[i]);
		tab_path[i] = ft_strdup(path);
		ft_strdel(&path);
	}
	if (!tab_path[i])
		path = ft_strdup("/");
	else
		path = ft_strnew(1);
	while (tab_path[i])
	{
		tab_path[i] = ft_strjoinfree("/", tab_path[i], 2);
		path = ft_strjoinfree(path, tab_path[i++], 1);
	}
	ft_strdel(&tab_path[0]);
	ft_free(tab_path);
	return (path);
}

void	expand_tilde_pwd(char **str, t_expand **expand)
{
	char	*path;
	char	**tmp;

	path = NULL;
	if (ft_strchr(*str, '/') || !(*expand)->next->next)
	{
		if ((*expand)->next->ltr == '-')
			path = ft_strdup(get_env_string("OLDPWD"));
		else if ((*expand)->next->ltr == '+')
			path = ft_strdup(get_env_string("PWD"));
	}
	if (path && ft_strchr(*str, '/'))
	{
		tmp = ft_strsplit(*str, '/');
		ft_strdel(&tmp[0]);
		tmp[0] = ft_strdup(path);
		ft_strdel(&path);
		path = recup_expath(tmp, 0);
	}
	if (path && path[0])
	{
		ft_strdel(str);
		*str = path;
	}
}

void	expand_tilde_user(char **str)
{
	char	*user;
	char	*tmp_path;
	char	**tmp;
	char	*home;

	tmp_path = NULL;
	if (!ft_strchr(*str, '/'))
		user = ft_strdup(*str + 1);
	else
	{
		tmp = ft_strsplit(*str, '/');
		tmp_path = tmp[0];
		user = ft_strndup(tmp_path + 1, ft_strlen(tmp_path + 1));
		tmp_path = recup_expath(tmp, 1);
	}
	home = get_user_home(user);
	if (home)
	{
		ft_strdel(str);
		if (!tmp_path)
			*str = home;
		else
			*str = ft_strjoinfree(home, tmp_path, 3);
	}
	ft_strdel(&user);
}

void	expand_tilde_path(char **str)
{
	char	*home;
	char	*str_tmp;

	home = get_home_value();
	str_tmp = ft_strjoinfree(home, *str + 1, 1);
	ft_strdel(str);
	*str = str_tmp;
}

void	expand_tilde_only(char **str)
{
	ft_strdel(str);
	*str = NULL;
	*str = get_home_value();
}
