/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:45:30 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/09 01:00:15 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tem;

	if (!lst)
		return (NULL);
	tem = lst;
	while (tem->next != NULL)
		tem = tem->next;
	return (tem);
}
