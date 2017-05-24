/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:59:31 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:59:34 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	ft_vec(double a, double b, double c)
{
	t_vec res;

	res.x = a;
	res.y = b;
	res.z = c;
	return (res);
}

double	ft_len(t_vec vec)
{
	double len;

	len = sqrt(ft_dot_prod(vec, vec));
	return (len);
}

t_vec	ft_norm(t_vec vec)
{
	t_vec	res;
	double	len;

	len = ft_len(vec);
	res.x = vec.x / len;
	res.y = vec.y / len;
	res.z = vec.z / len;
	return (res);
}

t_vec	ft_negative(t_vec vec)
{
	t_vec res;

	res.x = -vec.x;
	res.y = -vec.y;
	res.z = -vec.z;
	return (res);
}

t_vec	ft_m_mult_vec(t_main *main, t_vec vec)
{
	t_vec res;

	res.x = main->matrix.m_res.m[0][0] * vec.x + main->matrix.m_res.m[0][1] *
		vec.y + main->matrix.m_res.m[0][2] * vec.z + main->matrix.m_res.m[0][3];
	res.y = main->matrix.m_res.m[1][0] * vec.x + main->matrix.m_res.m[1][1] *
		vec.y + main->matrix.m_res.m[1][2] * vec.z + main->matrix.m_res.m[1][3];
	res.z = main->matrix.m_res.m[2][0] * vec.x + main->matrix.m_res.m[2][1] *
		vec.y + main->matrix.m_res.m[2][2] * vec.z + main->matrix.m_res.m[2][3];
	return (res);
}
