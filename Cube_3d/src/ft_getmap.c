/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:24:18 by mtayebi           #+#    #+#             */
/*   Updated: 2023/07/23 20:36:19 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	ft_chek_dnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n'))
			return (false);
		i++;
	}
	return (true);
}

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
	if (!ft_chek_dnl(line))
		return (free(line), NULL);
	lines = ft_split(line, '\n');
	return (free(buff), free(line), lines);
}

bool	ft_check_validformat(char *str)
{
	int		len;
	int		i;
	char	*ber;

	len = ft_strlen(str);
	ber = ".ber";
	i = 0;
	if (len < 5)
		return (false);
	if (ft_strnstr(str, ".ber.ber", ft_strlen(str))
		|| ft_strnchr(str, '.', ft_strlen(str) - 4) == true)
		return (false);
	while (str[len - 4] != '\0' && ber[i] != '\0' )
	{
		if (ber[i] != str[len - 4])
			return (false);
		i++;
		len++;
	}
	return (true);
}
