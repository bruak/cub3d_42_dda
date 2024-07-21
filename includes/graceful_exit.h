/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graceful_exit.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:36:16 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:44:32 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRACEFUL_EXIT_H
# define GRACEFUL_EXIT_H

# include "player.h"

t_player	*get_player(void);
void		free_all(t_player *player);
void		safe_exit(void);
void		handle_abort(void);

#endif
