/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:09:07 by vfries            #+#    #+#             */
/*   Updated: 2022/11/08 15:05:48 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			i;
	size_t			total_size;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	else if (SIZE_MAX / count < size)
		return (NULL);
	total_size = count * size;
	result = malloc(total_size);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
		result[i++] = 0;
	return ((void *)result);
}
