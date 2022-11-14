/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:48:56 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 04:32:01 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

#define HEXA_LOW "0123456789abcdef"
#define HEXA_UP "0123456789ABCDEF"

char	*format_u(va_list *args, int *char_written);
char	*format_x(char *base, va_list *args, int *char_written);
char	*format_percent(int *char_written);

char	*format_c(va_list *args, int *char_written)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	*str = va_arg(*args, int);
	str[1] = '\0';
	(*char_written)++;
	return (str);
}

char	*format_s(va_list *args, int *char_written)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (str == NULL)
		return (NULL);
	*char_written += ft_strlen(str);
	return (str);
}

char	*format_p(va_list *args, int *char_written)
{
	char	*hexa_value;
	char	*str;

	hexa_value = format_x(HEXA_LOW, args, char_written);
	if (hexa_value == NULL)
		return (NULL);
	str = ft_strjoin("0x", hexa_value);
	free(hexa_value);
	*char_written += 2;
	return (str);
}

char	*format_d_i(va_list *args, int *char_written)
{
	char	*str;

	str = ft_itoa(va_arg(*args, int));
	if (str == NULL)
		return (NULL);
	*char_written += ft_strlen(str);
	return (str);
}

char	*format(const char *str_format, int *char_written, va_list *args)
{
	if (*str_format == 'c')
		return (format_c(args, char_written));
	else if (*str_format == 's')
		return (format_s(args, char_written));
	else if (*str_format == 'p')
		return (format_p(args, char_written));
	else if (*str_format == 'd' || *str_format == 'i')
		return (format_d_i(args, char_written));
	else if (*str_format == 'u')
		return (format_u(args, char_written));
	else if (*str_format == 'x')
		return (format_x(HEXA_LOW, args, char_written));
	else if (*str_format == 'X')
		return (format_x(HEXA_UP, args, char_written));
	else if (*str_format == '%')
		return (format_percent(char_written));
	return (NULL);
}
