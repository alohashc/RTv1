/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:00:17 by alohashc          #+#    #+#             */
/*   Updated: 2017/02/22 13:48:31 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		flag;
	int		res;
	char	*s;

	i = 0;
	res = 0;
	flag = 0;
	s = (char*)str;
	while (((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r')) && s[i])
		i++;
	if (s[i] == 45)
		flag = -1;
	if (s[i] == 43 || s[i] == 45)
		i++;
	while (s[i] >= 48 && s[i] <= 57 && s[i])
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	if (flag < 0)
		res = res * flag;
	return (res);
}
