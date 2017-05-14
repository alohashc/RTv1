/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:03:12 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/08 18:37:41 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	a;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	a = ft_strncmp(s1, s2, n);
	if (a == 0)
		return (1);
	return (0);
}
