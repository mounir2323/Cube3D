/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:51:49 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/20 19:37:21 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	x_wrapper(mlx_texture_t	*texture, t_general *gen, double pos)
{
	return((int)fmodf((pos *
		(texture->width / TILE_SIZE)), texture->width));
}

int	get_x_o(mlx_texture_t	*texture, t_general *gen)
{
	if (gen->ray->flag == 1)
		return (x_wrapper(texture, gen, gen->ray->horiz[X]));
	return (x_wrapper(texture, gen, gen->ray->vect[Y]));
}

int	get_index(t_general *gen, mlx_texture_t	*texture, double y_o)
{
	uint32_t		*arr;

	arr = (uint32_t *)texture->pixels;
	return (arr[(int)y_o * texture->width + get_x_o(texture, gen)]);
}

double	get_y_o(t_general *gen, double factor)
{
	double			y_o;

	y_o = (gen->params.top_pix - (HEIGHT / 2) +
		 (gen->params.wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	return (y_o);
}

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
	get_params(gen, *r);
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
