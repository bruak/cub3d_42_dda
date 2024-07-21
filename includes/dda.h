/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:10:14 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:37:05 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "player.h"
# include "vector.h"
# include "map.h"

void	calc_ray_direction(t_player player, t_raycast *ray, int x);
void	calc_ray_step_side_dist(t_player player, t_raycast *ray);
void	send_ray(t_map map, t_raycast *ray);
void	calc_texture(t_player player, t_raycast *ray);
void	calc_wall_dist(t_raycast *ray);
void	draw_line(t_image *img, t_texture_data textures, int x, t_raycast *ray);
void	calc_wall_texture_dimensions(t_texture_data textures, t_raycast *ray);

#endif