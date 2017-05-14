/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:28:07 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/08 18:10:45 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	char	*s1;
	size_t	i;

	s1 = (char*)s;
	i = 0;
	if (!s1)
		return (0);
	s2 = (char*)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (0);
	while (i < len && s1[i + start])
	{
		s2[i] = s1[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
