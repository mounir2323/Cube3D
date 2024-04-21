/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:16:48 by schibane          #+#    #+#             */
/*   Updated: 2024/04/06 21:28:42 by schibane         ###   ########.fr       */
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

void	clean_exit(int status, char *msg, t_config *config)
{
	if (msg)
		printf("%s", msg);
	if (config->ea)
		free(config->ea);
	exit(status);
}