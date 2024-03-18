/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:27:42 by mtayebi           #+#    #+#             */
/*   Updated: 2023/03/23 23:45:35 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;
	char	x;

	i = 0;
	str = (char *)s;
	x = (char)c;
	while (i < n)
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
