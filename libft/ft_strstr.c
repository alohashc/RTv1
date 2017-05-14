/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:45:21 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/01 11:14:52 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*s11;
	char	*s22;

	i = 0;
	s11 = (char*)s1;
	s22 = (char*)s2;
	len = ft_strlen(s22);
	if (s22[i] == '\0')
		return (s11);
	while (s11[i])
	{
		j = 0;
		while (s22[j] == s11[j + i])
		{
			if (j == len - 1)
				return (s11 + i);
			j++;
		}
		i++;
	}
	return (0);
}
