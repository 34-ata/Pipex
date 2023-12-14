/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:23:38 by marvin            #+#    #+#             */
/*   Updated: 2023/10/16 17:25:33 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t sz)
{
	size_t	i;

	i = 0;
	if (!sz)
		return (ft_strlen(src));
	while (src[i] && i < sz - 1)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest[i] = '\0', ft_strlen(src));
}
