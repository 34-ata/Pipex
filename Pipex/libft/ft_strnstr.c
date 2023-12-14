/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:24:45 by marvin            #+#    #+#             */
/*   Updated: 2023/10/16 16:40:22 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *find, size_t len)
{
	if (*find == 0)
		return ((char *)dest);
	while ((*dest && ft_strlen(find) <= len) && (--len, 1))
	{
		if ((*dest == *find && ft_strncmp(dest, find, ft_strlen(find)) == 0))
			return ((char *)dest);
		dest++;
	}
	return ((void *)0);
}
