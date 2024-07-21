/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:16:01 by bsoykan           #+#    #+#             */
/*   Updated: 2024/07/21 12:16:33 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "map.h"

# define BOLD_RED "\033[1m\033[31m"
# define RESET "\033[0m"
# define ERROR "Error\n"
# define MAP_EXTENSION_SHORT "Map file extension is too short\n"
# define MAP_EXTENSION_IS_NOT_CUB "Map file extension is not .cub\n"
# define TOO_MANY_ARGS "Too many arguments\n"
# define OPEN_ERROR "Map file does not exist\n"
# define READ_ERROR "Error while reading the map file, could be empty!\n"
# define SAFE_MALLOC_ERROR "Memory allocation error\n"
# define INVALID_CHARACTER "Invalid character in map\n"
# define MISSING_METADATA "Missing metadata\n"
# define EMPTY_MAP "Empty map\n"
# define MAP_NOT_SURROUNDED_BY_WALL "Map is not surrounded by walls\n"
# define INVALID_METADATA_ID_LENGTH "Invalid metadata id length\n"
# define DUPLICATE_OR_TOO_LONG "Duplicate key or ceiling, floor key too long\n"
# define DUPLICATE "Duplicate value\n"
# define INVALID_RGB "Invalid RGB\n"
# define USAGE_MSG "Usage: ./cub3d map.cub\n"
# define LONG_METADATA_KEY "Metadata key is too long\n"
# define MULTIPLE_SPAWN_POINTS "Multiple spawn points\n"
# define NO_SPAWN_POINT "No spawn point\n"

# include "mlx_struct.h"

typedef struct s_map_metadata
{
	char		*north_texture_file_name;
	char		*south_texture_file_name;
	char		*west_texture_file_name;
	char		*east_texture_file_name;
	int			floor_color;
	int			ceiling_color;
	int			map_content_first_line;
}	t_map_metadata;

t_map			load_map(t_mlx *mlx, char *filename);
void			load_metadata(int fd, void *arg);
void			load_map_dimensions(int fd, void *arg);
int				is_map_width_height_zero(t_map map);
void			load_map_content(int fd, void *arg);
void			set_position_and_fill_map(
					t_map *map, char *line, unsigned int x, unsigned int y);
void			error_exit(const char *msg);
t_map_element	char_to_element(char c);
int				is_surrounded_by_defined(t_map *map, int x, int y);
void			check_map_extension(char *str);
void			file_context(char *filename, void *arg,
					int file_line, void func(int, void *));
void			check_metadata_is_not_set(t_map_metadata meta);
void			check_surrounded_by_wall(t_map *map);
int				str2rgb(char *str);
void			load_metadata(int fd, void *arg);
int				is_a_map_line(char *line);
void			load_metadata_from_line(t_map_metadata *metadata, char *line);
void			set_metadata(t_map_metadata *metadata, char *key, char *val);

#endif