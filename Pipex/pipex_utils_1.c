/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:22:11 by faata             #+#    #+#             */
/*   Updated: 2023/12/19 12:28:10 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_strncmp(const char	*s1, const char	*s2, size_t n)
{
	while (((unsigned char)*s1 || (unsigned char)*s2) && n--)
		if ((unsigned char)*s1++ != (unsigned char)*s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
