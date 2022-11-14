/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:48:56 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 19:46:24 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

char	*format_u(va_list *args);
char	*format_x(char *base, va_list *args);

#define HEXA_LOWER "0123456789abcdef"
#define HEXA_UPPER "0123456789ABCDEF"

char	*format_c(va_list *args)
{
	char	*str;
	char	c;

	c = va_arg(*args, int);
	if (c == '\0')
		return ((void *)-1);
	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	*str = c;
	str[1] = '\0';
	return (str);
}

char	*format_s(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*format_p(va_list *args, char *base)
{
	size_t	n;
	char	buf[19];
	char	*buf_ptr;

	n = va_arg(*args, size_t);
	if (n == 0)
		return (ft_strdup("0x0"));
	buf[18] = '\0';
	buf_ptr = buf + 17;
	while (n != 0)
	{
		*buf_ptr-- = base[n % 16];
		n /= 16;
	}
	*buf_ptr-- = 'x';
	*buf_ptr = '0';
	return (ft_strdup(buf_ptr));
}

char	*format_d_i(va_list *args)
{
	return (ft_itoa(va_arg(*args, int)));
}

char	*format(const char *str_format, va_list *args)
{
	if (*str_format == 'c')
		return (format_c(args));
	else if (*str_format == 's')
		return (format_s(args));
	else if (*str_format == 'p')
		return (format_p(args, HEXA_LOWER));
	else if (*str_format == 'd' || *str_format == 'i')
		return (format_d_i(args));
	else if (*str_format == 'u')
		return (format_u(args));
	else if (*str_format == 'x')
		return (format_x(HEXA_LOWER, args));
	else if (*str_format == 'X')
		return (format_x(HEXA_UPPER, args));
	else if (*str_format == '%')
		return (ft_strdup("%"));
	return (NULL);
}
