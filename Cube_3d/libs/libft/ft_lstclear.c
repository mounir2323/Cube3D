/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:40:00 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/08 22:30:22 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tem;

	if (!*lst)
		return ;
	tem = *lst;
	while (*lst)
	{
		tem = tem->next;
		ft_lstdelone(*lst, del);
		*lst = tem;
	}
	*lst = NULL;
}
