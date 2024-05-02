/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:15:59 by schibane          #+#    #+#             */
/*   Updated: 2024/04/28 00:56:07 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	str_tab_len(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			i ++;
		}
	}
	return (i);
}

char	**list_to_array(t_config *conf)
{
	char	**arr;
	t_list	*tmp;
	int		i;

	tmp = conf->map_lst;
	arr = malloc((ft_lstsize((conf->map_lst)) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (tmp)
	{
		arr[i] = (char *)tmp->content;
		i ++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

t_coor	get_player_pos(char **arr)
{
	t_coor	pos;
	int		i;
	int		j;

	i = 0;
	pos.i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (is_char_player(arr[i][j]))
			{
				pos.i = i;
				pos.j = j;
				pos.dir = arr[i][j];
				return (pos);
			}
			j ++;
		}
		i ++;
	}
	return (pos);
}

void	get_map_normal(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				map[i][j] = '0';
			j ++;
		}
		i ++;
	}
}

void	replace_tab(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i ++;
	}
}
