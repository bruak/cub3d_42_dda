/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c              		                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:46:16 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/14 18:43:23 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../memory-allocator/allocator.h"

int	is_in_bounds(t_map map, t_coord coord)
{
	return (coord.x >= 0 && coord.x < map.width
		&& coord.y >= 0 && coord.y < map.height);
}

/**
 * Get the element of the map at the given coordinates.
 * the coordinates has padding to allow negative coordinates.
*/
t_map_element	get_map_element(t_map map, t_coord coord)
{
	if (!is_in_bounds(map, coord))
		return (UNDEFINED);
	return (map.map[coord.y][coord.x]);
}

void	set_map_element(t_map map, t_coord coord, t_map_element element)
{
	if (!is_in_bounds(map, coord))
		return ;
	map.map[coord.y][coord.x] = element;
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		safe_free(map.map[i]);
		i++;
	}
	safe_free(map.map);
}
