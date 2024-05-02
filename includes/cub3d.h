/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:26:01 by schibane          #+#    #+#             */
/*   Updated: 2024/04/28 00:53:53 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libs/libft/libft.h"
# include "MLX42.h"

# define BUFFER_SIZE	42
# define X 				0
# define Y 				1

# define RED			0
# define GREEN			1
# define BLUE			2
# define SPEED		 	2
# define ROT_SPEED	  0.04

# define A 		65
# define D 		68
# define S 		83
# define W 		87
# define LEFT	263
# define RIGHT	262

# define WIDTH 1900 
# define HEIGHT 1000 
# define FOV_RAD 1.15
# define TILE_SIZE 20

# define NO 0 
# define EA 1
# define WE 2
# define SO 3 

# define VECT 0
# define HORIZ 1

# define ROT_LEFT 0 
# define ROT_RIGHT 1

typedef struct s_move
{
	int		mv[4];
	int		rot;
}			t_move;

typedef struct s_player
{
	int		pix_x;
	int		pix_y;
	t_move	mv;
	double	init_dir;
}				t_player;

typedef struct s_coor
{
	unsigned int	i;
	unsigned int	j;
	char			dir;
}	t_coor;

typedef struct s_map //the data structure
{
	char		**map_2d;
	int			p_x;
	int			p_y;
	int			map_max_width;
	int			map_max_height;
	uint32_t	clr_floor;
	uint32_t	clr_ceil;
}	t_map;

typedef struct s_info
{
	float	step;
	double	inter;	
}			t_info;

typedef struct s_rayon //the ray structure
{
	double	ray_ngl;
	double	distance;
	bool	flag;
}		t_rayon;

typedef struct s_mlx //the mlx structure
{
	mlx_t			*mlx_p;
	mlx_image_t		*img;
	mlx_texture_t	*walls[4];
}	t_mlx;

typedef struct s_params
{
	double	wall_h;
	double	bottom_p;
	double	top_pix;
}	t_params;

typedef struct s_ray_info
{
	double	horiz;
	double	vect;
	float	step;
}	t_ray_info;

typedef struct s_general
{
	t_rayon		*ray;
	t_player	*ply;
	t_map		*map;
	t_mlx		*mlx;
	t_params	params;
	t_ray_info	info[2];
}				t_general;

typedef struct s_config
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	char		**map;
	t_list		*map_lst;
	t_coor		player_pos;
	int			biggest_mapline;
	t_general	*dt;
	int			fd;
}	t_config;

int				parsing(t_config *conf, int fd);
int				str_tab_len(char **tab);
int				check_map_validity(t_config *conf);
int				is_char_player(char c);
int				load_png(t_mlx *ml, t_config init);
int				reverse_bytes(int c);
int				u_circle(float angle, int axis);
int				get_biggest_line(t_list *map_lst);
int				get_index(t_general *gen, mlx_texture_t	*texture, double y_o);
double			get_y_o(t_general *gen, double factor);
void			clean_exit(int status, char *msg, t_config *config);
void			init_gen(t_general *dt);
void			print_general(const t_general *general);
void			drawing_walls(t_general *gen, int ray);
void			get_params(t_general *gen);
void			keys(mlx_key_data_t keydata, void *param);
void			rotation_hook(t_general *mlx);
void			move_hook(t_general *dt, double move_x, double move_y);
void			get_colors(t_config *conf, int fd);
void			launch_game(t_config cnf);
void			free_tab_str(char **tab);
void			read_map(int fd, t_config *conf);
void			fill_up_spaces(t_config *conf);
void			add_to_maplst(t_config *conf, t_list **map_lst, char *line);
void			get_map_normal(char **map);
void			walls_rend(t_general *gen, int *r);
void			drawing_sky_flr(t_general *gen, int ray);
void			ray_cst(t_general *dt);
void			h_v_update(t_general *gen, double h_inter, double v_inter);
void			read_map(int fd, t_config *conf);
void			add_bottom_border(t_config *conf);
void			add_top_border(t_config *conf);
void			replace_tab(char *str);
char			*get_next_line(int fd);
char			**list_to_array(t_config *conf);
char			*add_side_borders_fill_space(t_config *conf, t_list *current);
float			nrm_ngl(float angle);
t_coor			get_player_pos(char **arr);
t_rayon			*init_ray(t_config cnf);
t_map			*init_map(t_config cnf);
t_player		*init_ply(t_map *map, t_config cnf);
mlx_texture_t	*get_textures(t_general *dt, int flag);
mlx_texture_t	*get_textures(t_general *dt, int flag);



#endif