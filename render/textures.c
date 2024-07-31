#include "../includes/config.h"
#include "../includes/player.h"
#include "../includes/math_extensions.h"

int get_texture_x(t_raycast *ray, t_player player)
{
	double	wall_x;

	if (ray->on_horizontal_line)
		wall_x = fract(player.position.x + ray->wall_dist * ray->ray_dir.x);
	else
		wall_x = fract(player.position.y + ray->wall_dist * ray->ray_dir.y);
	return ((int)(wall_x * (double)ray->current_texture.width));
}

int should_be_mirrored(t_raycast *ray)
{
	return ((!ray->on_horizontal_line && ray->ray_dir.x < 0)
		|| (ray->on_horizontal_line && ray->ray_dir.y > 0));
}

void	calc_texture(t_player player, t_raycast *ray)
{
	ray->texture.x = get_texture_x(ray, player);

	if (should_be_mirrored(ray))
		ray->texture.x = ray->current_texture.width - ray->texture.x - 1;
		
	ray->step = (double) ray->current_texture.height / ray->line_height;
	if (SCREEN_HEIGHT > ray->line_height)
		ray->texture.pos = 0;
	else
		ray->texture.pos = (ray->line_height - SCREEN_HEIGHT) * ray->step / 2;
}