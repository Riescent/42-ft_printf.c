/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:49:27 by vfries            #+#    #+#             */
/*   Updated: 2022/11/07 23:08:03 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*original_dst;

	original_dst = dst;
	while (n-- > 0)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (original_dst);
}
