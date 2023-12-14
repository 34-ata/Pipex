/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:22:11 by marvin            #+#    #+#             */
/*   Updated: 2023/10/16 20:26:53 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const	*str, char c, int i, int count)
{
	while (str[i])
	{
		while ((str[i] && str[i] == c) && (i++, 1))
			;
		(void)(str[i] && (count++, 0))
			;
		while ((str[i] && str[i] != c) && (i++, 1))
			;
	}
	return (count);
}

static int	ft_strlen_sep(char const	*str, char c, int i)
{
	while ((str[i] && str[i] != c) && (i++, 1))
		;
	return (i);
}

char	**ft_split(char const	*str, char c)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *)
			* (count_strings(str, c, 0, 0) + 1));
	if (!strings)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			strings[i] = ft_substr(str, 0, ft_strlen_sep(str, c, 0));
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	return (strings[i] = 0, strings);
}
