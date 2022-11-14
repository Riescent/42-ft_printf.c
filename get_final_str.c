/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:42:11 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 09:33:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	free_content(void *content)
{
	if (content != NULL && content != (void *)-1)
		free(content);
}

size_t	get_final_str_len(t_list *line_lst)
{
	size_t	len;
	char	*str_end;

	len = 0;
	while (line_lst)
	{
		if (line_lst->content == (void *)-1)
			len++;
		else
		{
			str_end = line_lst->content;
			while (*str_end)
				str_end++;
			len += str_end - (char *)line_lst->content;
		}
		line_lst = line_lst->next;
	}
	return (len);
}

char	*get_final_str(t_list *line_lst, int *char_written)
{
	char	*final_str;
	char	*final_str_start;
	char	*node_str;
	t_list	*current;

	*char_written = get_final_str_len(line_lst);
	final_str = malloc(*char_written + 1);
	if (final_str == NULL)
	{
		ft_lstclear(&line_lst, &free_content);
		return (NULL);
	}
	final_str_start = final_str;
	current = line_lst;
	while (current)
	{
		if (current->content == (void *)-1)
			*final_str++ = '\0';
		else
		{
			node_str = current->content;
			while (*node_str)
				*final_str++ = *node_str++;
		}
		current = current->next;
	}
	*final_str = '\0';
	return (final_str_start);
}
