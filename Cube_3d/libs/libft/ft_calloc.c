/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:16:18 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/12 00:18:00 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;
	size_t	res;

	res = count * size;
	cal = malloc(res);
	if (cal == 0)
		return (NULL);
	ft_bzero(cal, res);
	return (cal);
}
