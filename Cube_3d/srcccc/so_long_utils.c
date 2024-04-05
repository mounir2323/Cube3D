/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:09:26 by mtayebi           #+#    #+#             */
/*   Updated: 2023/08/07 02:21:54 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_nbr_component(char **map, char x)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == x)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**ft_matcpy(char **mat)
{
	int		i;
	char	**dest;

	dest = malloc((ft_strlong(mat) + 1) * (sizeof(char *)));
	if (!dest)
		return (NULL);
	i = 0;
	while (mat[i])
	{
		dest[i] = ft_strdup(mat[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

void	ft_printmap(char	**maps)
{
	int		i;

	i = 0;
	while (maps[i])
	{
		ft_printf("%s\n", maps[i]);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_freestrcuts(t_map	*strct)
{
	if (strct->tex->donuts)
		mlx_delete_image(strct->mlx, strct->tex->donuts);
	if (strct->tex->exit)
		mlx_delete_image(strct->mlx, strct->tex->exit);
	if (strct->tex->homer)
		mlx_delete_image(strct->mlx, strct->tex->homer);
	if (strct->tex->grass)
		mlx_delete_image(strct->mlx, strct->tex->grass);
	if (strct->tex->hall)
		mlx_delete_image(strct->mlx, strct->tex->hall);
	free(strct->tex);
	if (strct->map)
		free_map(strct->map);
	mlx_terminate(strct->mlx);
}
