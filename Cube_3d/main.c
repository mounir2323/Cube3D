/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 01:49:50 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/07 21:41:06 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void init_mlx(t_gen *gen)
{
	    mlx_set_setting(MLX_STRETCH_IMAGE, true);
	gen->mlx = mlx_init(WIDTH, HEIGHT, "CUBE3D", false);
    if (!gen->mlx) {
        free(gen->p);
        free(gen->map);
        free(gen);
    }
	gen->img = mlx_new_image(gen->mlx, WIDTH, HEIGHT);
	  if (!gen->img) {
        free(gen->ray);
        free(gen->p);
        free(gen);
    }
    mlx_image_to_window(gen->mlx, gen->img, 0, 0);
	mlx_loop(gen->mlx);
}


//  mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H); // create new image
int main(void)
{
	t_gen *general;

	general = init_args();
	init_mlx(general);
	
	
	return 0;
}