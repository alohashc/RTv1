/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:09:43 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/08 10:20:27 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	int		len;
	int		i;

	i = 0;
	if (!s && !f)
		return (0);
	len = ft_strlen(s);
	s1 = (char*)malloc(sizeof(char) * len + 1);
	if (!s1)
		return (0);
	while (s[i])
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
