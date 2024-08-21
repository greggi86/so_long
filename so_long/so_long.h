/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:49:25 by grbuchne          #+#    #+#             */
/*   Updated: 2024/05/30 15:51:43 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

# define FILE_PATH_0 "./sprites/bg.xpm"
# define FILE_PATH_1 "./sprites/hole.xpm"
# define FILE_PATH_E "./sprites/exit.xpm"
# define FILE_PATH_P "./sprites/jump_down_xpm/jump_down_01.xpm"
# define FILE_PATH_C "./sprites/soap.xpm"

# define FILE_PATH_JU01 "./sprites/jump_up_xpm/jump_up_01.xpm"
# define FILE_PATH_JU02 "./sprites/jump_up_xpm/jump_up_02.xpm"
# define FILE_PATH_JU03 "./sprites/jump_up_xpm/jump_up_03.xpm"
# define FILE_PATH_JU04 "./sprites/jump_up_xpm/jump_up_04.xpm"
# define FILE_PATH_JU05 "./sprites/jump_up_xpm/jump_up_05.xpm"
# define FILE_PATH_JU06 "./sprites/jump_up_xpm/jump_up_06.xpm"
# define FILE_PATH_JU07 "./sprites/jump_up_xpm/jump_up_07.xpm"
# define FILE_PATH_JU08 "./sprites/jump_up_xpm/jump_up_08.xpm"
# define FILE_PATH_JU09 "./sprites/jump_up_xpm/jump_up_09.xpm"
# define FILE_PATH_JU10 "./sprites/jump_up_xpm/jump_up_10.xpm"
# define FILE_PATH_JU11 "./sprites/jump_up_xpm/jump_up_11.xpm"
# define FILE_PATH_JU12 "./sprites/jump_up_xpm/jump_up_12.xpm"

# define FILE_PATH_JD01 "./sprites/jump_down_xpm/jump_down_01.xpm"
# define FILE_PATH_JD02 "./sprites/jump_down_xpm/jump_down_02.xpm"
# define FILE_PATH_JD03 "./sprites/jump_down_xpm/jump_down_03.xpm"
# define FILE_PATH_JD04 "./sprites/jump_down_xpm/jump_down_04.xpm"
# define FILE_PATH_JD05 "./sprites/jump_down_xpm/jump_down_05.xpm"
# define FILE_PATH_JD06 "./sprites/jump_down_xpm/jump_down_06.xpm"
# define FILE_PATH_JD07 "./sprites/jump_down_xpm/jump_down_07.xpm"
# define FILE_PATH_JD08 "./sprites/jump_down_xpm/jump_down_08.xpm"
# define FILE_PATH_JD09 "./sprites/jump_down_xpm/jump_down_09.xpm"
# define FILE_PATH_JD10 "./sprites/jump_down_xpm/jump_down_10.xpm"
# define FILE_PATH_JD11 "./sprites/jump_down_xpm/jump_down_11.xpm"
# define FILE_PATH_JD12 "./sprites/jump_down_xpm/jump_down_12.xpm"

# define FILE_PATH_JR01 "./sprites/jump_right_xpm/jump_right_01.xpm"
# define FILE_PATH_JR02 "./sprites/jump_right_xpm/jump_right_02.xpm"
# define FILE_PATH_JR03 "./sprites/jump_right_xpm/jump_right_03.xpm"
# define FILE_PATH_JR04 "./sprites/jump_right_xpm/jump_right_04.xpm"
# define FILE_PATH_JR05 "./sprites/jump_right_xpm/jump_right_05.xpm"
# define FILE_PATH_JR06 "./sprites/jump_right_xpm/jump_right_06.xpm"
# define FILE_PATH_JR07 "./sprites/jump_right_xpm/jump_right_07.xpm"
# define FILE_PATH_JR08 "./sprites/jump_right_xpm/jump_right_08.xpm"
# define FILE_PATH_JR09 "./sprites/jump_right_xpm/jump_right_09.xpm"
# define FILE_PATH_JR10 "./sprites/jump_right_xpm/jump_right_10.xpm"
# define FILE_PATH_JR11 "./sprites/jump_right_xpm/jump_right_11.xpm"
# define FILE_PATH_JR12 "./sprites/jump_right_xpm/jump_right_12.xpm"

# define FILE_PATH_JL01 "./sprites/jump_left_xpm/jump_left_01.xpm"
# define FILE_PATH_JL02 "./sprites/jump_left_xpm/jump_left_02.xpm"
# define FILE_PATH_JL03 "./sprites/jump_left_xpm/jump_left_03.xpm"
# define FILE_PATH_JL04 "./sprites/jump_left_xpm/jump_left_04.xpm"
# define FILE_PATH_JL05 "./sprites/jump_left_xpm/jump_left_05.xpm"
# define FILE_PATH_JL06 "./sprites/jump_left_xpm/jump_left_06.xpm"
# define FILE_PATH_JL07 "./sprites/jump_left_xpm/jump_left_07.xpm"
# define FILE_PATH_JL08 "./sprites/jump_left_xpm/jump_left_08.xpm"
# define FILE_PATH_JL09 "./sprites/jump_left_xpm/jump_left_09.xpm"
# define FILE_PATH_JL10 "./sprites/jump_left_xpm/jump_left_10.xpm"
# define FILE_PATH_JL11 "./sprites/jump_left_xpm/jump_left_11.xpm"
# define FILE_PATH_JL12 "./sprites/jump_left_xpm/jump_left_12.xpm"

# define FILE_PATH_L_0 "./sprites/letter_xpm/0.xpm"
# define FILE_PATH_L_1 "./sprites/letter_xpm/1.xpm"
# define FILE_PATH_L_2 "./sprites/letter_xpm/2.xpm"
# define FILE_PATH_L_3 "./sprites/letter_xpm/3.xpm"
# define FILE_PATH_L_4 "./sprites/letter_xpm/4.xpm"
# define FILE_PATH_L_5 "./sprites/letter_xpm/5.xpm"
# define FILE_PATH_L_6 "./sprites/letter_xpm/6.xpm"
# define FILE_PATH_L_7 "./sprites/letter_xpm/7.xpm"
# define FILE_PATH_L_8 "./sprites/letter_xpm/8.xpm"
# define FILE_PATH_L_9 "./sprites/letter_xpm/9.xpm"
# define FILE_PATH_L_S "./sprites/letter_xpm/S.xpm"
# define FILE_PATH_L_O "./sprites/letter_xpm/O.xpm"
# define FILE_PATH_L_A "./sprites/letter_xpm/A.xpm"
# define FILE_PATH_L_P "./sprites/letter_xpm/P.xpm"
# define FILE_PATH_L_T "./sprites/letter_xpm/T.xpm"
# define FILE_PATH_L_E "./sprites/letter_xpm/E.xpm"

# define TOO_MANY_PLAYERS "too many players, only one is allowed\n"
# define TOO_MANY_EXITS "too many exits, only one is allowed\n"

typedef struct s_map
{
	char	**lines;
	int		amount_width_tiles;
	int		amount_height_tiles;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_sprites
{
	t_img	ground;
	t_img	wall;
	t_img	exit;
	t_img	player;
	t_img	collectable;
	int		width_px;
	int		height_px;
}	t_sprites;

typedef struct s_animation
{
	t_img	sprite;
	int		width;
	int		height;
}	t_animation;

typedef struct s_win
{
	void	*ptr;
	int		height_px;
	int		width_px;
}	t_win;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*img_ptr;
	t_img		map_img;
	t_map		map;
	t_img		gui;
	t_img		letter;
	t_win		win;
	t_sprites	sprites;
	t_animation	p_animation;
	int			is_moving_bool;
	int			p_ani_iterator;
	t_animation	c_animation;
	int			c_ani_iterator;
	int			step_count;
	int			x_player_tile;
	int			y_player_tile;
	int			x_pixel;
	int			y_pixel;
	int			c_count;
	int			x_player_next;
	int			y_player_next;
	int			on_exit;
	int			**touch_mask;
	int			i;
	t_img		animation_sprite;
	int			direction;
	int			*buffer_tile;
	int			*buffer_map;
	int			c_ani_status;
}	t_data;

typedef struct s_info
{
	t_img	*map_img;
	int		x_pixel;
	int		y_pixel;
	int		width;
	int		height;
	int		*buffer_tile_img;
	int		*buffer_map_img;
	int		color;
	int		y_tile_img;
	int		x_tile_img;
}	t_info;

//load_map.c
t_map	load_map(char *file_path);
t_list	*create_map_list(char *file_path);
char	**convert_list_to_array(t_list *map, int y_dim);
t_list	*trim_empty_head(t_list *untrimmed_map);

//main.c
void	draw_player(t_data *data, int x_tile, int y_tile);
void	load_static_sprites(t_data *data);
int		count_col(t_data *data);
int		count_steps(t_data *data);

//window_managment
void	create_window(t_data *data, t_map map);
void	draw_screen(t_data *data);
void	draw_sprite_to_img(t_data *data, t_map map, int x_tile, int y_tile);
void	put_tile_to_image(t_info *info, t_img *tile_img);
int		next_frame(t_data *data);

//validate_map.c
int		validate_path(t_data *data);
int		validate_borders(t_data *data);
int		validate_elements(t_data *data, int i, int j);
void	check_map(t_data *data);

//utils1.c
int		on_destroy(t_data *data);
void	touch_mask(t_data *data);
void	toucher(int x, int y, t_data *data);
int		flood_checker(char c);
int		flood(int x, int y, t_data *data);

//utils2.c

int		close_game(t_data *data);
void	init_data(t_data *data);
int		is_loot(t_data *data);
int		is_exit(t_data *data);
int		is_possible(t_data data);

//movement
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
int		handle_key(int key, t_data *data);
void	error_output(char *str);

//validate utils
void	validate_elements2(char **pce, t_data *data, int *i, int *j);
void	too_many_elements(t_data *data, char **pce, int *i, int *j);
int		string_compare(char **pce);
void	declaration(char **pce, int *width, int *height, t_data *data);

#endif