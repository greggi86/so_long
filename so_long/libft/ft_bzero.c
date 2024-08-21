/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:57:48 by gregor.buch       #+#    #+#             */
/*   Updated: 2023/05/25 18:42:06 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*zero;
// 	size_t			i;

// 	i = 0;
// 	zero = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		zero[i] = 0;
// 		i++;
// 	}
// }

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
