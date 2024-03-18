/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:02:48 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/10 18:18:52 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;
	char	*srcc;
	char	*dstt;

	x = 0;
	srcc = (char *)src;
	dstt = (char *)dst;
	if (dst == src)
		return (NULL);
	if (!dst && !src)
		return (NULL);
	while (x < n)
	{
		dstt[x] = srcc[x];
		x++;
	}
	return (dstt);
}
