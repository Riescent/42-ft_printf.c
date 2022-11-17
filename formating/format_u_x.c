/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:06:21 by vfries            #+#    #+#             */
/*   Updated: 2022/11/17 02:16:06 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

char	*format_u(va_list *args)
{
	char			buf[11];
	char			*buf_ptr;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	if (n == 0)
		return (ft_strdup("0"));
	buf[10] = '\0';
	buf_ptr = buf + 9;
	while (n > 0)
	{
		*buf_ptr-- = n % 10 + '0';
		n /= 10;
	}
	return (ft_strdup(buf_ptr + 1));
}

char	*format_x(char *base, va_list *args)
{
	unsigned int	n;
	char			buf[9];
	char			*buf_ptr;

	n = va_arg(*args, unsigned int);
	if (n == 0)
		return (ft_strdup("0"));
	buf[8] = '\0';
	buf_ptr = buf + 7;
	while (n != 0)
	{
		*buf_ptr-- = base[n % 16];
		n /= 16;
	}
	return (ft_strdup(buf_ptr + 1));
}
