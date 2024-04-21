/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:47:18 by schibane          #+#    #+#             */
/*   Updated: 2024/04/06 22:13:15 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	dst_size;

// 	dst_size = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	str = (char *)ft_calloc(dst_size, 1);
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
// 	ft_strlcat(str, s2, dst_size);
// 	free((void *)s1);
// 	return (str);
// }
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	dst_size;
	size_t	len_s1;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	len_s1 = ft_strlen(s1);
	dst_size = len_s1 + ft_strlen(s2) + 1;
	str = (char *)malloc(dst_size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, dst_size);
	free(s1);
	s1 = NULL;
	return (str);
}
