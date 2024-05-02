/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:20:26 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/28 00:29:52 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_png(t_mlx *ml, t_config init)
{
	ml->walls[NO] = mlx_load_png(init.no);
	if (!ml->walls[NO])
		clean_exit(1, "PNG file data wrong! == > NO\n", &init);
	ml->walls[EA] = mlx_load_png(init.ea);
	if (!ml->walls[EA])
		clean_exit(1, "PNG file data wrong! == > EA\n", &init);
	ml->walls[WE] = mlx_load_png(init.we);
	if (!ml->walls[WE])
		clean_exit(1, "PNG file data wrong! == > WE\n", &init);
	ml->walls[SO] = mlx_load_png(init.so);
	if (!ml->walls[SO])
		clean_exit(1, "PNG file data wrong! == > SO\n", &init);
	return (EXIT_SUCCESS);
}

mlx_texture_t	*get_textures(t_general *dt, int flag)
{
	dt->ray->ray_ngl = nrm_ngl(dt->ray->ray_ngl);
	if (flag == 0)
	{
		if (dt->ray->ray_ngl > M_PI_2 && dt->ray->ray_ngl < 3 * M_PI_2)
			return (dt->mlx->walls[EA]);
		else
			return (dt->mlx->walls[WE]);
	}
	else
	{
		if (dt->ray->ray_ngl > 0 && dt->ray->ray_ngl < M_PI)
			return (dt->mlx->walls[SO]);
		else
			return (dt->mlx->walls[NO]);
	}
}
