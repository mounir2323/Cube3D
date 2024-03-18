
#include "cub3d.h"

// static void	error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// mlx_image_t	*ft_put_imgs(mlx_t *mlx, char *path)
// {
// 	xpm_t			*xpm;
// 	mlx_image_t		*img;
// 	int				fd;

// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	close(fd);
// 	xpm = mlx_load_xpm42(path);
// 	if (!xpm)
// 		return (NULL);
// 	img = mlx_texture_to_image(mlx, &xpm->texture);
// 	if (!img)
// 		return (0);
// 	mlx_delete_xpm42(xpm);
// 	return (img);
// }

// void	ft_imgs(t_map *tex)
// {
// 	tex->tex->grass = ft_put_imgs(tex->mlx, "assets/grass.xpm42" );
// 	tex->tex->exit = ft_put_imgs(tex->mlx, "assets/home_1.xpm42" );
// 	tex->tex->homer = ft_put_imgs(tex->mlx, "assets/homer_1.xpm42" );
// 	tex->tex->hall = ft_put_imgs(tex->mlx, "assets/buisson.xpm42" );
// 	tex->tex->donuts = ft_put_imgs(tex->mlx, "assets/donuts.xpm42" );
// }

// void	ft_add_player(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map->map[i])
// 	{
// 		j = 0;
// 		while (map->map[i][j] != '\0')
// 		{
// 			if (map->map[i][j] == 'P')
// 				mlx_image_to_window(map->mlx, map->tex->homer,
// 					j * 50, i * 50);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// bool	ft_chek_dnl(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n' && (str[i + 1] == '\n'))
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

// char	*ft_joinlines(int fd, int nbr_ofread, char *buff, char *line)
// {
// 	line[0] = '\0';
// 	while (nbr_ofread != 0)
// 	{
// 		nbr_ofread = read(fd, buff, 100);
// 		if (nbr_ofread < 0)
// 			return (free(buff), free(line), NULL);
// 		buff[nbr_ofread] = '\0';
// 		line = ft_strjoin(line, buff);
// 	}
// 	return (line);
// }




// char	**ft_splitmaps(int fd)
// {
// 	char	*buff;
// 	int		nbr_ofread;
// 	char	*line;
// 	char	**lines;

// 	if (fd < 0)
// 		return (NULL);
// 	nbr_ofread = 1;
// 	buff = malloc(100);
// 	if (!buff)
// 		return (NULL);
// 	line = malloc(100);
// 	if (!line)
// 		return (free(buff), NULL);
// 	line = ft_joinlines(fd, nbr_ofread, buff, line);
// 	if (!line)
// 		return (NULL);
// 	if (!ft_chek_dnl(line))
// 		return (free(line), NULL);
// 	lines = ft_split(line, '\n');
// 	return (free(buff), free(line), lines);
// }

// void	ft_create_map(t_map	*map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (map->map[++i])
// 	{
// 		j = 0;
// 		while (map->map[i][j] != '\0')
// 		{
// 			mlx_image_to_window(map->mlx, map->tex->grass, j * 50, i * 50);
// 			if (map->map[i][j] == '1')
// 				mlx_image_to_window(map->mlx, map->tex->hall,
// 					j * 50, i * 50);
// 			else if (map->map[i][j] == 'E')
// 				mlx_image_to_window(map->mlx,
// 					map->tex->exit, j * 50, i * 50);
// 			else if (map->map[i][j] == 'C')
// 			{
// 				mlx_image_to_window(map->mlx, map->tex->donuts,
// 					j * 50, i * 50);
// 			}
// 			j++;
// 		}
// 	}
// 	ft_add_player(map);
// }

// t_map	*ft_initmap(int fd)
// {
// 	t_map	*initmap;

// 	initmap = malloc(sizeof(t_map));
// 	initmap->map = ft_splitmaps(fd);
// 	if (!initmap->map)
// 		return (free(initmap), NULL);
// 	initmap->map_width = 50;
// 	initmap->map_height = ft_strlong(initmap->map);
// 	initmap->c_fix = initmap->c_nbr;
// 	initmap->counter = 0;
// 	return (initmap);
// }

// void	test(void)
// {
// 	printf("test");
// }

// void	ft_start(t_map *maps)
// {
// 	maps->tex = malloc(sizeof(t_tex));
// 	ft_imgs(maps);
// 	ft_create_map(maps);
// 	mlx_loop(maps->mlx);
// }

int main() {
    void *mlx_ptr;


    mlx_ptr = mlx_init(WIDTH, HEIGHT,"fenetre", true );
    if (!mlx_ptr)
        return -1;
    mlx_loop(mlx_ptr);

    return 0;
}
