/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:04:16 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/05 15:47:58 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (void*)src;
	s2 = (void*)dst;
	i = 0;
	if (s1 > s2)
	{
		while (i < len)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			s2[len - i - 1] = s1[len - i - 1];
			i++;
		}
	}
	return (dst);
}
