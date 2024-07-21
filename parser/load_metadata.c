/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_metadata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:46:16 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:30:04 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/map.h"
#include "../get_next_line/get_next_line.h"
#include "../includes/image.h"
#include "../memory-allocator/allocator.h"

/**
 * Load metadata from the file
 * if the line is a map line return
*/
void	load_metadata(int fd, void *arg)
{
	char			*line;
	int				line_count;
	t_map_metadata	*meta;

	line_count = 1;
	meta = (t_map_metadata *)arg;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_a_map_line(line))
		{
			meta->map_content_first_line = line_count;
			safe_free(line);
			return ;
		}
		load_metadata_from_line(meta, ft_strtrim(line, " "));
		safe_free(line);
		line_count++;
	}
}

/**
 * check the line is a map line
 * if it is a map line return 1
*/
int	is_a_map_line(char *line)
{
	int	element_found;

	element_found = 0;
	while (*line && *line != '\n')
	{
		if (*line != ' ' && *line != '1' && *line != '0' && *line != 'N'
			&& *line != 'S' && *line != 'W' && *line != 'E')
			return (0);
		if (*line != ' ')
			element_found = 1;
		line++;
	}
	return (element_found);
}

/**
* pass the space and get key and value
*/
void	load_metadata_from_line(t_map_metadata *metadata, char *line)
{
	int		id_length;
	char	*value;
	char	*key;

	if (line[0] != '\n' && line[0] != '\0')
	{
		id_length = 0;
		while (line[id_length] != '\0'
			&& line[id_length] != '\n' && line[id_length] != ' ')
			id_length++;
		if (id_length != 1 && id_length != 2)
			error_exit(LONG_METADATA_KEY);
		value = ft_strtrim(line + id_length, " \n");
		key = ft_substr(line, 0, id_length);
		set_metadata(metadata, key, value);
		safe_free(key);
		safe_free(value);
	}
	safe_free(line);
}

void	safe_set_value(char **ptr, char *value)
{
	if (*ptr != NULL)
		error_exit(DUPLICATE);
	*ptr = ft_strdup(value);
}

void	set_metadata(t_map_metadata *metadata, char *key, char *val)
{
	if (ft_strncmp(key, "NO", 2) == 0)
		safe_set_value(&metadata->north_texture_file_name, val);
	else if (ft_strncmp(key, "SO", 2) == 0)
		safe_set_value(&metadata->south_texture_file_name, val);
	else if (ft_strncmp(key, "WE", 2) == 0)
		safe_set_value(&metadata->west_texture_file_name, val);
	else if (ft_strncmp(key, "EA", 2) == 0)
		safe_set_value(&metadata->east_texture_file_name, val);
	else if (ft_strncmp(key, "F", 1) == 0)
	{
		if (metadata->floor_color != -1 || ft_strlen(key) != 1)
			error_exit(DUPLICATE_OR_TOO_LONG);
		metadata->floor_color = str2rgb(val);
	}
	else if (ft_strncmp(key, "C", 1) == 0)
	{
		if (metadata->ceiling_color != -1 || ft_strlen(key) != 1)
			error_exit(DUPLICATE_OR_TOO_LONG);
		metadata->ceiling_color = str2rgb(val);
	}
	else
		error_exit(INVALID_METADATA_ID_LENGTH);
}
