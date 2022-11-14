/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:48:56 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 09:14:44 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

char	*format_u(va_list *args);
char	*format_x(char *base, va_list *args);

#define HEXA_LOW "0123456789abcdef"
#define HEXA_UP "0123456789ABCDEF"

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
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*format_p(va_list *args)
{
	char	*hexa_value;
	char	*str;

	hexa_value = format_x(HEXA_LOW, args);
	if (hexa_value == NULL)
		return (NULL);
	str = ft_strjoin("0x", hexa_value);
	free(hexa_value);
	return (str);
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
		return (format_p(args));
	else if (*str_format == 'd' || *str_format == 'i')
		return (format_d_i(args));
	else if (*str_format == 'u')
		return (format_u(args));
	else if (*str_format == 'x')
		return (format_x(HEXA_LOW, args));
	else if (*str_format == 'X')
		return (format_x(HEXA_UP, args));
	else if (*str_format == '%')
		return (ft_strdup("%"));
	return (NULL);
}
