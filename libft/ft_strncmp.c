/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:27:06 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/05 18:13:34 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	i = 0;
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (s11[i] && s22[i] && s11[i] == s22[i])
	{
		i++;
		if (i == n)
			return (0);
	}
	return (s11[i] - s22[i]);
}
