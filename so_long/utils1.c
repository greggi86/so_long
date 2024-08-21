/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:55:21 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/27 19:57:01 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx_ptr, data->win.ptr);
	mlx_destroy_display(data->mlx_ptr);
	while (i < data->map.amount_height_tiles)
	{
		free(data->touch_mask[i]);
		i++;
	}
	free(data->touch_mask);
	i = 0;
	while (i < data->map.amount_height_tiles)
	{
		free(data->map.lines[i]);
		i++;
	}
	free(data->map.lines);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	touch_mask(t_data *data)
{
	int	i;

	data->touch_mask = calloc(1, sizeof(int *) * data->map.amount_height_tiles);
	i = 0;
	while (i < data->map.amount_height_tiles)
	{
		data->touch_mask[i] = calloc(1,
				sizeof(int) * data->map.amount_width_tiles);
		i++;
	}
}

void	toucher(int x, int y, t_data *data)
{
	data->touch_mask[y][x] = 1;
}

int	flood_checker(char c)
{
	if (c == '1')
		return (0);
	return (1);
}

int	flood(int x, int y, t_data *data)
{
	if ((data->touch_mask[y][x] != 1) && (flood_checker(data->map.lines[y][x])))
	{
		if ((data->map.lines[y][x] == 'C') || (data->map.lines[y][x] == 'E'))
			data->i++;
		toucher(x, y, data);
		flood(x + 1, y, data);
		flood(x - 1, y, data);
		flood(x, y + 1, data);
		flood(x, y - 1, data);
	}
	if (data->i == data->c_count + 1)
		return (1);
	return (0);
}
