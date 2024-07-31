/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:40:48 by hamza             #+#    #+#             */
/*   Updated: 2024/07/31 22:10:27 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"
#include "../includes/config.h"
#include "../includes/image.h"
#include <math.h>

/* returns fractional part of x */
double	fract(double x)
{
	return (fabs(x - floor(x)));
}


static int	get_texture_color(t_texture_data textures, t_raycast *ray)
{
	t_image	texture;

	if (ray->on_horizontal_line && ray->ray_dir.y < 0)
		texture = textures.north;
	else if (ray->on_horizontal_line && ray->ray_dir.y >= 0)
		texture = textures.south;
	else if (!ray->on_horizontal_line && ray->ray_dir.x < 0)
		texture = textures.west;
	else if (!ray->on_horizontal_line && ray->ray_dir.x >= 0)
		texture = textures.east;
	return (get_pixel(&texture, ray->texture.x, ray->texture.y));
}
void	draw_line(t_image *img, t_texture_data textures, int x, t_raycast *ray)
{
	int		y;
	int		color;
	double	draw_start;
	double	draw_end;

	draw_start = fmax(0, (SCREEN_HEIGHT - ray->line_height) / 2);
	draw_end = fmin(SCREEN_HEIGHT, (ray->line_height + SCREEN_HEIGHT) / 2);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < draw_start)
			set_pixel(img, x, y, textures.ceiling_color);
		else if (y >= draw_end)
			set_pixel(img, x, y, textures.floor_color);
		else
		{
			ray->texture.y = (int)ray->texture.pos;
			ray->texture.pos += ray->step;
			color = get_texture_color(textures, ray);
			set_pixel(img, x, y, color);
		}
		y++;
	}
}

void	calc_wall_texture_dimensions(t_texture_data textures, t_raycast *ray)
{
	t_image	wall_img;

	if (ray->on_horizontal_line)
	{
		if (ray->ray_dir.y < 0)
			wall_img = textures.north;
		else
			wall_img = textures.south;
	}
	else
	{
		if (ray->ray_dir.x < 0)
			wall_img = textures.west;
		else
			wall_img = textures.east;
	}
	ray->current_texture.width = wall_img.width;
	ray->current_texture.height = wall_img.height;
}
