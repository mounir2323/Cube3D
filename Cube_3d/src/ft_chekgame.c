/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chekgame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:38:42 by mtayebi           #+#    #+#             */
/*   Updated: 2023/07/22 21:54:20 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_chek_p_e(t_map *maps)
{
	int		i;
	int		j;

	i = 0;
	while (maps->map[i])
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i][j] == 'P')
			{
					maps->pos_pi = i;
					maps->pos_pj = j;
			}
			if (maps->map[i][j] == 'E')
			{
					maps->pos_ei = i;
					maps->pos_ej = j;
			}
			j++;
		}
		i++;
	}
	return ;
}
