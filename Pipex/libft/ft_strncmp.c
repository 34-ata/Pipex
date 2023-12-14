/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:24:22 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 18:17:55 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char	*s2, size_t n)
{
	while (((unsigned char)*s1 || (unsigned char)*s2) && n--)
		if ((unsigned char)*s1++ != (unsigned char)*s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return (0);
}
