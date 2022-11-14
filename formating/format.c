/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:48:56 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 02:25:18 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

#define HEXA_LOW "0123456789abcdef"
#define HEXA_UP "0123456789ABCDEF"

char	*format_u(const char **str_format, va_list *args, int *char_written);
char	*format_x(const char **str_format, char *base, va_list *args,
			int *char_written);
char	*format_percent(const char **str_format, int *char_written);

char	*format_c(const char **str_format, va_list *args, int *char_written)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	*str = va_arg(*args, int);
	str[1] = '\0';
	(*char_written)++;
	(*str_format)++;
	return (str);
}

char	*format_s(const char **str_format, va_list *args, int *char_written)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	if (str == NULL)
		return (NULL);
	*char_written += ft_strlen(str);
	(*str_format)++;
	return (str);
}

char	*format_p(const char **str_format, va_list *args, int *char_written)
{
	char	*hexa_value;

	hexa_value = format_x(str_format, HEXA_LOW, args, char_written);
	return (hexa_value);
}

char	*format_d_i(const char **str_format, va_list *args, int *char_written)
{
	char	*str;

	str = ft_itoa(va_arg(*args, int));
	*char_written += ft_strlen(str);
	(*str_format)++;
	return (str);
}

char	*format(const char **str_format, int *char_written, va_list *args)
{
	if (**str_format == '\0')
		return (NULL);
	else if (**str_format == 'c')
		return (format_c(str_format, args, char_written));
	else if (**str_format == 's')
		return (format_s(str_format, args, char_written));
	else if (**str_format == 'p')
		return (format_p(str_format, args, char_written));
	else if (**str_format == 'd' || **str_format == 'i')
		return (format_d_i(str_format, args, char_written));
	else if (**str_format == 'u')
		return (format_u(str_format, args, char_written));
	else if (**str_format == 'x')
		return (format_x(str_format, HEXA_LOW, args, char_written));
	else if (**str_format == 'X')
		return (format_x(str_format, HEXA_UP, args, char_written));
	else if (**str_format == '%')
		return (format_percent(str_format, char_written));
	return (NULL);
}
