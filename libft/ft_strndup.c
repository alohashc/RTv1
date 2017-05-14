/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:42:45 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/06 12:52:55 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)s1;
	while (s[i] && i < n)
		i++;
	dst = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	if (!dst)
		return (0);
	while (s[i] && i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
