/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_dimentions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:45:26 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:34:38 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/map.h"
#include "../get_next_line/get_next_line.h"

void	load_map_dimensions(int fd, void *arg)
{
	unsigned int	line_len;
	int				line_count;
	char			*line;
	t_map			*map;
	size_t			longest_line_length;

	map = (t_map *)arg;
	longest_line_length = 0;
	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_len = ft_strlen(line);
		if (line[line_len - 1] == '\n')
			line_len--;
		if (line_len > longest_line_length)
			longest_line_length = line_len;
		line_count++;
	}
	map->width = (int) longest_line_length;
	map->height = line_count;
}

int	is_map_width_height_zero(t_map map)
{
	return (map.width <= 0 || map.height <= 0);
}
