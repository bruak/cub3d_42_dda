/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:39:08 by hcoskun           #+#    #+#             */
/*   Updated: 2024/07/21 13:06:41 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/controllers.h"
#include "includes/config.h"
#include "includes/render.h"
#include "includes/parser.h"
#include "minilibx/mlx.h"
#include "includes/graceful_exit.h"
#include <stdlib.h>

int	close_window(void)
{
	safe_exit();
	return (0);
}

int	game_loop(t_player *player)
{
	if (player->keys->a)
	{
		player->position.x = move_x(player, -player->camera.plane.x);
		player->position.y = move_y(player, -player->camera.plane.y);
	}
	if (player->keys->d)
	{
		player->position.x = move_x(player, player->camera.plane.x);
		player->position.y = move_y(player, player->camera.plane.y);
	}
	if (player->keys->w)
	{
		player->position.x = move_x(player, player->camera.dir.x);
		player->position.y = move_y(player, player->camera.dir.y);
	}
	if (player->keys->s)
	{
		player->position.x = move_x(player, -player->camera.dir.x);
		player->position.y = move_y(player, -player->camera.dir.y);
	}
	else if (player->keys->right_arrow)
		rotate_player(player, 1);
	else if (player->keys->left_arrow)
		rotate_player(player, -1);
	return (render_map(*player));
}

void	set_player_camera(t_player *player)
{
	if (player->map.spawn_direction == NORTH)
	{
		player->camera.dir = (t_vector){0, -1};
		player->camera.plane = (t_vector){0.66, 0};
	}
	else if (player->map.spawn_direction == SOUTH)
	{
		player->camera.dir = (t_vector){0, 1};
		player->camera.plane = (t_vector){-0.66, 0};
	}
	else if (player->map.spawn_direction == WEST)
	{
		player->camera.dir = (t_vector){-1, 0};
		player->camera.plane = (t_vector){0, -0.66};
	}
	else if (player->map.spawn_direction == EAST)
	{
		player->camera.dir = (t_vector){1, 0};
		player->camera.plane = (t_vector){0, 0.66};
	}
}

int	main(int ac, char **av)
{
	t_mlx			mlx;
	t_map			map;
	t_pressed_keys	pressed_keys;
	t_player		player;

	if (ac != 2)
		return (error_exit(USAGE_MSG), 1);
	map = load_map(&mlx, av[1]);
	mlx.win = mlx_new_window(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
	pressed_keys = (t_pressed_keys){0};
	player.keys = &pressed_keys;
	player.position = map.spawn_point;
	player.mlx = mlx;
	player.map = map;
	set_player_camera(&player);
	mlx_hook(mlx.win, 2, 0, on_key_press, &player);
	mlx_hook(mlx.win, 3, 0, on_key_release, &player);
	mlx_loop_hook(mlx.mlx, game_loop, &player);
	mlx_hook(mlx.win, 17, 0, close_window, 0);
	mlx_loop(mlx.mlx);
}
