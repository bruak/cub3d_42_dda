/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:35 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:26:53 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../minilibx/mlx.h"

t_image	create_img(t_mlx mlx, int height, int width)
{
	t_image	img;

	img.img = mlx_new_image(mlx.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	img.height = height;
	img.width = width;
	return (img);
}

void	set_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = &img->addr[offset];
	*(unsigned int *)dst = color;
}

int	get_pixel(t_image *img, int x, int y)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0x0);
	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = &img->addr[offset];
	return (*(unsigned int *)dst);
}

t_image	load_xpm(void *mlx, char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (!img.img)
		error_exit("Invalid xpm file\n");
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
		error_exit("Invalid xpm file (address)\n");
	return (img);
}

t_texture_data	load_textures(void *mlx, t_map_metadata metadata)
{
	t_texture_data	textures;

	textures.north = load_xpm(mlx, metadata.north_texture_file_name);
	textures.south = load_xpm(mlx, metadata.south_texture_file_name);
	textures.east = load_xpm(mlx, metadata.east_texture_file_name);
	textures.west = load_xpm(mlx, metadata.west_texture_file_name);
	textures.floor_color = metadata.floor_color;
	textures.ceiling_color = metadata.ceiling_color;
	return (textures);
}
