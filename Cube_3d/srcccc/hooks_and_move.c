/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:22:06 by mtayebi           #+#    #+#             */
/*   Updated: 2023/08/07 04:26:31 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_del_c(t_map *map, int i, int j)
{
	int	k;

	k = 0;
	map->c_nbr--;
	while (k < map->c_fix)
	{
		if (map->tex->donuts->instances[k].x == i
			&& map->tex->donuts->instances[k].y == j)
			map->tex->donuts->instances[k].enabled = 0;
		k++;
	}
	return ;
}

void	ft_moving_c(t_map *map, int i, int j)
{
	int	diff_i;
	int	diff_j;

	diff_i = map->pos_pi - i;
	diff_j = map->pos_pj - j;
	map->map[map->pos_pi][map->pos_pj] = '0';
	map->pos_pi = i;
	map->pos_pj = j;
	map->map[map->pos_pi][map->pos_pj] = 'P';
	if (diff_i != 0)
			map->tex->homer->instances[0].y -= diff_i * 50;
	if (diff_j != 0)
			map->tex->homer->instances[0].x -= diff_j * 50;
}

void	ft_move(t_map *map, int i, int j)
{
	int	diff_i;
	int	diff_j;

	diff_i = map->pos_pi - i;
	diff_j = map->pos_pj - j;
	if ((map->map[i][j] == '0' || map->map[i][j] == 'C')
		|| (map->map[i][j] == 'E' && map->c_nbr != 0))
	{
		map->counter ++;
		if (map->map[i][j] == 'C')
			ft_del_c(map, map->tex->homer->instances[0].x - (diff_j * 50),
				map->tex->homer->instances[0].y - (diff_i * 50));
		ft_moving_c(map, i, j);
	}
	if ((i == map->pos_ei && j == map->pos_ej && map->c_nbr == 0))
		mlx_close_window(map->mlx);
	ft_printf("nbr of move = %i\n", map->counter);
}

void	ft_hook(mlx_key_data_t data, void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if ((data.key == MLX_KEY_UP && data.action == MLX_PRESS)
		|| (data.key == MLX_KEY_W && data.action == MLX_PRESS))
		ft_move(map, map->pos_pi - 1, map->pos_pj);
	if ((data.key == MLX_KEY_DOWN && data.action == MLX_PRESS)
		|| (data.key == MLX_KEY_S && data.action == MLX_PRESS))
		ft_move(map, map->pos_pi + 1, map->pos_pj);
	if ((data.key == MLX_KEY_RIGHT && data.action == MLX_PRESS)
		|| (data.key == MLX_KEY_D && data.action == MLX_PRESS))
		ft_move(map, map->pos_pi, map->pos_pj + 1);
	if ((data.key == MLX_KEY_LEFT && data.action == MLX_PRESS)
		|| (data.key == MLX_KEY_A && data.action == MLX_PRESS))
		ft_move(map, map->pos_pi, map->pos_pj - 1);
}
