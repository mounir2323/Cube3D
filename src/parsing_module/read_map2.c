/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:21:31 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/28 00:51:52 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_up_spaces(t_config *conf)
{
	t_list	*tmp;
	char	*line;

	tmp = conf->map_lst;
	conf->biggest_mapline = get_biggest_line(conf->map_lst);
	while (tmp)
	{
		line = add_side_borders_fill_space(conf, tmp);
		free(tmp->content);
		tmp->content = line;
		tmp = tmp->next;
	}
	add_top_border(conf);
	add_bottom_border(conf);
}

void	read_map(int fd, t_config *conf)
{
	t_list	*map_lst;
	char	*line;
	int		start;
	int		i;

	i = 0;
	start = 0;
	line = get_next_line(fd);
	map_lst = NULL;
	if (!line)
		clean_exit(1, "Map empty or problem has occured try later\n", conf);
	while (line)
	{
		if (ft_strncmp(line, "\n", 3) || start)
		{
			i++;
			add_to_maplst(conf, &map_lst, line);
			start = 1;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	conf->map_lst = map_lst;
}
