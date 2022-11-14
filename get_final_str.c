/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:42:11 by vfries            #+#    #+#             */
/*   Updated: 2022/11/14 19:45:01 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	free_content(void *content)
{
	if (content != NULL && content != (void *)-1)
		free(content);
}

int	get_final_str_len(t_list *str_list)
{
	int		len;

	len = 0;
	while (str_list)
	{
		if (str_list->content == (void *)-1)
			len++;
		else
			len += ft_strlen(str_list->content);
		str_list = str_list->next;
	}
	return (len);
}

void	fill_final_str(char *final_str, t_list *str_list)
{
	char	*node_str;
	t_list	*current;

	current = str_list;
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
}

char	*get_final_str(t_list *str_list, int *char_written)
{
	char	*final_str;

	*char_written = get_final_str_len(str_list);
	final_str = malloc(*char_written + 1);
	if (final_str == NULL)
		return (NULL);
	fill_final_str(final_str, str_list);
	return (final_str);
}
