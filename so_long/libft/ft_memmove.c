/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:52:25 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/30 16:08:54 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	unsigned char	*usgnd_dst;
// 	unsigned char	*usgnd_src;

// 	usgnd_dst = (unsigned char *) dst;
// 	usgnd_src = (unsigned char *) src;
// 	while (len-- > 0 && *(char *)src != '\0')
// 	{
// 		*usgnd_dst = *usgnd_src;
// 	}
// 	return (dst);
// }

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	while (len-- > 0)
// 	{
// 		((char *)dst)[len] = ((char *)src)[len];
// 	}
// 	return (dst);
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	iterator;

	iterator = 0;
	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		while (len-- > 0)
		{
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	else
	{
		while (iterator < len)
		{
			((char *)dst)[iterator] = ((char *)src)[iterator];
			iterator++;
		}
	}
	return (dst);
}

// void	memmove(void *dest, void *src, size_t n)
// {
// 	int
// }