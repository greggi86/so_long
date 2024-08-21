/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:26:24 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/29 21:31:27 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_col(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map.amount_height_tiles)
	{
		x = 0;
		while (x < data->map.amount_width_tiles)
		{
			if (data->map.lines[y][x] == 'C')
			{
				data->c_count++;
			}
			else if (data->map.lines[y][x] == 'P')
			{
				data->x_player_tile = x;
				data->y_player_tile = y;
			}
			x++;
		}
		y++;
	}
	return (data->c_count);
}

void	load_static_sprites(t_data *data)
{
	data->sprites.ground.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			FILE_PATH_0, &(data->sprites.width_px), &(data->sprites.height_px));
	data->sprites.wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			FILE_PATH_1, &(data->sprites.width_px), &(data->sprites.height_px));
	data->sprites.exit.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			FILE_PATH_E, &(data->sprites.width_px), &(data->sprites.height_px));
	data->sprites.player.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			FILE_PATH_P, &(data->sprites.width_px), &(data->sprites.height_px));
	data->sprites.collectable.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			FILE_PATH_C, &(data->sprites.width_px), &(data->sprites.height_px));
}

void	draw_player(t_data *data, int x_tile, int y_tile)
{
	t_info	info;

	info.x_pixel = x_tile * data->sprites.width_px;
	info.y_pixel = y_tile * data->sprites.height_px;
	info.height = data->sprites.height_px;
	info.width = data->sprites.width_px;
	info.map_img = &data->map_img;
	put_tile_to_image(&info, &data->sprites.player);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (ac != 2)
	{
		write(1, "No valid map\n", 14);
		exit(1);
	}
	data.map = load_map(av[1]);
	data.mlx_ptr = mlx_init();
	data.c_count = count_col(&data);
	load_static_sprites(&data);
	check_map(&data);
	create_window(&data, data.map);
	mlx_key_hook(data.win.ptr, handle_key, &data);
	mlx_hook(data.win.ptr, DestroyNotify, 0, &on_destroy, &data);
	mlx_loop_hook(data.mlx_ptr, next_frame, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
