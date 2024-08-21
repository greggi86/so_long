/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:00:43 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/27 22:18:19 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *data)
{
	if (data->c_count == 0 && (data->map.lines[data->y_player_tile]
			[data->x_player_tile] == 'E'))
	{
		on_destroy(data);
		return (0);
	}
	return (1);
}

void	init_data(t_data *data)
{
	data->is_moving_bool = 0;
	data->p_ani_iterator = 0;
	data->c_ani_iterator = 0;
	data->step_count = 0;
	data->c_count = 0;
	data->on_exit = 0;
	data->i = 0;
	data->direction = 0;
	data->c_ani_status = 0;
	data->x_player_next = 0;
	data->y_player_next = 0;
}

int	is_loot(t_data *data)
{
	if (data->map.lines[data->y_player_next][data->x_player_next] == 'C')
	{
		data->c_count--;
		return (1);
	}
	return (0);
}

int	is_exit(t_data *data)
{
	if (data->map.lines[data->y_player_next][data->x_player_next] == 'E')
	{
		data->on_exit = 1;
		return (1);
	}
	return (0);
}

int	is_possible(t_data data)
{
	if (!data.map.lines)
		return (1);
	return (data.map.lines[data.y_player_next][data.x_player_next] != '1');
}
