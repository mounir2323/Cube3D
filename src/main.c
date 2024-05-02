/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:25:44 by schibane          #+#    #+#             */
/*   Updated: 2024/04/28 00:44:39 by mtayebi          ###   ########.fr       */
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
	conf->dt = NULL;
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

int	main(int argc, char **argv)
{
	t_config	conf;

	if (argc != 2)
		return (printf("this programs needs one argument <path to map.cub>\n"));
	if (!is_cub_ext(argv[1]))
		return (printf("the path of the map must end with .cub extention"));
	conf.fd = open(argv[1], O_RDONLY);
	if (conf.fd < 0)
		return (printf("could not open the file '%s'\n", argv[1]));
	init_conf(&conf);
	parsing(&conf, conf.fd);
	launch_game(conf);
	clean_exit(0, NULL, &conf);
	return (0);
}
