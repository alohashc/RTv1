/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:45:12 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/02 15:03:26 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t s;
	size_t d;
	size_t i;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (size > d)
	{
		while (src[i] && d < size - 1)
		{
			dst[d] = src[i];
			i++;
			d++;
		}
		dst[d] = '\0';
		return ((s - i) + d);
	}
	return (s + size);
}
