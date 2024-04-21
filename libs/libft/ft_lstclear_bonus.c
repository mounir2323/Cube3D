/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:31:55 by schibane          #+#    #+#             */
/*   Updated: 2023/03/30 22:26:32 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*b;

	p = *lst;
	b = *lst;
	if (*lst)
	{
		while (p)
		{
			p = p->next;
			(*del)(b->content);
			free(b);
			b = p;
		}
	*lst = NULL;
	}
}
