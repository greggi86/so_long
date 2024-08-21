/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:19:19 by grbuchne          #+#    #+#             */
/*   Updated: 2023/06/02 20:02:56 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total_len;
	size_t	copy_len;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	total_len = dst_len + src_len;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	copy_len = dstsize - dst_len - 1;
	if (src_len < copy_len)
		copy_len = src_len;
	ft_memcpy(dst + dst_len, src, copy_len);
	dst[dst_len + copy_len] = '\0';
	return (total_len);
}
// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	initial_desired_len;

// 	initial_desired_len = ft_strlen(dst) + ft_strlen(src);
// 	if (ft_strlen(dst) >= dstsize)
// 		return (ft_strlen(src) + dstsize);
// 	if (initial_desired_len <= dstsize)
// 	{
// 		ft_memset(dst + ft_strlen(dst) + ft_strlen(src), 0, 1);
// 		ft_memmove(dst + ft_strlen(dst), src, ft_strlen(src) + 1);
// 	}
// 	else
// 	{
// 		ft_memset(dst + ft_strlen(dst), 0, dstsize - ft_strlen(dst));
// 		ft_memmove(dst + ft_strlen(dst), src, dstsize - ft_strlen(dst) - 1);
// 	}
// 	return (initial_desired_len);
// }

// #include "string.h"

// int main()
// {
// 	char buf[13];
// 	char buf_test[13];
// 	char *src = "abcdefghi";
// 	char *dst_content = "pqrs";
// 	ft_memmove(buf, dst_content, ft_strlen(dst_content));
// 	ft_memmove(buf_test, dst_content, ft_strlen(dst_content));
// 	strlcat(buf_test, src, 13);
// 	ft_strlcat(buf, src, 13);
// 	printf("std: %s\n", buf_test);
// 	printf("our: %s\n", buf);
// 	return (0);
// }