/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:55:17 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:25:38 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include "../includes/config.h"
#include "../includes/dda.h"
#include "../includes/image.h"
#include "../includes/mlx_struct.h"
#include "../minilibx/mlx.h"
#include <math.h>

/*
 * calculates wall distance, degrees and decides how the
 * texture should be displayed.
 * 
 * if ray is ended due to limit (instead of hitting a wall)
 * do not render any wall. so ray->line_height is set to 0
 */
void	calculate_line_textures(
	t_player player, t_texture_data textures, t_raycast *ray)
{
	if (get_map_element(player.map, ray->gridcoord) != WALL)
	{
		ray->line_height = 0;
		return ;
	}
	calc_wall_dist(ray);
	calc_wall_texture_dimensions(textures, ray);
	ray->line_height = (int)(SCREEN_HEIGHT / ray->wall_dist);
	calc_texture(player, ray);
}

int	render_map(t_player	player)
{
	int			x;
	t_raycast	ray;
	t_image		frame;

	frame = create_img(player.mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calc_ray_direction(player, &ray, x);
		ray.gridcoord
			= (t_coord){(int)player.position.x, (int)player.position.y};
		ray.delta_dist.x = fabs(1 / ray.ray_dir.x);
		ray.delta_dist.y = fabs(1 / ray.ray_dir.y);
		calc_ray_step_side_dist(player, &ray);
		send_ray(player.map, &ray);
		calculate_line_textures(player, player.map.texture, &ray);
		draw_line(&frame, player.map.texture, x, &ray);
		x++;
	}
	mlx_put_image_to_window(player.mlx.mlx, player.mlx.win, frame.img, 0, 0);
	return (0);
}
