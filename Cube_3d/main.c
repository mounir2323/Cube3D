/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:01:44 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/05 02:46:27 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



// t_map	*init_argumet(void)
// {
// 	t_map	*map;

// 	map = malloc (sizeof(t_map));
// 	map->map = malloc(10 * sizeof(char *));
// 	map->map[0] = strdup("1111111111111111111111111");
// 	map->map[1] = strdup("1000000000000000000100001");
// 	map->map[2] = strdup("1001000000000P00000000001");
// 	map->map[3] = strdup("1001000000000000001000001");
// 	map->map[4] = strdup("1001000000000000001000001");
// 	map->map[5] = strdup("1001000000100000001000001");
// 	map->map[6] = strdup("1001000000000000001000001");
// 	map->map[7] = strdup("1001000000001000001000001");
// 	map->map[8] = strdup("1111111111111111111111111");
// 	map->map[9] = NULL;
// 	map->p_y = 3;
// 	map->p_x = 14;
// 	map->map_width = 25;
// 	map->map_height = 9;
// 	map->wall[0] = mlx_load_png("/Users/mtayebi/Desktop/Cub3D_mygit/Cube_3d/texture/1.png");
// 	map->wall[1] = mlx_load_png("/Users/mtayebi/Desktop/Cub3D_mygit/Cube_3d/texture/2.png");
// 	map->wall[2] = mlx_load_png("/Users/mtayebi/Desktop/Cub3D_mygit/Cube_3d/texture/3.png");
// 	map->wall[3] = mlx_load_png("/Users/mtayebi/Desktop/Cub3D_mygit/Cube_3d/texture/4.png");
// 	return (map);
// }


// void	cel_floor(t_map *map)
// {
// 	unsigned int	x;
// 	unsigned int	y;

// 	x = 0;
// 	while (x < map->img->width)
// 	{
// 		y = 0;
// 		while (y < map->img->height / 2)
// 			mlx_put_pixel(map->img, x, y++, 0xFF87CEEB);
// 		while (y < map->img->height - 1)
// 			mlx_put_pixel(map->img, x, y++, 0xFFDCDCDC);
// 		x++;
// 	}
// }


// void	init(t_general *g, t_map *map)
// {
// 	setup(map, g);
// 	g->map = map;
// 	get_player_pos(g, map->map);
// 	g->mlx = NULL;
// 	g->img = NULL;
// 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// 	g->mlx = mlx_init(1920, 1080, "CUB3D", true);
// 	if (!g->mlx)
// 		return ;
// 	g->img = mlx_new_image(g->mlx, 1920, 1080);
// 	if (!g->img)
// 		return ;
// 	mlx_image_to_window(g->mlx, g->img, 0, 0);
// 	cel_floor(g);
// 	all(g, g->map->map);
// 	mlx_key_hook(g->mlx, &my_keyhook, g);
// 	mlx_loop(g->mlx);
// 	mlx_terminate(g->mlx);
// }

// void start_the_game(t_map *map) // start the game
// {
// 	t_mlx	mlx;

// 	mlx.map = map;
// 	mlx.ply = malloc(sizeof(t_player)); // init the player structure i'm using malloc to initialize the variables to zero
// 	mlx.ray = malloc (sizeof(t_rayon)); // init the ray structure
// 	mlx.mlx_p = mlx_init(WIDTH, HEIGHT, "Cub3D", true); // init the mlx pointer and put a window to the screen
// 	init_the_player(mlx); // init the player structure
// 	mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx); // game loop continuously call a specified function to update the game state and render the frames.
// 	mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx); // key press and release
// 	mlx_loop(mlx.mlx_p); // mlx loop
// 	ft_exit(&mlx); // exit the game
// }


void draw_scene(mlx_image_t *mlx_ptr) {
    int y = 0;
    
    // Dessiner le ciel bleu
    while (y < mlx_ptr->height / 2) {
        int x = 0;
        while (x < WIDTH) {
            mlx_put_pixel(mlx_ptr, x, y, 0xFF87CEEB); // Couleur bleu ciel
            x++;
        }
        y++;
    }

    // Dessiner le sol gris clair
    while (y < HEIGHT) {
        int x = 0;
        while (x < WIDTH) {
            mlx_put_pixel(mlx_ptr, x, y, 0xFFDCDCDC); // Couleur gris clair
            x++;
        }
        y++;
    }
}

int main() {
	mlx_t *mlx;
	mlx_image_t *img;
	//  img = NULL;
	mlx = mlx_init(WIDTH,HEIGHT, "start!", true);
	mlx_new_image(mlx, WIDTH, HEIGHT);
    draw_scene(img);
    mlx_loop(mlx);
	return 0;
}
