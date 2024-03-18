/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:14:30 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/08 17:34:50 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		c1;
	unsigned char		*y;
	size_t				i;

	y = (unsigned char *) b;
	c1 = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		y[i] = c1;
		i++;
	}
	return ((void *)y);
}
