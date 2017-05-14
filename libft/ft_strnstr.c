/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:45:21 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/05 15:50:13 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*s11;
	char	*s22;

	i = 0;
	s11 = (char*)s1;
	s22 = (char*)s2;
	len = ft_strlen(s22);
	if (len == 0)
		return (s11);
	while (s11[i] && i < n)
	{
		j = 0;
		while (s22[j] == s11[j + i] && j + i < n)
		{
			if (j == len - 1)
				return (s11 + i);
			j++;
		}
		i++;
	}
	return (0);
}
