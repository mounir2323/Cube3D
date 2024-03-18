/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmaps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:34:37 by mtayebi           #+#    #+#             */
/*   Updated: 2023/07/23 20:17:05 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	ft_check_valid_comp(char **map)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < len)
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
					&& map[i][j] != 'C' && map[i][j] != 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_chek_doublnl(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (j < len)
		{
			if (map[i][j] == '\n' && (map[i + 1][0] == '\n'))
				return (false);
			if (map[i][j] == '\n' && (map[i + 1][0] == 0))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_chek_rectmaps(char **map)
{
	int		i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((ft_strlen(map[i]) != len))
			return (false);
		i++;
	}
	if (i <= 2)
		return (false);
	return (true);
}

bool	ft_validmap(char **map)
{
	if (ft_strlong(map) == 0)
		return (false);
	if (!ft_check_wholframe(map) || !ft_chek_rectmaps(map)
		|| !ft_chek_doublnl(map) || !ft_check_valid_comp(map))
		return (false);
	if (ft_nbr_component(map, 'C') < 1 || ft_nbr_component(map, 'E') != 1
		|| ft_nbr_component(map, 'P') != 1)
		return (false);
	return (true);
}
