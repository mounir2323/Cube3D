/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:59:40 by mtayebi           #+#    #+#             */
/*   Updated: 2023/03/24 02:23:42 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	char			*str1;
	char			*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while ((i < n))
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
			i++;
	}
	if (i + 1 > n)
		return (0);
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}
