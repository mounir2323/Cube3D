/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:51:49 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/28 00:58:44 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	x_wrapper(mlx_texture_t	*texture, double pos)
{
	return (fmodf((pos *(texture->width
					/ TILE_SIZE)), texture->width));
}

int	get_x_o(mlx_texture_t	*texture, t_general *gen)
{
	if (gen->ray->flag == 1)
		return (x_wrapper(texture, gen->info[X].horiz));
	return (x_wrapper(texture, gen->info[Y].vect));
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

	y_o = (gen->params.top_pix - (HEIGHT / 2)
			+ (gen->params.wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	return (y_o);
}
