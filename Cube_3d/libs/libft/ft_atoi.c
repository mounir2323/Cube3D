/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:11:56 by mtayebi           #+#    #+#             */
/*   Updated: 2023/03/27 01:10:46 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_spaces(char *c, int y)
{
	y = 0;
	while (c[y] == '\n' || c[y] == '\t' || c[y] == '\v'
		|| c[y] == '\f' || c[y] == '\r' || c[y] == ' ')
	y++;
	return (y);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	int		res;
	char	*strr;

	strr = (char *)str;
	sign = 1;
	res = 0;
	i = 0;
	i = is_spaces (strr, i);
	if (strr[i] == '-' || strr[i] == '+')
	{
		if (strr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(strr[i]))
	{
			res = (res * 10) + (strr[i] - '0');
		i++;
	}
	return (res * sign);
}
