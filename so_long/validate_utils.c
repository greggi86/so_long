/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:53:39 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/28 21:09:12 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	string_compare(char **pce)
{
	(*pce)[3] = '\0';
	if (!(ft_strncmp(*pce, "111", 4)))
	{
		free(*pce);
		return (1);
	}
	else
		return (0);
}

void	validate_elements2(char **pce, t_data *data, int *i, int *j)
{
	if (data->map.lines[*i][*j] != 'E' && data->map.lines[*i][*j] != 'P'
	&& data->map.lines[*i][*j] != 'C'
	&& data->map.lines[*i][*j] != '1' &&
	data->map.lines[*i][*j] != '0'
	&& data->map.lines[*i][*j] != '\n'
	&& data->map.lines[*i][*j] != '\0')
	{
		write(1, "invalid element in the map.", 28);
		write(1, "Allowed are: 1, 0, C, P(1x), E(1x)\n", 36);
		exit(1);
	}
	if (data->map.lines[*i][*j] == 'P')
		(*pce)[0] = '1';
	if (data->map.lines[*i][*j] == 'C')
		(*pce)[1] = '1';
	if (data->map.lines[*i][*j] == 'E')
		(*pce)[2] = '1';
}

void	too_many_elements(t_data *data, char **pce, int *i, int *j)
{
	if (data->map.lines[*i][*j] == 'P' && (*pce)[0] == '1')
		error_output(TOO_MANY_PLAYERS);
	if (data->map.lines[*i][*j] == 'E' && (*pce)[2] == '1')
		error_output(TOO_MANY_EXITS);
}

void	declaration(char **pce, int *width, int *height, t_data *data)
{
	*pce = ft_calloc(1, sizeof(char) * 4);
	*width = data->map.amount_width_tiles;
	*height = data->map.amount_height_tiles;
}
