/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:52:43 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/28 19:29:53 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data)
{
	data->direction = 4;
	data->x_player_next = data->x_player_tile - 1;
	data->y_player_next = data->y_player_tile;
}

void	move_right(t_data *data)
{
	data->direction = 2;
	data->x_player_next = data->x_player_tile + 1;
	data->y_player_next = data->y_player_tile;
}

void	move_up(t_data *data)
{
	data->direction = 1;
	data->x_player_next = data->x_player_tile;
	data->y_player_next = data->y_player_tile - 1;
}

void	move_down(t_data *data)
{
	data->direction = 3;
	data->x_player_next = data->x_player_tile;
	data->y_player_next = data->y_player_tile + 1;
}

int	handle_key(int key, t_data *data)
{
	if (key == XK_Escape)
		on_destroy(data);
	if (key == XK_Left)
		move_left(data);
	else if (key == XK_Right)
		move_right(data);
	else if (key == XK_Up)
		move_up(data);
	else if (key == XK_Down)
		move_down(data);
	if (is_possible(*data))
	{
		data->step_count++;
		write(1, "steps:", 7);
		ft_putnbr_fd(data->step_count, 1);
		write(1, "\n", 1);
		is_loot(data);
		is_exit(data);
		data->x_player_tile = data->x_player_next;
		data->y_player_tile = data->y_player_next;
		if (data->map.lines[data->y_player_tile][data->x_player_tile] == 'C')
			data->map.lines[data->y_player_tile][data->x_player_tile] = '0';
	}
	return (0);
}
