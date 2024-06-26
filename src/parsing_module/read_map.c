/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:29:24 by schibane          #+#    #+#             */
/*   Updated: 2024/04/28 00:40:58 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_to_maplst(t_config *conf, t_list **map_lst, char *line)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (!node)
		clean_exit(1,
			"Map empty or problem has occured try later\n", conf);
	ft_lstadd_back(map_lst, node);
}

int	get_biggest_line(t_list *map_lst)
{
	int		i;
	t_list	*tmp;
	char	*line;
	int		biggest;

	tmp = map_lst;
	biggest = 0;
	while (tmp)
	{
		i = 0;
		line = (char *)tmp->content;
		while (line[i] && line[i] != '\n')
			i ++;
		if (i > biggest)
			biggest = i;
		tmp = tmp->next;
	}
	return (biggest);
}

char	*add_side_borders_fill_space(t_config *conf, t_list *current)
{
	char	*new_line;
	char	*line;
	int		i;

	line = (char *)current->content;
	i = 1;
	new_line = malloc(conf->biggest_mapline + 2);
	if (!line)
		clean_exit(1, "Error occured please try later\n", conf);
	new_line[0] = 'B';
	while (line[i - 1] && line[i - 1] != '\n')
	{
		if (line[i - 1] == ' ' || line[i - 1] == '\t')
			new_line[i] = '0';
		else
			new_line[i] = line[i - 1];
		i ++;
	}
	while (i < conf->biggest_mapline + 1)
	{
		new_line[i] = '0';
		i ++;
	}
	new_line[conf->biggest_mapline + 1] = 'B';
	return (new_line[conf->biggest_mapline + 2] = '\0', new_line);
}

void	add_bottom_border(t_config *conf)
{
	char	*borders;
	int		i;

	borders = malloc(conf->biggest_mapline + 2);
	i = 0;
	if (!borders)
		clean_exit(1, "Map empty or problem has occured try later\n", conf);
	while (i < conf->biggest_mapline + 2)
	{
		borders[i] = 'B';
		i ++;
	}
	borders[i] = '\0';
	add_to_maplst(conf, &conf->map_lst, borders);
}

void	add_top_border(t_config *conf)
{
	char	*borders;
	int		i;
	t_list	*node;

	borders = malloc(conf->biggest_mapline + 2);
	i = 0;
	if (!borders)
		clean_exit(1, "Map empty or problem has occured try later\n", conf);
	while (i < conf->biggest_mapline + 2)
	{
		borders[i] = 'B';
		i ++;
	}
	borders[i] = '\0';
	node = ft_lstnew(borders);
	if (!node)
		clean_exit(1,
			"Map empty or problem has occured try later\n", conf);
	ft_lstadd_front(&conf->map_lst, node);
}
