//
// Created by Andrii Lohashchuk on 5/15/17.
//

#include "rtv1.h"

void	ft_print(t_main *main)
{
	int i = -1;
	int j;

	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			printf("%f ", main->matrix.m_res.m[i][j]);
		printf("\n");
	}
}

t_vec	ft_m_mult_vec(t_main *main, t_vec vec)
{
	t_vec res;
	double w;

	res.x = main->matrix.m_res.m[0][0] * vec.x + main->matrix.m_res.m[0][1] *
		vec.y + main->matrix.m_res.m[0][2] * vec.z + main->matrix.m_res.m[0][3];
	res.y = main->matrix.m_res.m[1][0] * vec.x + main->matrix.m_res.m[1][1] *
		vec.y + main->matrix.m_res.m[1][2] * vec.z + main->matrix.m_res.m[1][3];
	res.z = main->matrix.m_res.m[2][0] * vec.x + main->matrix.m_res.m[2][1] *
		vec.y + main->matrix.m_res.m[2][2] * vec.z + main->matrix.m_res.m[2][3];
	w = main->matrix.m_res.m[3][0] * vec.x + main->matrix.m_res.m[3][1] *
											 vec.y + main->matrix.m_res.m[3][2] * vec.z + main->matrix.m_res.m[3][3];
	res.x /= w;
	res.y /= w;
	res.z /= w;
	return (res);
}

void	ft_mult_m(t_main *main, t_matrix a, t_matrix b)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				main->matrix.m_res.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_m_rotate_z(t_main *main)
{
	main->matrix.m_z.m[0][0] = cos(main->angle);
	main->matrix.m_z.m[0][1] = -sin(main->angle);
	main->matrix.m_z.m[0][2] = 0;
	main->matrix.m_z.m[0][3] = 0;
	main->matrix.m_z.m[1][0] = sin(main->angle);
	main->matrix.m_z.m[1][1] = cos(main->angle);
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
	main->matrix.m_x.m[1][1] = cos(main->angle);
	main->matrix.m_x.m[1][2] = -sin(main->angle);
	main->matrix.m_x.m[1][3] = 0;
	main->matrix.m_x.m[2][0] = 0;
	main->matrix.m_x.m[2][1] = sin(main->angle);
	main->matrix.m_x.m[2][2] = cos(main->angle);
	main->matrix.m_x.m[2][3] = 0;
	main->matrix.m_x.m[3][0] = 0;
	main->matrix.m_x.m[3][1] = 0;
	main->matrix.m_x.m[3][2] = 0;
	main->matrix.m_x.m[3][3] = 1;
}

void	ft_m_rotate_y(t_main *main)
{
	main->matrix.m_y.m[0][0] = cos(main->angle);
	main->matrix.m_y.m[0][1] = 0;
	main->matrix.m_y.m[0][2] = sin(main->angle);
	main->matrix.m_y.m[0][3] = 0;
	main->matrix.m_y.m[1][0] = 0;
	main->matrix.m_y.m[1][1] = 1;
	main->matrix.m_y.m[1][2] = 0;
	main->matrix.m_y.m[1][3] = 0;
	main->matrix.m_y.m[2][0] = -sin(main->angle);
	main->matrix.m_y.m[2][1] = 0;
	main->matrix.m_y.m[2][2] = cos(main->angle);
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
	main->matrix.m_res.m[0][0] = 0;
	main->matrix.m_res.m[0][1] = 0;
	main->matrix.m_res.m[0][2] = 0;
	main->matrix.m_res.m[0][3] = 0;
	main->matrix.m_res.m[1][0] = 0;
	main->matrix.m_res.m[1][1] = 0;
	main->matrix.m_res.m[1][2] = 0;
	main->matrix.m_res.m[1][3] = 0;
	main->matrix.m_res.m[2][0] = 0;
	main->matrix.m_res.m[2][1] = 0;
	main->matrix.m_res.m[2][2] = 0;
	main->matrix.m_res.m[2][3] = 0;
	main->matrix.m_res.m[3][0] = 0;
	main->matrix.m_res.m[3][1] = 0;
	main->matrix.m_res.m[3][2] = 0;
	main->matrix.m_res.m[3][3] = 0;
	ft_print(main);
	ft_mult_m(main, main->matrix.m_x, main->matrix.m_y);
	ft_print(main);
	ft_mult_m(main, main->matrix.m_res, main->matrix.m_z);
	ft_print(main);
}