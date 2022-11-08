/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:36:26 by vfries            #+#    #+#             */
/*   Updated: 2022/11/08 18:58:37 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	if (size == 0)
		return (ft_strlen(src));
	src_len = 0;
	while (*src)
	{
		if (src_len < size)
			*dst++ = *src;
		src_len++;
		src++;
	}
	if (src_len >= size)
		*--dst = '\0';
	else
		*dst = '\0';
	return (src_len);
}
