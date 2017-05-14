//
// Created by Andrii Lohashchuk on 4/10/17.
//

#include "rtv1.h"

t_vec	ft_vec(double a, double b, double c)
{
	t_vec res;

	res.x = a;
	res.y = b;
	res.z = c;
	return (res);
}

double	ft_dot_prod(t_vec vec, t_vec vec1)
{
	double res;

	res = vec.x * vec1.x + vec.y * vec1.y + vec.z * vec1.z;
	return (res);
}

t_vec	ft_cross_prod(t_vec vec, t_vec vec1)
{
	t_vec res;

	res.x = vec.y * vec1.z - vec.z * vec1.y;
	res.y = vec.x * vec1.z - vec.z * vec1.x;
	res.z = vec.x * vec1.y - vec.y * vec1.x;
	return (res);
}

t_vec	ft_diff(t_vec vec, t_vec vec1)
{
	t_vec res;

	res.x = vec.x - vec1.x;
	res.y = vec.y - vec1.y;
	res.z = vec.z - vec1.z;
	return (res);
}

t_vec	ft_add(t_vec vec, t_vec vec1)
{
	t_vec res;

	res.x = vec.x + vec1.x;
	res.y = vec.y + vec1.y;
	res.z = vec.z + vec1.z;
	return (res);
}

t_vec	ft_mult(t_vec vec, double a)
{
	t_vec res;

	res.x = vec.x * a;
	res.y = vec.y * a;
	res.z = vec.z * a;
	return (res);
}

t_vec	ft_normalize(t_vec vec)
{
	t_vec res;
	double len;

	len = sqrt(ft_dot_prod(vec, vec));
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
