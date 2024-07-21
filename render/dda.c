/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:19:40 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/07/21 12:58:31 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/player.h"
#include "../includes/config.h"

/*
** This function calculates the ray direction
*/
void	calc_ray_direction(t_player player, t_raycast *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir.x = player.camera.dir.x + player.camera.plane.x * camera_x;
	ray->ray_dir.y = player.camera.dir.y + player.camera.plane.y * camera_x;
}

/*
** This function calculates the step and initial sideDist
*/
void	calc_ray_step_side_dist(t_player player, t_raycast *ray)
{
	if (ray->ray_dir.x < 0)
		ray->side_dist.x = fract(player.position.x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (1 - fract(player.position.x)) * ray->delta_dist.x;
	if (ray->ray_dir.y < 0)
		ray->side_dist.y = fract(player.position.y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (1 - fract(player.position.y)) * ray->delta_dist.y;
}

/* performs dda algorithm */
void	send_ray(t_map map, t_raycast *ray)
{
	int				limit;

	limit = 1000;
	while (limit--)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->gridcoord.x += copysign(1, ray->ray_dir.x);
			ray->on_horizontal_line = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->gridcoord.y += copysign(1, ray->ray_dir.y);
			ray->on_horizontal_line = 1;
		}
		if (get_map_element(map, ray->gridcoord) == WALL)
			break ;
	}
}

void	calc_wall_dist(t_raycast *ray)
{
	if (ray->on_horizontal_line)
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
	else
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
}
