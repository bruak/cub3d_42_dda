/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:08:55 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:43:28 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.h"
#include "../includes/controllers.h"
#include "../includes/render.h"
#include "../includes/graceful_exit.h"
#include <math.h>

double	move_x(t_player *player, double delta)
{
	double			new_x;
	t_coord			target;
	t_map_element	element;

	new_x = player->position.x + delta * MOVEMENT_SPEED;
	target = (t_coord){(int)new_x, (int)player->position.y};
	element = get_map_element(player->map, target);
	if (element != WALL)
		return (new_x);
	return (player->position.x);
}

double	move_y(t_player *player, double delta)
{
	double			new_y;
	t_coord			target;
	t_map_element	element;

	new_y = player->position.y + delta * MOVEMENT_SPEED;
	target = (t_coord){(int)player->position.x, (int) new_y};
	element = get_map_element(player->map, target);
	if (element != WALL)
		return (new_y);
	return (player->position.y);
}

/**
 * clock_dir = player arrow direction left -1, right 1. (- +).
 */
void	rotate_player(t_player *player, double clock_dir)
{
	double		old_dir_x;
	double		old_plane_x;
	double		sinr;
	double		cosr;

	sinr = sin(ROTATION_SPEED * clock_dir);
	cosr = cos(ROTATION_SPEED * clock_dir);
	old_dir_x = player->camera.dir.x;
	player->camera.dir.x
		= player->camera.dir.x * cosr - player->camera.dir.y * sinr;
	player->camera.dir.y
		= old_dir_x * sinr + player->camera.dir.y * cosr;
	old_plane_x = player->camera.plane.x;
	player->camera.plane.x
		= player->camera.plane.x * cosr - player->camera.plane.y * sinr;
	player->camera.plane.y
		= old_plane_x * sinr + player->camera.plane.y * cosr;
}

int	on_key_press(int key, t_player *player)
{
	if (key == ESC)
		safe_exit();
	if (key == A)
		player->keys->a = 1;
	else if (key == D)
		player->keys->d = 1;
	else if (key == W)
		player->keys->w = 1;
	else if (key == S)
		player->keys->s = 1;
	else if (key == LEFT_ARROW)
		player->keys->left_arrow = 1;
	else if (key == RIGHT_ARROW)
		player->keys->right_arrow = 1;
	return (0);
}

int	on_key_release(int key, t_player *player)
{
	if (key == A)
		player->keys->a = 0;
	else if (key == D)
		player->keys->d = 0;
	else if (key == W)
		player->keys->w = 0;
	else if (key == S)
		player->keys->s = 0;
	else if (key == LEFT_ARROW)
		player->keys->left_arrow = 0;
	else if (key == RIGHT_ARROW)
		player->keys->right_arrow = 0;
	return (0);
}
