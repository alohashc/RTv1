//
// Created by Andrii Lohashchuk on 5/13/17.
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

double	ft_magnitude(t_vec vec)
{
	double len;

	len = sqrt(ft_dot_prod(vec, vec));
	return (len);
}

t_vec	ft_normalize(t_vec vec)
{
	t_vec res;
	double len;

	len = ft_magnitude(vec);
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
