/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:25:43 by schibane          #+#    #+#             */
/*   Updated: 2024/04/28 00:42:41 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_char_valid(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}

int	is_char_player(char c)
{
	return (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

int	check_chracters(t_config *conf)
{
	t_list	*lst;
	char	*line;
	int		i;
	int		players;

	lst = conf->map_lst->next;
	players = 0;
	while (lst->next)
	{
		line = (char *)lst->content;
		i = 1;
		while (line[i + 1])
		{
			if (!is_char_valid(line[i]))
				return (0);
			if (is_char_player(line[i]))
				players ++;
			if (players > 1)
				return (0);
			i ++;
		}
		lst = lst->next;
	}
	return (players && 1);
}

void	mark_reachable(char **map, int i, int j, t_config *conf)
{
	if (map[i][j] == '1' || map[i][j] == '2')
		return ;
	if (map[i][j] == 'B')
	{
		clean_exit(1, "The map is not closed, \
			the player can go out of the map", conf);
	}
	map[i][j] = '2';
	mark_reachable(map, i - 1, j, conf);
	mark_reachable(map, i + 1, j, conf);
	mark_reachable(map, i, j - 1, conf);
	mark_reachable(map, i, j + 1, conf);
}

int	check_map_validity(t_config *conf)
{
	if (!check_chracters(conf))
		return (0);
	conf->map = list_to_array(conf);
	if (!conf->map)
		clean_exit(1, "Problem occured please try later\n", conf);
	conf->player_pos = get_player_pos(conf->map);
	mark_reachable(conf->map, conf->player_pos.i, conf->player_pos.j, conf);
	return (1);
}
