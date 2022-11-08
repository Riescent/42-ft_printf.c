/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:11:33 by vfries            #+#    #+#             */
/*   Updated: 2022/10/10 21:36:50 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*start_dst;

	start_dst = dst;
	if (dst > src)
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(unsigned char *)dst-- = *(unsigned char *)src--;
	}
	else if (dst < src)
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (start_dst);
}
