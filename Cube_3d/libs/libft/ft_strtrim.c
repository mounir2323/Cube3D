/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:03:56 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/10 18:58:37 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char *set)
{
	int	itr;

	itr = 0;
	while (set[itr] != '\0')
	{
		if (c == set[itr])
			return (1);
		itr++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;

	head = 0;
	tail = 0;
	while (s1[head] != '\0')
	{
		if (ft_inset(s1[head], (char *)set) != 1)
			break ;
		head++;
	}
	while (tail < ft_strlen(s1))
	{
		if (ft_inset(s1[ft_strlen(s1) - 1 - tail], (char *)set) != 1)
			break ;
		tail++;
	}
	return (ft_substr(s1, head, (ft_strlen(s1) - head - tail)));
}
