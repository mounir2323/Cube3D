/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:07:27 by schibane          #+#    #+#             */
/*   Updated: 2024/04/05 00:38:43 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
// {
// 	size_t	i;
// 	size_t	x;

// 	x = ft_strlen(src);
// 	i = 0;
// 	if (dstsize != 0)
// 	{
// 		while (src [i] != '\0' && i < dstsize - 1)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (x);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	dstlen;
// 	size_t	src_len;

// 	dstlen = ft_strlen(dst);
// 	src_len = ft_strlen(src);
// 	if (dstsize <= dstlen)
// 		return (dstsize + src_len);
// 	i = dstlen;
// 	j = 0;
// 	while (src[j] != '\0' && i < dstsize - 1)
// 	{
// 		dst[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dst[i] = '\0';
// 	return (dstlen + ft_strlen(&src[j]));
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	size_t	dst_size;
// 	size_t	len_s1;

// 	if (!s1)
// 	{
// 		s1 = malloc(1);
// 		if (!s1)
// 			return (NULL);
// 		s1[0] = 0;
// 	}
// 	len_s1 = ft_strlen(s1);
// 	dst_size = len_s1 + ft_strlen(s2) + 1;
// 	str = (char *)malloc(dst_size);
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s1, len_s1 + 1);
// 	ft_strlcat(str, s2, dst_size);
// 	free(s1);
// 	s1 = NULL;
// 	return (str);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char		*str;
// 	size_t		len_s;

// 	if (!s)
// 		return (NULL);
// 	len_s = ft_strlen(s);
// 	if (start >= len_s)
// 		return (NULL);
// 	if (len > len_s - (unsigned int)start)
// 		len = len_s - (unsigned int)start;
// 	str = (char *) malloc(len + 1);
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s + start, len + 1);
// 	return (str);
// }
