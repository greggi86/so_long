/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:38:53 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/05/24 15:11:02 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_new(char *workstr, char *buf)
{
	char	*temp;

	temp = ft_strjoin(workstr, buf);
	free(workstr);
	return (temp);
}

char	*ft_searcher(char	*workstr, int fd)
{
	char	*buf;
	int		rd_func;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!workstr)
		workstr = (char *)ft_calloc(1, sizeof(char));
	if (!buf)
		return (NULL);
	rd_func = 1;
	while (rd_func > 0)
	{
		rd_func = read(fd, buf, BUFFER_SIZE);
		if (rd_func < 0)
		{
			free(workstr);
			free(buf);
			return (NULL);
		}
		buf[rd_func] = 0;
		workstr = make_new(workstr, buf);
		if (ft_strchr_gnl(buf, '\n'))
			break ;
	}
	free(buf);
	return (workstr);
}

char	*ft_cleaner(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (ft_strlen_gnl(rest) == 0)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] && rest[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_reststr(char *workstr)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (workstr[i] != '\n' && workstr[i])
		i++;
	if (!workstr[i])
	{
		free(workstr);
		return (NULL);
	}
	rest = ft_calloc(ft_strlen_gnl(workstr) - i, sizeof(char));
	i++;
	j = 0;
	while (workstr[i])
	{
		rest[j] = workstr[i];
		j++;
		i++;
	}
	rest[j] = '\0';
	free(workstr);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*workstr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	workstr = ft_searcher(workstr, fd);
	if (!workstr)
		return (NULL);
	line = ft_cleaner(workstr);
	workstr = ft_reststr(workstr);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;

// 	fd1 = open("file.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 3)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s\n", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	return (0);
// }
