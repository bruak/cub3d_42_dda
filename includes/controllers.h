/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:10:14 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/20 18:41:38 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLERS_H
# define CONTROLLERS_H

# include "player.h"

enum	e_keys
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
};

typedef struct s_pressed_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left_arrow;
	int	right_arrow;
}	t_pressed_keys;

typedef struct s_player	t_player;

int			on_key_press(int keycode, t_player *player);
int			on_key_release(int keycode, t_player *player);
double		move_x(t_player *player, double delta);
double		move_y(t_player *player, double delta);
void		rotate_player(t_player *player, double clock_dir);

#endif 