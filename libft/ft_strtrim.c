/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:40:33 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/04 15:05:45 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	size_t	l;

	l = 0;
	if (!s)
		return (0);
	while (*s == '\n' || *s == '\t' || *s == ' ')
		s++;
	l = ft_strlen(s);
	while ((s[l - 1] == '\n' || s[l - 1] == '\t' || s[l - 1] == ' ') && l)
		l--;
	dst = ft_strnew(l);
	if (!dst)
		return (0);
	dst[l] = '\0';
	while (l--)
		dst[l] = s[l];
	return (dst);
}
