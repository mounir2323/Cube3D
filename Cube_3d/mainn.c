/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:01:44 by mtayebi           #+#    #+#             */
/*   Updated: 2024/04/07 03:30:25 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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


// void draw_scene(mlx_image_t *mlx_ptr, uint32_t cel, uint32_t floor) {
//     int y = -1;
    
//     while (++y < (int)mlx_ptr->height / 2) {
//         int x = 0;
//         while (x < WIDTH) {
//             mlx_put_pixel(mlx_ptr, x, y, cel); 
//             x++;
//         }
//     }

//     while (++y < HEIGHT) {
//         int x = -1;
//         while (++x < WIDTH) {
//             mlx_put_pixel(mlx_ptr, x, y, floor); 
//         }
//     }
// }

#include "cub3d.h"






void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color) // put the pixel
{
 if (x < 0) // check the x position
  return ;
 else if (x >= WIDTH)
  return ;
 if (y < 0) // check the y position
  return ;
 else if (y >= HEIGHT)
  return ;
 mlx_put_pixel(mlx->img, x, y, color); // put the pixel
}

float nor_angle(float angle) // normalize the angle
{
 if (angle < 0)
  angle += (2 * M_PI);
 if (angle > (2 * M_PI))
  angle -= (2 * M_PI);
 return (angle);
}

int get_color(t_mlx *mlx, int flag) // get the color of the wall
{
 mlx->ray->ray_ngl = nor_angle(mlx->ray->ray_ngl); // normalize the angle
 if (flag == 0)
 {
  if (mlx->ray->ray_ngl > M_PI / 2 && mlx->ray->ray_ngl < 3 * (M_PI / 2))
   return (0xB5B5B5FF); // west wall
  else
   return (0xB5B5B5FF); // east wall
 }
 else
 {
  if (mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI)
   return (0xF5F5F5FF); // south wall
  else
   return (0xF5F5F5FF); // north wall
 }
}


void draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
{
 int  i;
//  int  c;

 i = b_pix;
 while (i < HEIGHT)
  my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF); // floor
 i = 0;
 while (i < t_pix)
  my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF); // ceiling
}



void draw_wall(t_mlx *mlx, int ray, int t_pix, int b_pix) // draw the wall
{
 int color;

 color = get_color(mlx, mlx->ray->flag);
 while (t_pix < b_pix)
  my_mlx_pixel_put(mlx, ray, t_pix++, color);
            // mlx_put_pixel(mlx, x, y, color); 
}

void render_wall(t_mlx *mlx, int ray) // render the wall
{
 double wall_h;
 double b_pix;
 double t_pix;

 mlx->ray->distance *= cos(nor_angle(mlx->ray->ray_ngl)); // fix the fisheye
 wall_h = (TILE_SIZE / mlx->ray->distance) * ((WIDTH / 2) / tan(FOV_RAD / 2)); // get the wall height
 b_pix = (HEIGHT / 2) + (wall_h / 2); // get the bottom pixel
 t_pix = (HEIGHT / 2) - (wall_h / 2); // get the top pixel
 if (b_pix > HEIGHT) // check the bottom pixel
  b_pix = HEIGHT;
 if (t_pix < 0) // check the top pixel
  t_pix = 0;
 	draw_wall(mlx, ray, t_pix, b_pix); // draw the wall
	// draw_scene(mlx->img,0x87CEEB, 0x89CFF3FF);
 draw_floor_ceiling(mlx, ray, t_pix, b_pix); // draw the floor and the ceiling
}



// int main() 
// {
// 	t_mlx *test1;

// 	test1 = malloc (sizeof(t_mlx));
// 	test1->ply = malloc(sizeof(t_player));
// 	test1->ray = malloc(sizeof(t_rayon));
// 	test1->ply->plyr_x = test1->dt->p_x * TILE_SIZE + TILE_SIZE / 2; // player x position in pixels in the center of the tile
//  	test1->ply->plyr_y = test1->dt->p_y * TILE_SIZE + TILE_SIZE / 2; // player y position in pixels in the center of the tile
// 	test1->map = init_argumet();
// 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// 	test1->mlx_p = mlx_init(WIDTH, HEIGHT, "HELLOO", true);
// 	if (!test1->mlx_p)
// 		return (printf("errroor\n"));
// 	mlx_image_t* img = mlx_new_image(test1->mlx_p, WIDTH, HEIGHT);
// 	mlx_image_to_window(test1->mlx_p, img, 0, 0);
// 	// draw_wall();
	
// 	render_wall(test1, 1);
// 	mlx_loop(test1->mlx_p);
//     return 0;
// }



#include "cub3d.h"

t_mlx 	*init_mlx(void) {
    t_mlx *mlx = malloc(sizeof(t_mlx));
    if (!mlx)
        return NULL;

    mlx->ply = malloc(sizeof(t_player));
    if (!mlx->ply) {
        free(mlx);
        return NULL;
    }

    mlx->ray = malloc(sizeof(t_rayon));
    if (!mlx->ray) {
        free(mlx->ply);
        free(mlx);
        return NULL;
    }

    mlx->ply->plyr_x = mlx->map->p_x * TILE_SIZE + TILE_SIZE / 2;
    mlx->ply->plyr_y = mlx->map->p_y * TILE_SIZE + TILE_SIZE / 2;

    mlx_set_setting(MLX_STRETCH_IMAGE, true);
    mlx->mlx_p = mlx_init(WIDTH, HEIGHT, "HELLOO", true);
    if (!mlx->mlx_p) {
        free(mlx->ray);
        free(mlx->ply);
        free(mlx);
        return NULL;
    }

    mlx_image_t* img = mlx_new_image(mlx->mlx_p, WIDTH, HEIGHT);
    if (!img) {
        free(mlx->ray);
        free(mlx->ply);
        free(mlx);
        return NULL;
    }

    mlx_image_to_window(mlx->mlx_p, img, 0, 0);
    mlx->img = img;

    return mlx;
}

int main() {
    t_mlx *test1 = init_mlx();
    if (!test1) {
        printf("Error initializing mlx\n");
        return 1;
    }

    render_wall(test1, 1);
    mlx_loop(test1->mlx_p);

    return 0;
}
