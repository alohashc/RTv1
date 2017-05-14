/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:37:53 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/01 11:24:52 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = (void*)src;
	s2 = (void*)dst;
	i = 0;
	while (n != 0)
	{
		if ((*s2++ = *s1++) == c)
			return (s2);
		n--;
	}
	return (0);
}
