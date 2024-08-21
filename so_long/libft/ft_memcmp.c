/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:05:07 by grbuchne          #+#    #+#             */
/*   Updated: 2023/06/02 19:50:43 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int ft_memcmp(const void *s1, const void *s2, size_t n)
// {
//     size_t i;
//     const unsigned char *u_s1 = (const unsigned char *)s1;
//     const unsigned char *u_s2 = (const unsigned char *)s2;

//     for (i = 0; i < n; i++)
//     {
//         if (u_s1[i] != u_s2[i])
//             return (u_s1[i] - u_s2[i]);
//     }
//     return 0;
// }

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (u_s1[i] != u_s2[i])
			return (u_s1[i] - u_s2[i]);
		i++;
	}
	return (0);
}
