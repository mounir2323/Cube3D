/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:39:56 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/01 00:11:57 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// #include <mlx.h>
# include <fcntl.h>
# include <memory.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h> 
# include "MLX42.h"

# define WIDTH 720
# define HEIGHT 720
# define IMG_W 64
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 3 // player speed

typedef struct s_player //the player structure
{
 int  plyr_x; // player x position in pixels
 int  plyr_y; // player y position in pixels
 double init_direction; // player angle
 float fov_rd; // field of view in radians
 int  rot_flag; // rotation flag
 int	l_r; // left right flag
 int  u_d; // up down flag
} t_player;

typedef struct s_rayon //the ray structure
{
 double ray_ngl; // ray angle
 double distance; // distance to the wall
 bool  flag;  // flag for the wall
} t_rayon;

typedef struct s_data //the data structure
{
 char **map2d; // the map
 int  p_x;  // player x position in the map
 int  p_y;  // player y position in the map
 int  w_map;  // map width
 int  h_map;  // map height
} t_data;

typedef struct s_mlx
{
	mlx_image_t	*img;
	mlx_t		*mlx_p;
	t_rayon		*ray;
	t_data		*dt;
	t_player	*ply;
}				t_mlx;


t_data *init_argumet() ;
void start_the_game(t_data *dt);
void hook(t_mlx *mlx, double move_x, double move_y);
void cast_rays(t_mlx *mlx);
void mlx_key(mlx_key_data_t keydata, void *ml) ;
void ft_exit(t_mlx *mlx)  ;





#endif