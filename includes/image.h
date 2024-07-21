/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:16:52 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/20 18:42:49 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "mlx_struct.h"
# include "parser.h"

t_image			create_img(t_mlx mlx, int height, int width);
void			set_pixel(t_image *img, int x, int y, int color);
int				get_pixel(t_image *img, int x, int y);
t_image			load_xpm(void *mlx, char *path);

t_texture_data	load_textures(void *mlx, t_map_metadata metadata);

#endif