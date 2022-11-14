/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:32:51 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 09:32:54 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void	free_content(void *content);
char	*get_final_str(t_list *line_lst, int *char_written);
char	*format(const char *str_format, va_list *args);

char	*strdup_till_format(const char **str_format)
{
	const char	*result_start;

	result_start = *str_format;
	while (**str_format && **str_format != '%')
		(*str_format)++;
	return (ft_substr(result_start, 0, *str_format - result_start));
}

t_list	*get_str_list(const char *str_format, va_list *args)
{
	char	*str;
	t_list	*str_list;

	str_list = NULL;
	while (*str_format)
	{
		if (*str_format == '%')
		{
			str = format(str_format + 1, args);
			str_format += 2;
		}
		else
			str = strdup_till_format(&str_format);
		if (str == NULL)
		{
			ft_lstclear(&str_list, &free_content);
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
	str_list = get_str_list(str_format, &args);
	va_end(args);
	if (str_list == NULL)
		return (-1);
	final_str = get_final_str(str_list, &char_written);
	if (final_str == NULL)
		return (-1);
	write(1, final_str, char_written);
	free(final_str);
	ft_lstclear(&str_list, &free_content);
	return (char_written);
}
