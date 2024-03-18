/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:49:51 by mtayebi           #+#    #+#             */
/*   Updated: 2023/04/09 01:00:26 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*tem;
	t_list	*new_lst;

	new_lst = NULL;
	if (!lst || ! f || !del)
		return (NULL);
	tem = lst;
	while (tem)
	{
		new_node = malloc (sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			free(new_node);
			return (NULL);
		}
		new_node->content = (*f)(tem->content);
		new_node->next = NULL;
		ft_lstadd_back(&new_lst, new_node);
		tem = tem->next;
	}
	free(tem);
	return (new_lst);
}
