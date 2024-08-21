/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:58:50 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/30 16:00:56 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	create_window(t_data *data, t_map map)
{
	int	width;
	int	height;

	width = data->sprites.width_px * map.amount_width_tiles;
	height = data->sprites.height_px * map.amount_height_tiles ;
	if (map.amount_width_tiles > 78 || map.amount_height_tiles > 41)
	{
		write(1, "Map is bigger than screeen, build a smaller one\n", 49);
		exit(1);
	}
	data->win.width_px = data->map.amount_width_tiles * data->sprites.width_px;
	data->win.height_px = data->map.amount_height_tiles
		* data->sprites.height_px;
	data->gui.img_ptr = mlx_new_image(data->mlx_ptr, width, 50);
	data->win.ptr = mlx_new_window(data->mlx_ptr,
			data->win.width_px, data->win.height_px, "window");
	data->map_img.img_ptr = mlx_new_image(data->mlx_ptr, width, height);
}

void	draw_screen(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->map.amount_height_tiles)
	{
		x = 0;
		while (x < data->map.amount_width_tiles)
		{
			draw_sprite_to_img(data, data->map, x, y);
			x++;
		}
		y++;
	}
}

void	put_tile_to_image(t_info *info, t_img *tile_img)
{
	info->buffer_tile_img = (int *) mlx_get_data_addr(tile_img->img_ptr,
			&tile_img->bpp, &tile_img->line_len, &tile_img->endian);
	info->buffer_map_img = (int *) mlx_get_data_addr(info->map_img->img_ptr,
			&info->map_img->bpp, &info->map_img->line_len,
			&info->map_img->endian);
	tile_img->line_len /= 4;
	info->map_img->line_len /= 4;
	info->y_tile_img = 0;
	while (info->y_tile_img + info->y_pixel < info->y_pixel + info->height)
	{
		info->x_tile_img = 0;
		while (info->x_tile_img + info->x_pixel < info->x_pixel + info->width)
		{
			info->color = info->buffer_tile_img[(info->y_tile_img
					* tile_img->line_len) + info->x_tile_img];
			if (!(info->color & 0xff000000))
				info->buffer_map_img[((info->y_tile_img + info->y_pixel)
						* info->map_img->line_len)
					+ info->x_tile_img + info->x_pixel] = info->color;
			info->x_tile_img++;
		}
		info->y_tile_img++;
	}
}

void	draw_sprite_to_img(t_data *data, t_map map, int x_tile, int y_tile)
{
	t_info	info;

	info.map_img = &data->map_img;
	info.x_pixel = x_tile * data->sprites.width_px;
	info.y_pixel = y_tile * data->sprites.height_px;
	info.height = data->sprites.height_px;
	info.width = data->sprites.width_px;
	if (map.lines[y_tile][x_tile] == '0')
		put_tile_to_image(&info, &data->sprites.ground);
	else if (map.lines[y_tile][x_tile] == '1')
		put_tile_to_image(&info, &data->sprites.wall);
	else if (map.lines[y_tile][x_tile] == 'E')
		put_tile_to_image(&info, &data->sprites.exit);
	else if (map.lines[y_tile][x_tile] == 'P')
		put_tile_to_image(&info, &data->sprites.ground);
	else if (map.lines[y_tile][x_tile] == 'C')
		put_tile_to_image(&info, &data->sprites.collectable);
}

int	next_frame(t_data *data)
{
	draw_screen(data);
	draw_player(data, data->x_player_tile, data->y_player_tile);
	mlx_put_image_to_window(data->mlx_ptr, data->win.ptr,
		data->map_img.img_ptr, 0, 0);
	close_game(data);
	return (0);
}
