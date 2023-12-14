/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:20:18 by marvin            #+#    #+#             */
/*   Updated: 2023/10/18 11:42:01 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	size_t	i;

	i = n;
	if (!dest && !src)
		return (dest);
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (dest - i);
}
