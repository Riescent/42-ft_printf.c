/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:28:30 by vfries            #+#    #+#             */
/*   Updated: 2022/11/07 14:38:09 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (len > 0 && *haystack)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i])
		{
			if (len - i == 0)
				return (NULL);
			i++;
		}
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
