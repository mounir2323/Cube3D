/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:15:33 by schibane          #+#    #+#             */
/*   Updated: 2024/04/11 13:17:06 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(t_config *conf, char *str, int fd, char **text)
{
	char	*line;
	char	**splt;

	line = get_next_line(fd);
	while (line && !ft_strncmp(line, "\n", 2))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		splt = ft_split(line, ' ');
		if (!splt)
		{
			free(line);
			clean_exit(1, "error occured try again later !\n", conf);
		}
		if (str_tab_len(splt) == 2 && !ft_strncmp(splt[0], str, 3))
			*text = ft_strtrim(splt[1], "\n");
		free_tab_str(splt);
		free(line);
	}
}

void	get_all_textures(t_config *conf, int fd)
{
	get_texture(conf, "NO", fd, &conf->no);
	if (!conf->no)
		clean_exit(1, "Could not find NO texture in file\n", conf);
	get_texture(conf, "SO", fd, &conf->so);
	if (!conf->so)
		clean_exit(1, "Could not find SO texture in file\n", conf);
	get_texture(conf, "WE", fd, &conf->we);
	if (!conf->we)
		clean_exit(1, "Could not find WE texture in file\n", conf);
	get_texture(conf, "EA", fd, &conf->ea);
	if (!conf->ea)
		clean_exit(1, "Could not find EA texture in file\n", conf);
}

void	print_lst(t_list *lst)
{
	t_list *l;

	l = lst;
	while (l)
	{
		printf("%s\n",(char *)l->content);
		l = l->next;
	}
}

int	parsing(t_config *conf, int fd)
{
	get_all_textures(conf, fd);
	get_colors(conf, fd);
	read_map(fd, conf);
	fill_up_spaces(conf);
	if (!check_map_validity(conf))
		clean_exit(1, "Invalid characteres or multiple players in map\n", conf);
	get_map_normal(conf->map);
	conf->map[conf->player_pos.i][conf->player_pos.j] = conf->player_pos.dir;
	print_lst(conf->map_lst);
	return (1);
}
