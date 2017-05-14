/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:56:19 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/02 17:22:28 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*s11;
	int		len;

	if (!s1 || !s2)
		return (0);
	s11 = (char*)s1;
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_strcpy(str, s11);
	return (ft_strcat(str, s2));
}
