/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:24:09 by marvin            #+#    #+#             */
/*   Updated: 2023/10/16 17:29:20 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*res;

	index = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return ((void *)0);
	while (index < ft_strlen(s))
	{
		res[index] = f(index, s[index]);
		index++;
	}
	return (res[index] = '\0', res);
}
