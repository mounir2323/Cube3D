/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:32:44 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/08 17:33:48 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	int		i;

	c = (char)c;
	i = 0;
	src = (char *)(s);
	while (*src != '\0')
	{
	src = (char *)(s + i);
		if (*src == c)
			return (src);
	src++;
	i++;
	}
	if (c == 0)
		return (src);
	return (NULL);
}
