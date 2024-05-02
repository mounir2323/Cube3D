/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:35:01 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/28 00:57:20 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing_sky_flr(t_general *gen, int ray)
{
	int	i;

	i = gen->params.bottom_p;
	while (i < HEIGHT)
	{
		mlx_put_pixel(gen->mlx->img, ray, i, gen->map->clr_floor);
		i++;
	}
	i = 0;
	while (i < gen->params.top_pix)
	{
		mlx_put_pixel(gen->mlx->img, ray, i, gen->map->clr_ceil);
		i++;
	}
}

void	walls_rend(t_general *gen, int *r)
{
	get_params(gen);
	drawing_walls(gen, *r);
	drawing_sky_flr(gen, *r);
	gen->ray->ray_ngl += (FOV_RAD / WIDTH);
	(*r)++;
}

void	drawing_walls(t_general *gen, int ray)
{
	double			y;
	mlx_texture_t	*tex;
	double			fct;
	double			tmp;

	tmp = gen->params.top_pix - 1;
	tex = get_textures(gen, gen->ray->flag);
	fct = (double)tex->height / gen->params.wall_h;
	y = get_y_o(gen, fct);
	while (++tmp < gen->params.bottom_p)
	{
		mlx_put_pixel(gen->mlx->img, ray, tmp,
			reverse_bytes(get_index(gen, tex, y)));
		y += fct;
	}
}
