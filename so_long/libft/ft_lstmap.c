/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:06:30 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/30 16:06:34 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node_f;

	if (!lst || !f)
		return (NULL);
	node_f = ft_lstnew(f(lst->content));
	if (node_f == NULL)
	{
		ft_lstclear(&lst, del);
	}
	if (lst->next)
	{
		node_f->next = ft_lstmap(lst->next, f, del);
	}
	return (node_f);
}
