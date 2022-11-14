/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:06:21 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 02:25:53 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

char	*format_u(const char **str_format, va_list *args, int *char_written)
{
	char			buf[11];
	char			*buf_ptr;
	unsigned int	n;

	(*str_format)++;
	n = va_arg(*args, unsigned int);
	if (n == 0)
	{
		(*char_written)++;
		return (ft_strdup("0"));
	}
	buf[10] = '\0';
	buf_ptr = buf + 9;
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

char	*format_x(const char **str_format, char *base, va_list *args,
		int *char_written)
{
	size_t	n;
	char	buf[17];
	char	*buf_ptr;

	(*str_format)++;
	n = va_arg(*args, size_t);
	if (n == 0)
	{
		(*char_written)++;
		return (ft_strdup("0"));
	}
	buf[16] = '\0';
	buf_ptr = buf + 15;
	while (n != 0)
	{
		*buf_ptr-- = base[n % 16];
		n /= 16;
	}
	*char_written += ft_strlen(buf_ptr);
	return (ft_strdup(buf_ptr));
}
char	*format_percent(const char **str_format, int *char_written)
{
	(*char_written)++;
	(*str_format)++;
	return (ft_strdup("%"));
}
