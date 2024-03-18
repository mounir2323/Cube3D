/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:54:12 by mtayebi           #+#    #+#             */
/*   Updated: 2023/06/17 17:46:06 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int	len;
	int	i;
	int	count;

	count = 0;
	i = 0;
	len = (int)ft_strlen(s);
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static int	lenth_world(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	**spliting(char const	*s, char c, char **dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] != 0)
	{
		if ((s [j] != c && j == 0) || ((s [j] != c) && (s [j - 1] == c)))
		{
			dest[i] = ft_substr(s, j, lenth_world(&s[j], c));
			if (!dest[i])
			{
				while (i -- >= 0)
					free (dest[i]);
				free (dest);
				return (NULL);
			}
			i++;
		}
		j++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		count;
	int		j;

	i = 0;
	j = 0;
	count = count_word((char *)s, c);
	if (!s)
		return (NULL);
	dest = (char **)malloc ((count + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest = spliting(s, c, dest);
	if (!dest)
		return (NULL);
	dest[count] = NULL;
	return (dest);
}
