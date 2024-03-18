/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:22:11 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/10 18:30:24 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*to_find;
	char	*str;
	size_t	i;
	int		j;

	str = (char *) haystack;
	to_find = (char *)needle;
	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
