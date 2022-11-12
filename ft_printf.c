/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:32:51 by vfries            #+#    #+#             */
/*   Updated: 2022/11/12 21:49:12 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

char	*get_final_str(t_list *line_lst);
char	*format(const char *str_format, int *char_written);

char	*strdup_till_format(const char *str_format, int *char_written)
{
	const char	*result_end;

	result_end = str_format;
	while (*result_end && *result_end != '%')
		result_end++;
	*char_written += result_end - str_format;
	return (ft_substr(str_format, 0, result_end - str_format));
}

int	error(t_list *str_list)
{
	ft_lstclear(&str_list, &free);
	return (-1);
}

int	ft_printf(const char *str_format, ...)
{
	int		char_written;
	int		previous_char_written;
	t_list	*str_list;
	char	*str;

	str_list = NULL;
	char_written = 0;
	while (*str_format)
	{
		previous_char_written = char_written;
		if (*str_format == '%')
			str = format(str_format + 1, &char_written);
		else
			str = strdup_till_format(str_format, &char_written);
		if (str == NULL)
			return (error(str_list));
		else
			ft_lstadd_front(&str_list, ft_lstnew(str));
		str_format += char_written - previous_char_written;
	}
	write(0, get_final_str(str_list), char_written);
	ft_lstclear(&str_list, &free);
	return (char_written);
}
