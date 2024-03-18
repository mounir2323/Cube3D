/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_solong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:09:01 by mtayebi           #+#    #+#             */
/*   Updated: 2023/08/07 01:44:18 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_fill(char **copy, int y, int x)
{
	if (copy[y][x] == '1' || copy[y][x] == 'X')
		return ;
	copy[y][x] = 'X';
	ft_fill(copy, y + 1, x);
	ft_fill(copy, y - 1, x);
	ft_fill(copy, y, x + 1);
	ft_fill(copy, y, x - 1);
}

bool	ft_check_valid_path(t_map *map, int y, int x)
{
	char	**copy;

	copy = ft_matcpy(map->map);
	ft_fill(copy, y, x);
	if (ft_nbr_component(copy, 'C') != 0)
		return (false);
	if (ft_nbr_component(copy, 'E') == 1)
		return (false);
	return (free_map(copy), true);
}
