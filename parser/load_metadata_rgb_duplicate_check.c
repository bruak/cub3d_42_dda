/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_metadata_rgb_duplicate_check.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:42 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:31:40 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/image.h"
#include "../memory-allocator/allocator.h"

char	**split_and_trim(char *str, char c)
{
	char	**split;
	char	*temp;
	int		i;

	i = 0;
	split = ft_split(str, c);
	if (split == NULL)
		error_exit(SAFE_MALLOC_ERROR);
	while (split[i] != NULL)
	{
		temp = ft_strtrim(split[i], " ");
		if (split[i] == NULL)
			error_exit(SAFE_MALLOC_ERROR);
		safe_free(split[i]);
		split[i] = temp;
		i++;
	}
	return (split);
}

int	str2rgb(char *str)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;
	int		i;

	i = 0;
	rgb = split_and_trim(str, ',');
	if (rgb == NULL)
		error_exit(SAFE_MALLOC_ERROR);
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
		error_exit(INVALID_RGB);
	r = natural_atoi(rgb[0]);
	g = natural_atoi(rgb[1]);
	b = natural_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_exit(INVALID_RGB);
	while (i < 3)
		safe_free(rgb[i++]);
	safe_free(rgb);
	return (r << 16 | g << 8 | b);
}

void	check_metadata_is_not_set(t_map_metadata meta)
{
	if (meta.floor_color == -1)
		error_exit("Floor color not set\n");
	if (meta.ceiling_color == -1)
		error_exit("Ceiling color not set\n");
	if (meta.north_texture_file_name == NULL)
		error_exit("North texture not set\n");
	if (meta.south_texture_file_name == NULL)
		error_exit("South texture not set\n");
	if (meta.west_texture_file_name == NULL)
		error_exit("West texture not set\n");
	if (meta.east_texture_file_name == NULL)
		error_exit("East texture not set\n");
}
