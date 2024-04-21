/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:04:21 by schibane          #+#    #+#             */
/*   Updated: 2024/04/05 00:40:29 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #include "get_next_line_utils.c"
// #include <stdio.h>
// #include <fcntl.h>	
// # include <unistd.h>
// # include <stdlib.h>
// # include <stddef.h>

// int mem_counter = 0;
// void my_free(void * p)
// {
//   free(p);
//   printf ("Free memory %p \n", p);
//   printf ("Current leak counter %d\n", --mem_counter);
// }
// void * my_malloc(int size)
// {
//   void * ret;
//   ret = malloc(size);
//   if(ret) {
//     printf ("Allocated memory @%p of size %d \n", ret, size);
//     printf ("Current leak counter %d\n", ++mem_counter);
//   }
//   return ret;
// }
// #undef malloc
// #define malloc(size) my_malloc(size)
// #undef free
// #define free(p) my_free(p)

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t		count;
// 	char		*dst_dst;
// 	const char	*src_src;

// 	count = 0;
// 	dst_dst = (char *)dst;
// 	src_src = (const char *)src;
// 	if (dst == NULL && src == NULL)
// 		return (NULL);
// 	while (count < n)
// 	{
// 		dst_dst[count] = src_src[count];
// 		count++;
// 	}
// 	return (dst);
// }

// char	*ft_strdup(const char *s1)
// {
// 	size_t	s_len;
// 	char	*s2;

// 	s_len = ft_strlen(s1) + 1;
// 	s2 = malloc(s_len);
// 	if (s2 == NULL)
// 		return (NULL);
// 	return ((char *)ft_memcpy(s2, s1, s_len));
// }

// char	*extract_line(char **storage)
// {
// 	int		found;
// 	char	*temp;
// 	int		len;
// 	char	*line;

// 	line = NULL;
// 	if (*storage == NULL)
// 		return (NULL);
// 	found = line_schr(*storage);
// 	if (found == -1)
// 		found = ft_strlen(*storage);
// 	len = ft_strlen(*storage);
// 	line = ft_substr(*storage, 0, found + 1);
// 	if (!line)
// 		return (NULL);
// 	temp = ft_substr(*storage, found + 1, len - found);
// 	if (!temp)
// 		return (free(*storage), *storage = NULL, line);
// 	// if (!*temp)
// 	// 	return (free(*storage), *storage = NULL, line);
// 	free(*storage);
// 	*storage = ft_strdup(temp);
// 	free(temp);
// 	return (line);
// }
int	line_schr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0 && s[i] != '\n')
	{
		i++;
	}
	if (s[i] == '\n')
		return (i + 1);
	return (i);
}

int	ft_strchr2(char *str, int c)
{
	if (!str)
		return (0);
	while (*str != (char)c)
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return ((int)*str);
}

char	*read_once(char *storage, int fd, int *nbr_read)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	*nbr_read = read(fd, buff, BUFFER_SIZE);
	if (*nbr_read < 0)
		return (free(buff), free(storage), storage = NULL, NULL);
	buff[*nbr_read] = '\0';
	if (*nbr_read == 0)
	{
		free(buff);
	}
	return (buff);
}

char	*read_iter(int fd, char *storage, int *nbr_read)
{
	int		found;
	char	*buff;

	found = 0;
	while (*nbr_read != 0 && found == 0)
	{
		buff = read_once(storage, fd, nbr_read);
		if (!buff)
			return (NULL);
		if (*nbr_read == 0)
			break ;
		storage = ft_strjoin(storage, buff);
		if (!storage)
			return (free(buff), buff = NULL, NULL);
		found = ft_strchr2(storage, '\n');
		free(buff);
	}
	if (storage)
	{
		if (!*storage)
			return (free(storage), storage = NULL, NULL);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*temp;
	int			r;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(storage), storage = NULL, NULL);
	if (ft_strchr2(storage, '\n') == 0)
	{
		storage = read_iter(fd, storage, &r);
		if (r < 0)
			return (free(storage), storage = NULL, NULL);
	}
	line = ft_substr(storage, 0, line_schr(storage));
	temp = storage;
	storage = ft_substr(temp, line_schr(storage),
			ft_strlen(storage + line_schr(storage)));
	free(temp);
	temp = NULL;
	return (line);
}

// int main()
// {
// 	int fd;
// 	// char buff[BUFFER_SIZE];
// 	char path[] = "test.txt";
// 	fd = open(path, O_RDONLY);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// printf("\n");
// 	// char *d;
// 	// printf("%s",d);
// 	// d = get_next_line(fd);
// 	// printf("%s",d);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// // get_next_line(fd);
// // get_next_line(fd);
// // get_next_line(fd);
// // get_next_line(fd);
// // get_next_line(fd);
// 	// printf("\n");
// 	return (0);
// }