/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:46:51 by grbuchne          #+#    #+#             */
/*   Updated: 2023/05/25 20:10:22 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Return a pointer to the first 
occurrence 
of the character c in the string s.

char *strchr(const char *s, int c); --> the 2nd argument is an int
The strchr() and strrchr() functions return a pointer to the matched character 
or NULL if the character is not found.
The terminating null byte is considered part of the string, so that if
 c is specified as '\0', these functions return a pointer to the terminator.
[there is no defined behaviour if the first argument happens to be NULL]
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
	{
		s++;
	}
	if (*s == (char) c || (char) c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
