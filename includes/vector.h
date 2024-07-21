/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:37:45 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 11:21:05 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_texture
{
	double	pos;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_texture;

typedef struct s_raycast
{
	t_vector	side_dist;
	t_vector	delta_dist;
	t_vector	ray_dir;
	t_coord		gridcoord;
	double		wall_dist;
	double		step;
	int			on_horizontal_line;
	int			line_height;
	t_texture	texture;
	t_texture	current_texture;
}			t_raycast;

double	fract(double x);

#endif
