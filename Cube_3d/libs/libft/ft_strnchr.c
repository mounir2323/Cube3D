/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:29:39 by mtayebi           #+#    #+#             */
/*   Updated: 2023/08/07 04:28:40 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strnchr(const char *s, int c, int n)
{
	char	*src;
	int		i;

	src = (char *)s;
	i = 0;
	while (*src != '\0' && i < n)
	{
		if (*src == c)
			return (true);
		src++;
		i++;
	}
	if (c == '\0')
		return (true);
	return (false);
}
