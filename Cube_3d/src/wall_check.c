/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:27:09 by mtayebi           #+#    #+#             */
/*   Updated: 2023/07/12 15:38:51 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_wall_hor(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_wall_mid(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 1;
	if (str[i] != '1' || str[len] != '1')
		return (0);
	return (1);
}

bool	ft_check_wholframe(char **map)
{
	int	j;
	int	lon;

	j = 1;
	lon = ft_strlong(map) - 1;
	if (ft_wall_hor(map[0]) == 0 || ft_wall_hor(map[lon]) == 0)
		return (false);
	while (j < lon)
	{
		if (ft_wall_mid(map[j]) == 0)
			return (false);
		j++;
	}
	return (true);
}
