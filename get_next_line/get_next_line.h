/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:43:01 by hcoskun           #+#    #+#             */
/*   Updated: 2024/07/21 12:41:08 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*h_strndup(char *str, int size);

char	*h_strchr(char *str, char c);

char	*abort_pointers(char *buffer, char **str_read, char *line);

int		h_strlen(const char *str);

void	h_strlcpy(char *dst, char *str, int size);

int		h_linelen(const char *str);

void	expand_str(char **org, char *append);

int		narrow(char *eol, char **str_read);

char	*read_line(int fd, char *buffer, char **eol, char **str_read);

#endif