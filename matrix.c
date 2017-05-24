/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:47:55 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:47:57 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_mult_m(t_main *main, t_matrix a, t_matrix b)
{
	int		i;
	int		j;
	int		k;
	double	sum;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			sum = 0;
			while (k < 4)
			{
				sum += a.m[i][k] * b.m[k][j];
				main->matrix.m_res.m[i][j] = sum;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_m_rotate_z(t_main *main)
{
	main->matrix.m_z.m[0][0] = cos(main->matrix.angle_z);
	main->matrix.m_z.m[0][1] = -sin(main->matrix.angle_z);
	main->matrix.m_z.m[0][2] = 0;
	main->matrix.m_z.m[0][3] = 0;
	main->matrix.m_z.m[1][0] = sin(main->matrix.angle_z);
	main->matrix.m_z.m[1][1] = cos(main->matrix.angle_z);
	main->matrix.m_z.m[1][2] = 0;
	main->matrix.m_z.m[1][3] = 0;
	main->matrix.m_z.m[2][0] = 0;
	main->matrix.m_z.m[2][1] = 0;
	main->matrix.m_z.m[2][2] = 1;
	main->matrix.m_z.m[2][3] = 0;
	main->matrix.m_z.m[3][0] = 0;
	main->matrix.m_z.m[3][1] = 0;
	main->matrix.m_z.m[3][2] = 0;
	main->matrix.m_z.m[3][3] = 1;
}

void	ft_m_rotate_x(t_main *main)
{
	main->matrix.m_x.m[0][0] = 1;
	main->matrix.m_x.m[0][1] = 0;
	main->matrix.m_x.m[0][2] = 0;
	main->matrix.m_x.m[0][3] = 0;
	main->matrix.m_x.m[1][0] = 0;
	main->matrix.m_x.m[1][1] = cos(main->matrix.angle_x);
	main->matrix.m_x.m[1][2] = -sin(main->matrix.angle_x);
	main->matrix.m_x.m[1][3] = 0;
	main->matrix.m_x.m[2][0] = 0;
	main->matrix.m_x.m[2][1] = sin(main->matrix.angle_x);
	main->matrix.m_x.m[2][2] = cos(main->matrix.angle_x);
	main->matrix.m_x.m[2][3] = 0;
	main->matrix.m_x.m[3][0] = 0;
	main->matrix.m_x.m[3][1] = 0;
	main->matrix.m_x.m[3][2] = 0;
	main->matrix.m_x.m[3][3] = 1;
}

void	ft_m_rotate_y(t_main *main)
{
	main->matrix.m_y.m[0][0] = cos(main->matrix.angle_y);
	main->matrix.m_y.m[0][1] = 0;
	main->matrix.m_y.m[0][2] = sin(main->matrix.angle_y);
	main->matrix.m_y.m[0][3] = 0;
	main->matrix.m_y.m[1][0] = 0;
	main->matrix.m_y.m[1][1] = 1;
	main->matrix.m_y.m[1][2] = 0;
	main->matrix.m_y.m[1][3] = 0;
	main->matrix.m_y.m[2][0] = -sin(main->matrix.angle_y);
	main->matrix.m_y.m[2][1] = 0;
	main->matrix.m_y.m[2][2] = cos(main->matrix.angle_y);
	main->matrix.m_y.m[2][3] = 0;
	main->matrix.m_y.m[3][0] = 0;
	main->matrix.m_y.m[3][1] = 0;
	main->matrix.m_y.m[3][2] = 0;
	main->matrix.m_y.m[3][3] = 1;
}

void	ft_mat(t_main *main)
{
	ft_m_rotate_x(main);
	ft_m_rotate_y(main);
	ft_m_rotate_z(main);
	ft_mult_m(main, main->matrix.m_x, main->matrix.m_y);
	ft_mult_m(main, main->matrix.m_res, main->matrix.m_z);
}
