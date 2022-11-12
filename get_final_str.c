/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:42:11 by vfries            #+#    #+#             */
/*   Updated: 2022/11/12 22:58:30 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

size_t	get_final_str_len(t_list *line_lst)
{
	size_t	len;
	char	*str_end;

	len = 0;
	while (line_lst)
	{
		str_end = line_lst->content;
		while (*str_end)
			str_end++;
		len += str_end - (char *)line_lst->content;
		line_lst = line_lst->next;
	}
	return (len);
}

char	*get_final_str(t_list *line_lst)
{
	char	*line;
	char	*line_start;
	char	*list_str;
	t_list	*current;

	line = malloc(get_final_str_len(line_lst) + 1);
	if (line == NULL)
	{
		ft_lstclear(&line_lst, &free);
		return (NULL);
	}
	line_start = line;
	current = line_lst;
	while (current)
	{
		list_str = current->content;
		while (*list_str)
			*line++ = *list_str++;
		current = current->next;
	}
	*line = '\0';
	return (line_start);
}
