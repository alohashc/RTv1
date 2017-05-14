/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:34:07 by alohashc          #+#    #+#             */
/*   Updated: 2016/12/01 18:46:11 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int flag;

	flag = 0;
	if (nb == -2147483648)
	{
		nb = nb / 10;
		flag = -1;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10 && nb <= 2147483647)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb >= 0 && nb <= 9)
	{
		nb = nb + '0';
		write(fd, &nb, 1);
	}
	if (flag < 0)
		write(fd, "8", 1);
}
