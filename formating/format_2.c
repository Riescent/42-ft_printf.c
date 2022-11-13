/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:06:21 by vfries            #+#    #+#             */
/*   Updated: 2022/11/13 22:59:24 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

char	*format_u(char **str_format, va_list *args, int *char_written)
{
	char			buf[11];
	char			*buf_ptr;
	char			is_negative;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	if (n == 0)
		return (ft_strdup("0"));
	buf[11] = '\0';
	buf_ptr = buf + 10;
	while (n > 0)
	{
		*buf_ptr-- = n % 10 + '0';
		n /= 10;
	}
	buf_ptr = ft_strdup(buf_ptr + 1);
	if (buf_ptr != NULL)
		*char_written += ft_strlen(buf_ptr);
	return (buf_ptr);
}

char	*format_percent(const char **str_format)
{
	(*str_format)++;
	return (ft_strdup("%"));
}
