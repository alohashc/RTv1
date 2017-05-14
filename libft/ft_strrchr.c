/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:18:52 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/05 18:03:04 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;
	char *s1;

	tmp = 0;
	s1 = (char*)s;
	while (*s1)
	{
		if (*s1 == (char)c)
			tmp = s1;
		s1++;
	}
	if (*s1 == '\0' && (char)c == '\0')
		return (s1);
	return (tmp);
}
