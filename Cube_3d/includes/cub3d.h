/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:39:56 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/05 02:02:58 by mtayebi          ###   ########.fr       */
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
# include "libft.h"

# define WIDTH 720
# define HEIGHT 720
# define IMG_W 64
# define TILE_SIZE 40 // tile size
# define FOV_RAD 80 * (M_PI/180) // field of view in rad
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 3 // player speed

typedef struct s_player //the player structure
{
	int		plyr_x;
	int		plyr_y;
	double	init_direction;
	int		rot_flag;
	int		l_r;
	int		u_d;
}					t_player;

typedef struct s_rayon //the ray structure
{
	double	ray_ngl; // ray angle
	double	distance; // distance to the wall
	bool	flag;  // flag for the wall
}					t_rayon;

typedef struct map //the data structure
{
	char	**map;
	int		p_x;
	int		p_y;
	int		map_width;
	int		map_height;
	mlx_texture_t	*wall[4];
	mlx_image_t		*img;

}		t_map;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	t_rayon			*ray;
	t_map			*map;
	t_player		*ply;
}				t_mlx;






// t_data *init_argumet() ;
void start_the_game(t_map *dt);
void hook(t_mlx *mlx, double move_x, double move_y);
void cast_rays(t_mlx *mlx);
void mlx_key(mlx_key_data_t keydata, void *ml) ;
void game_loop(void *ml) ;
void ft_exit(t_mlx *mlx)  ;
void init_the_player(t_mlx mlx) ;// init the player structure
char	**ft_splitmaps(int fd);



#endif