/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:16:48 by schibane          #+#    #+#             */
/*   Updated: 2024/04/26 22:34:36 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab_str(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i ++;
		}
		free(tab);
	}
}

void	clean_textures_path(t_config *config)
{
	if (config->no)
		free(config->no);
	if (config->we)
		free(config->we);
	if (config->ea)
		free(config->ea);
	if (config->so)
		free(config->so);
}

void	clean_general(t_general *dt)
{
	int	i;

	i = -1;
	if (dt)
	{
		if (dt->ray)
			free(dt->ray);
		if (dt->ply)
			free(dt->ply);
		if (dt->map)
			free(dt->map);
		if (dt->mlx)
		{
			if (dt->mlx->img)
				mlx_delete_image(dt->mlx->mlx_p, dt->mlx->img);
			while (++ i < 4)
			{
				if (dt->mlx->walls[i])
					mlx_delete_texture(dt->mlx->walls[i]);
			}
		}
		mlx_terminate(dt->mlx->mlx_p);
		free(dt);
	}
}

void	clean_exit(int status, char *msg, t_config *config)
{
	if (msg)
		printf("%s", msg);
	clean_textures_path(config);
	ft_lstclear(&config->map_lst, free);
	clean_general(config->dt);
	close (config->fd);
	exit(status);
}
