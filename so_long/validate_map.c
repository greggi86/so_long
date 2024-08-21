/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:40:43 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/28 21:08:42 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_path(t_data *data)
{
	touch_mask(data);
	if (flood(data->x_player_tile, data->y_player_tile, data))
	{
		return (1);
	}
	return (0);
}

int	validate_borders(t_data *data)
{
	int	h;
	int	w;
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 0;
	w = data->map.amount_width_tiles - 1;
	h = data->map.amount_height_tiles - 1;
	while (i <= w)
	{
		if ((data->map.lines[n][i] != '1') || (data->map.lines[h][i] != '1'))
			return (0);
		i++;
	}
	while (j <= h)
	{
		if ((data->map.lines[j][w] != '1') || (data->map.lines[j][n] != '1'))
			return (0);
		j++;
	}
	return (1);
}

int	validate_elements(t_data *data, int i, int j)
{
	int		w;
	int		h;
	char	*found_pce;

	declaration(&found_pce, &w, &h, data);
	if ((w >= 3 && h >= 5) || (w >= 5 && h >= 3))
	{
		while (i < data->map.amount_height_tiles)
		{
			j = 0;
			while (j < data->map.amount_width_tiles)
			{
				validate_elements2(&found_pce, data, &i, &j);
				j++;
				too_many_elements(data, &found_pce, &i, &j);
			}
			too_many_elements(data, &found_pce, &i, &j);
			i++;
		}
		if (string_compare(&found_pce))
			return (1);
	}
	free(found_pce);
	return (0);
}

void	check_map(t_data *data)
{
	if (!(validate_elements(data, 0, 0)))
	{
		printf("Nicht alle notwendigen Elemente vorhanden!\n");
		exit(1);
	}
	if (!(validate_borders(data)))
	{
		printf("Keine ausreichenden Grenzen vorhanden!\n");
		exit(1);
	}
	if (!(validate_path(data)))
	{
		printf("Alle notwendigen Teile vorhanden, aber kein valider Pfad!\n");
		exit(1);
	}
}

void	error_output(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}
