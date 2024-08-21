/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:22:17 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/30 16:08:26 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	len is the compare area
	
	len - needle_lenght = last point of comparable area where it wont exceed
	haystack according to trustable len variable
	
	iterator <= haystack_length - not to overstep after \0
	needle as null segfaults as it should
	return ((char *)&(haystack[iterator]));-alternative version of line 40
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_length;
	size_t	needle_length;
	size_t	iterator;

	iterator = 0;
	haystack_length = ft_strlen(haystack);
	needle_length = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len < needle_length)
		return (NULL);
	while (iterator <= len - needle_length && iterator <= haystack_length)
	{
		if (ft_strncmp(haystack + iterator, needle, needle_length) == 0)
			return ((char *)(haystack + iterator));
		iterator++;
	}
	return (NULL);
}
