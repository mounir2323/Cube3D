/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:14:57 by mtayebi           #+#    #+#             */
/*   Updated: 2023/03/27 01:21:50 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*x;

	c = (char)c;
	x = (char *) s;
	len = (int)ft_strlen(s) - 1 ;
	if (c == '\0')
		return (&x [len + 1]);
	while (len >= 0)
	{
		if (x[len] == c)
			return (&x[len]);
		len--;
	}
	return (0);
}
