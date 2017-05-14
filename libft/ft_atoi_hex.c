/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:37:11 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/06 12:25:07 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		num(char c)
{
	int		a;

	if (c >= '0' && c <= '9')
	{
		a = c - '0';
		return (a);
	}
	else if (c >= 'a' && c <= 'z')
		c = c - 32;
	a = c - 'A' + 10;
	return (a);
}

int		ft_atoi_hex(char *str)
{
	int		nb;
	int		i;
	int		len;
	int		power;

	power = 1;
	nb = 0;
	len = ft_strlen(str);
	i = len - 1;
	if (num(str[i]) >= 16)
		return (-1);
	while (i >= 0)
	{
		nb = nb + num(str[i]) * power;
		power = power * 16;
		i--;
	}
	return (nb);
}
