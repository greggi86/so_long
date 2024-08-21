/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:08:36 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/05/23 21:27:04 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_cleaner(char *rest);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen_gnl(char *s);
char	*ft_searcher(char	*workstr, int fd);
char	*ft_reststr(char *workstr);
void	*ft_calloc(size_t count, size_t size);

#endif