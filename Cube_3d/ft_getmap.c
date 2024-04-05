/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:24:18 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/03 23:53:52 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


char	*ft_joinlines(int fd, int nbr_ofread, char *buff, char *line)
{
	line[0] = '\0';
	while (nbr_ofread != 0)
	{
		nbr_ofread = read(fd, buff, 100);
		if (nbr_ofread < 0)
			return (free(buff), free(line), NULL);
		buff[nbr_ofread] = '\0';
		line = ft_strjoin(line, buff);
	}
	return (line);
}

char	**ft_splitmaps(int fd)
{
	char	*buff;
	int		nbr_ofread;
	char	*line;
	char	**lines;

	if (fd < 0)
		return (NULL);
	nbr_ofread = 1;
	buff = malloc(100);
	if (!buff)
		return (NULL);
	line = malloc(100);
	if (!line)
		return (free(buff), NULL);
	line = ft_joinlines(fd, nbr_ofread, buff, line);
	if (!line)
		return (NULL);
	lines = ft_split(line, '\n');
	return (free(buff), free(line), lines);
}

