/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:52:07 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/08 17:34:01 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	dst = malloc ((len * sizeof(char)) + 1);
	if (dst == 0 || s == 0)
		return (NULL);
	while (s[start] != 0 && i < len)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
