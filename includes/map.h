/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:38:00 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/20 18:43:07 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H 
# define MAP_H

# include "vector.h"

typedef enum e_map_element
{
	EMPTY = 0,
	WALL = 1,
	UNDEFINED = 4
}	t_map_element;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_image;

typedef struct s_texture_data
{
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
	int		floor_color;
	int		ceiling_color;
}	t_texture_data;

typedef struct s_map
{
	t_map_element	**map;
	int				width;
	int				height;
	t_vector		spawn_point;
	t_direction		spawn_direction;
	t_texture_data	texture;
}	t_map;

int				is_in_bounds(t_map map, t_coord coord);
t_map_element	get_map_element(t_map map, t_coord coord);

#endif