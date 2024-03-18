/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:43:22 by mtayebi           #+#    #+#             */
/*   Updated: 2023/03/28 00:03:31 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dest;
	int		i;

	i = 0;
	size = ft_strlen (s1);
	dest = malloc (size + 1);
	if (dest == 0)
		return (NULL);
	while (s1[i] != 0)
	{
	dest[i] = s1[i];
		i++;
	}
		dest[i] = '\0';
	return (dest);
}
