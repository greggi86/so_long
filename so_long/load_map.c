/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:42:51 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/27 22:46:56 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*trim_empty_head(t_list *untrimmed_map)
{
	t_list	*map;

	map = untrimmed_map->next;
	ft_lstdelone(untrimmed_map, free);
	return (map);
}

char	**convert_list_to_array(t_list *map, int y_dim)
{
	char	**map_arr;
	int		i;

	map_arr = malloc(sizeof(char *) * (y_dim + 1));
	i = 0;
	while (i < y_dim)
	{
		map_arr[i++] = (char *) map->content;
		map = map->next;
	}
	map_arr[i] = NULL;
	return (map_arr);
}

t_list	*create_map_list(char *file_path)
{
	t_list	*map;
	t_list	*map_iterator;
	char	*map_line;
	int		fd;

	map = ft_calloc(1, sizeof(t_list));
	map_iterator = map;
	fd = open(file_path, O_RDONLY);
	map_line = get_next_line(fd);
	if (map_line == NULL)
	{
		free(map_line);
		exit(1);
	}
	while (map_line)
	{
		map_iterator->next = ft_lstnew(map_line);
		map_iterator = map_iterator->next;
		map_line = get_next_line(fd);
	}
	free(map_line);
	close(fd);
	map = trim_empty_head(map);
	return (map);
}

t_map	load_map(char *file_path)
{
	t_list	*map_list;
	t_map	map;
	int		len;

	len = ft_strlen(file_path);
	if (file_path[len - 1] != 'r' || file_path[len - 2] != 'e'
		||file_path[len - 3] != 'b' || file_path[len - 4] != '.')
	{
		write(1, "unknown file format", 20);
		exit(1);
	}
	map_list = create_map_list(file_path);
	map.amount_height_tiles = ft_lstsize(map_list);
	map.amount_width_tiles = ft_strlen((char *) map_list->content) - 1;
	map.lines = convert_list_to_array(map_list, map.amount_height_tiles);
	ft_lstclear(&map_list, NULL);
	return (map);
}
