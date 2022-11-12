/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:48:56 by vfries            #+#    #+#             */
/*   Updated: 2022/11/12 22:22:59 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

char	*format(const char *str_format, int *char_written)
{
	(void)char_written;
	if (*str_format == '\0')
		return (NULL);
	if (*str_format == '%')
		return (ft_strdup("%"));
	return (NULL);
}
