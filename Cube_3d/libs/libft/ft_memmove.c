/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:12:46 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/10 18:57:40 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcc;
	char	*dstt;

	if (src > dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		if (!dst && !src)
			return (NULL);
		srcc = (char *)src;
		dstt = (char *)dst;
		while (len > 0)
		{
			len--;
			dstt[len] = srcc[len];
		}
		return (dstt);
	}
}
