/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 23:27:28 by schibane          #+#    #+#             */
/*   Updated: 2024/04/21 22:41:16 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && !ft_strncmp(line, "\n", 2))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

char	**get_color(t_config *conf, char *str, int fd)
{
	char	*line;
	char	**splt;
	char	**split_nbr;

	line = read_lines(fd);
	if (line)
	{
		replace_tab(line);
		splt = ft_split(line, ' ');
		if (!splt)
		{
			free(line);
			clean_exit(1, "error occured try again later !\n", conf);
		}
		if (str_tab_len(splt) == 2 && !ft_strncmp(splt[0], str, 2))
		{
			split_nbr = ft_split(splt[1], ',');
			return (free(line), free_tab_str(splt), split_nbr);
		}
		free_tab_str(splt);
		free(line);
	}
	return (NULL);
}

int	check_color_format(char **color_str, int *tab_color)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	if (str_tab_len(color_str) != 3)
		return (free_tab_str(color_str), 0);
	while (color_str[i])
	{
		j = 0;
		while (color_str[i][j] && color_str[i][j] != '\n')
		{
			if (!ft_isdigit(color_str[i][j]))
				return (free_tab_str(color_str), 0);
			j ++;
		}
		if (ft_atoi(color_str[i]) > 255)
			return (free_tab_str(color_str), 0);
		trim = ft_strtrim(color_str[i], "\n");
		tab_color[i] = ft_atoi(trim);
		free(trim);
		i ++;
	}
	return (free_tab_str(color_str), 1);
}

void	get_colors(t_config *conf, int fd)
{
	char	**colorf_str;
	char	**colorc_str;
	int		valid;

	colorf_str = get_color(conf, "F", fd);
	if (!colorf_str)
		clean_exit(1, "Could not find F color\n", conf);
	valid = check_color_format(colorf_str, conf->f);
	colorc_str = get_color(conf, "C", fd);
	if (!colorc_str)
		clean_exit(1, "Could not find C color\n", conf);
	valid = check_color_format(colorc_str, conf->c);
	if (!valid)
		clean_exit(1, "Color format incorrect\n", conf);
}
