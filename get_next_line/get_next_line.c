/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:41:04 by hcoskun           #+#    #+#             */
/*   Updated: 2024/07/21 12:41:38 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../memory-allocator/allocator.h"

int	h_linelen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	expand_str(char **org, char *append)
{
	char	*result;
	int		len_of_str1;
	int		len_of_str2;

	len_of_str1 = h_strlen(*org);
	len_of_str2 = h_strlen(append);
	result = (char *) safe_malloc(sizeof(char)
			* (len_of_str1 + len_of_str2 + 1));
	if (result)
	{
		h_strlcpy(result, *org, len_of_str1 + 1);
		h_strlcpy(result + len_of_str1, append, len_of_str2 + 1);
	}
	if (*org)
		safe_free(*org);
	*org = result;
}

int	narrow(char *eol, char **str_read)
{
	int		len_left;
	int		line_len;
	char	*line_start;
	char	*temp;

	line_len = h_linelen(*str_read);
	temp = (NULL);
	if (*eol)
	{
		line_start = *str_read + line_len + 1;
		len_left = h_strlen(line_start);
		if (len_left == 0)
			temp = NULL;
		else
		{
			temp = h_strndup(line_start, len_left + 1);
			if (temp == NULL)
				return (0);
		}
	}
	safe_free(*str_read);
	*str_read = temp;
	return (1);
}

char	*read_line(int fd, char *buffer, char **eol, char **str_read)
{
	ssize_t	bytes_read;

	while (1)
	{
		*eol = h_strchr(*str_read, '\n');
		if (*eol)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (abort_pointers(buffer, str_read, NULL));
		buffer[bytes_read] = '\0';
		expand_str(str_read, buffer);
		if (!*str_read)
			return (abort_pointers(buffer, str_read, NULL));
		if (bytes_read != BUFFER_SIZE)
		{
			*eol = *str_read + h_linelen(*str_read);
			break ;
		}
	}
	if (h_strlen(*str_read) == 0 && bytes_read == 0)
		return (abort_pointers(buffer, str_read, NULL));
	return (*str_read);
}

char	*get_next_line(int fd)
{
	static char	*str_read = NULL;
	char		*eol;
	char		*buffer;
	int			line_len;
	char		*line;

	if (fd < 0)
	{
		safe_free(str_read);
		str_read = NULL;
		return (NULL);
	}
	buffer = (char *) safe_malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (!read_line(fd, buffer, &eol, &str_read))
		return (NULL);
	line_len = h_linelen(str_read);
	line = h_strndup(str_read, line_len + 1 + (*eol != 0));
	if (!line)
		return (abort_pointers(buffer, &str_read, NULL));
	if (!narrow(eol, &str_read))
		return (abort_pointers(buffer, &str_read, line));
	safe_free(buffer);
	return (line);
}
