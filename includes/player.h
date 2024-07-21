/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:16:01 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/20 18:48:15 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"
# include "mlx_struct.h"
# include "map.h"

typedef struct s_camera
{
	t_vector	dir;
	t_vector	plane;
}	t_camera;

typedef struct s_pressed_keys	t_pressed_keys;

typedef struct s_player
{
	t_vector		position;
	t_camera		camera;
	t_map			map;
	t_mlx			mlx;
	t_pressed_keys	*keys;
}	t_player;

#endif