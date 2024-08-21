/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:05:44 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/30 16:07:55 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*run;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		run = ft_lstlast(*lst);
		if (run)
			(*run).next = new;
	}
}
