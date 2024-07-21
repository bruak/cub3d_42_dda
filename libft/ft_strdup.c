/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:40:48 by hcoskun42         #+#    #+#             */
/*   Updated: 2024/07/20 16:42:22 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../memory-allocator/allocator.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	size;

	size = ft_strlen(str) + 1;
	res = safe_malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, size);
	return (res);
}
