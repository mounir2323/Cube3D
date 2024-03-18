/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:16:28 by mtayebi           #+#    #+#             */
/*   Updated: 2023/06/21 14:51:10 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		l1;
	int		l2;
	int		size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	size = l1 + l2;
	dest = malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, l1);
	ft_memcpy(&dest[l1], s2, l2);
	dest [size] = '\0';
	return (free(s1), dest);
}
