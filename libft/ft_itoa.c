/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:51:24 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/08 17:41:30 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		count;
	int		temp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	count = ft_count(n);
	temp = n;
	if (temp < 0)
		temp = -temp;
	if (!(s = ft_memalloc(count + 1)))
		return (0);
	s[count] = '\0';
	while (temp > 0)
	{
		s[--count] = temp % 10 + '0';
		temp = temp / 10;
	}
	if (n < 0)
		s[--count] = '-';
	return (s);
}
