/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:42:38 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:33:35 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/image.h"
#include "../minilibx/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../includes/graceful_exit.h"
#include <fcntl.h>

int	is_spawn_point_not_set(t_map map)
{
	return (map.spawn_point.x == -1 || map.spawn_point.y == -1);
}

t_map	load_map(t_mlx *mlx, char *filename)
{
	t_map			map;
	t_map_metadata	meta;

	meta = (t_map_metadata){0};
	meta.floor_color = -1;
	meta.ceiling_color = -1;
	map.spawn_point = (t_vector){-1, -1};
	check_map_extension(filename);
	file_context(filename, &meta, 0, load_metadata);
	check_metadata_is_not_set(meta);
	file_context(filename, &map,
		meta.map_content_first_line, load_map_dimensions);
	if (is_map_width_height_zero(map))
		error_exit(EMPTY_MAP);
	file_context(filename, &map, meta.map_content_first_line, load_map_content);
	check_surrounded_by_wall(&map);
	if (is_spawn_point_not_set(map))
		error_exit(NO_SPAWN_POINT);
	mlx->mlx = mlx_init();
	map.texture = load_textures(mlx->mlx, meta);
	return (map);
}

/**
 * Continue from where i am in gnl
 * -1 is for fix get_next_line buffer bug
 * callback function
*/
void	file_context(char *filename, void *arg,
			int first_line, void func(int, void *))
{
	int	fd;
	int	i;

	i = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(OPEN_ERROR);
	while (i < first_line)
	{
		get_next_line(fd);
		i++;
	}
	func(fd, arg);
	get_next_line(-1);
	close(fd);
}

void	check_map_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		error_exit(MAP_EXTENSION_SHORT);
	if (str[len - 1] != 'b'
		|| str[len - 2] != 'u'
		|| str[len - 3] != 'c'
		|| str[len - 4] != '.')
		error_exit(MAP_EXTENSION_IS_NOT_CUB);
}

void	error_exit(const char *msg)
{
	write(2, BOLD_RED, ft_strlen(BOLD_RED));
	write(2, ERROR, 6);
	write(2, msg, ft_strlen(msg));
	write(2, RESET, ft_strlen(RESET));
	safe_exit();
}
