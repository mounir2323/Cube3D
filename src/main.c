/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:25:44 by schibane          #+#    #+#             */
/*   Updated: 2024/04/20 20:31:13 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_conf(t_config *conf)
{

	conf->no = NULL;
	conf->so = NULL;
	conf->we = NULL;
	conf->ea = NULL;
	conf->f[0] = -1;
	conf->f[1] = -1;
	conf->f[1] = -1;
	conf->c[0] = -1;
	conf->c[1] = -1;
	conf->c[2] = -1;
	conf->dt = malloc(sizeof(t_general));
	conf->map = NULL;
}

static int	is_cub_ext(char *path)
{
	int		len;
	char	*ext;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	ext = path + (len - 4);
	if (!ft_strncmp(ext, ".cub", 5))
		return (1);
	return (0);
}

// void print_config(t_config *config)
// {
// 	printf("no: %s\n", config->no);
// 	printf("so: %s\n", config->so);
// 	printf("we: %s\n", config->we);
// 	printf("ea: %s\n", config->ea);
// 	printf("f: [%d, %d, %d]\n", config->f[0], config->f[1], config->f[2]);
// 	printf("c: [%d, %d, %d]\n", config->c[0], config->c[1], config->c[2]);
// 	printf("map:\n");
// 	for (int i = 0; config->map[i]; i++) {
// 		printf("%s\n", config->map[i]);
// 	}
// 	printf("player_pos: i = %u, j = %u, dir = %c\n", config->player_pos.i, config->player_pos.j, config->player_pos.dir);
// 	printf("biggest_mapline: %d\n", config->biggest_mapline);
// }

// void print_general(const t_general *general) {
//     printf("Ray:\n");
//     printf("   Ray Angle: %.2f\n", general->ray->ray_ngl);
//     printf("   Distance to Wall: %.2f\n", general->ray->distance);
//     printf("   Wall Flag: %s\n", general->ray->flag ? "true" : "false");
    
//     printf("Player:\n");
//     printf("   Player X: %d\n", general->ply->plyr_x);
//     printf("   Player Y: %d\n", general->ply->plyr_y);
//     printf("   Angle: %.2f\n", general->ply->angle);
//     printf("   Field of View (Radians): %.2f\n", general->ply->fov_rd);
//     printf("   Rotation Flag: %d\n", general->ply->rot);
//     printf("   Left Right Flag: %d\n", general->ply->l_r);
//     printf("   Up Down Flag: %d\n", general->ply->u_d);
    
//     printf("Map:\n");
//     printf("   Player X Position on Map: %d\n", general->map->p_x);
//     printf("   Player Y Position on Map: %d\n", general->map->p_y);
//     printf("   Map Width: %d\n", general->map->map_max_width);
//     printf("   Map Height: %d\n", general->map->map_max_height);
// }

int	main(int argc, char **argv)
{
	t_config	conf;
	int			fd;

	if (argc != 2)
		return (printf("this programs needs one argument <path to map.cub>\n"));
	if (!is_cub_ext(argv[1]))
		return (printf("the path of the map must end with .cub extention"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("could not open the file '%s'\n", argv[1]));
	init_conf(&conf);
	parsing(&conf, fd);
	launch_game(conf.dt, conf);
	return (0);
}

