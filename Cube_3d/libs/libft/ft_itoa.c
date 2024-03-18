/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:02:47 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/01 17:46:03 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_ofnum(int x)
{
	size_t	count;

	count = 0;
	if (x == 0)
		return (1);
	else if (x < 0)
		x = x * -1;
	while (x != 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

static void	fillitoa(char	*dest, int count, long long int n, int limit)
{
	int	i;

	if (n < 0)
	{
		dest[0] = '-';
		n = n * -1;
	}
	i = count;
	while (i > limit)
	{
		dest[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	dest[count] = '\0';
}

char	*ft_itoa(int x)
{
	int				count;
	char			*dest;
	int				limit;
	long long int	n;

	n = x ;
	limit = 0;
	count = nbr_ofnum(n);
	if (n < 0)
	{
		count = count + 1;
		limit++;
	}
	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (!dest)
		return (NULL);
	fillitoa(dest, count, n, limit);
	return (dest);
}
