/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:49:25 by bsiche            #+#    #+#             */
/*   Updated: 2019/05/01 03:02:21 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[i])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return (((char*)haystack) + i - ft_strlen(needle));
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
