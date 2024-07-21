/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:43:00 by hcoskun42         #+#    #+#             */
/*   Updated: 2024/07/20 16:42:27 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../memory-allocator/allocator.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = safe_malloc(sizeof(char) * size);
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, size);
	ft_strlcat(string, s2, size);
	return (string);
}
