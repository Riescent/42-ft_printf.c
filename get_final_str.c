/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:42:11 by vfries            #+#    #+#             */
/*   Updated: 2022/11/08 23:09:07 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	lst_reverse(t_list **lst)
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	previous = NULL;
	current = *lst;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*lst = previous;
}

char	*get_final_str(t_list *line_lst)
{
	char	*line;
	char	*line_start;
	char	*list_str;
	t_list	*current;

	lst_reverse(&line_lst);
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
	ft_lstclear(&line_lst, &free);
	return (line_start);
}
