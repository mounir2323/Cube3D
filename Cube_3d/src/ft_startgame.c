/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startgame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:53:12 by mtayebi           #+#    #+#             */
/*   Updated: 2023/08/07 02:26:53 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*ft_put_imgs(mlx_t *mlx, char *path)
{
	xpm_t			*xpm;
	mlx_image_t		*img;
	int				fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	xpm = mlx_load_xpm42(path);
	if (!xpm)
		return (NULL);
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		return (0);
	mlx_delete_xpm42(xpm);
	return (img);
}

void	ft_imgs(t_map *tex)
{
	tex->tex->grass = ft_put_imgs(tex->mlx, "assets/grass.xpm42" );
	tex->tex->exit = ft_put_imgs(tex->mlx, "assets/home_1.xpm42" );
	tex->tex->homer = ft_put_imgs(tex->mlx, "assets/homer_1.xpm42" );
	tex->tex->hall = ft_put_imgs(tex->mlx, "assets/buisson.xpm42" );
	tex->tex->donuts = ft_put_imgs(tex->mlx, "assets/donuts.xpm42" );
}

void	ft_add_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
				mlx_image_to_window(map->mlx, map->tex->homer,
					j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_create_map(t_map	*map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			mlx_image_to_window(map->mlx, map->tex->grass, j * 50, i * 50);
			if (map->map[i][j] == '1')
				mlx_image_to_window(map->mlx, map->tex->hall,
					j * 50, i * 50);
			else if (map->map[i][j] == 'E')
				mlx_image_to_window(map->mlx,
					map->tex->exit, j * 50, i * 50);
			else if (map->map[i][j] == 'C')
			{
				mlx_image_to_window(map->mlx, map->tex->donuts,
					j * 50, i * 50);
			}
			j++;
		}
	}
	ft_add_player(map);
}

t_map	*ft_initmap(int fd)
{
	t_map	*initmap;

	initmap = malloc(sizeof(t_map));
	initmap->map = ft_splitmaps(fd);
	if (!initmap->map)
		return (free(initmap), NULL);
	initmap->map_width = ft_strlen(initmap->map[0]);
	initmap->map_height = ft_strlong(initmap->map);
	initmap->c_nbr = ft_nbr_component(initmap->map, 'C');
	ft_chek_p_e(initmap);
	initmap->c_fix = initmap->c_nbr;
	initmap->counter = 0;
	return (initmap);
}
