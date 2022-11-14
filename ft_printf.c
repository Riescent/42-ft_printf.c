/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:32:51 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 04:45:58 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

char	*get_final_str(t_list *line_lst);
char	*format(const char *str_format, int *char_written, va_list *args);

char	*strdup_till_format(const char **str_format, int *char_written)
{
	const char	*result_start;

	result_start = *str_format;
	while (**str_format && **str_format != '%')
		(*str_format)++;
	*char_written += *str_format - result_start;
	return (ft_substr(result_start, 0, *str_format - result_start));
}

t_list	*get_str_list(const char *str_format, va_list *args, int *char_written)
{
	char	*str;
	t_list	*str_list;

	str_list = NULL;
	*char_written = 0;
	while (*str_format)
	{
		if (*str_format == '%')
		{
			str = format(str_format + 1, char_written, args);
			str_format += 2;
		}
		else
			str = strdup_till_format(&str_format, char_written);
		if (str == NULL)
		{
			ft_lstclear(&str_list, free);
			return (NULL);
		}
		else
			ft_lstadd_front(&str_list, ft_lstnew(str));
	}
	ft_lst_reverse(&str_list);
	return (str_list);
}

int	ft_printf(const char *str_format, ...)
{
	int		char_written;
	t_list	*str_list;
	va_list	args;
	char	*final_str;

	va_start(args, str_format);
	str_list = get_str_list(str_format, &args, &char_written);
	va_end(args);
	final_str = get_final_str(str_list);
	write(0, final_str, char_written);
	free(final_str);
	ft_lstclear(&str_list, &free);
	return (char_written);
}
