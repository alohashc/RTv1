//
// Created by Andrii Lohashchuk on 5/13/17.
//

#include "rtv1.h"

int	ft_check_shadow(t_main *main)
{
	int i;
	int j;
	int len;

	i = -1;
	j = 0;
	len = main->mem.sph + main->mem.plane + main->mem.cyl + main->mem.cone;
	main->light->t_shadow = (double*)malloc(sizeof(double) * len);
	while (++i < main->mem.sph && main->flag.sph == 0)
		main->light->t_shadow[j++] = main->sph[i].inter.t;
	i = -1;
	while (++i < main->mem.plane && main->flag.plane == 0)
		main->light->t_shadow[j++] = main->sph[i].inter.t;
	i = -1;
	while (++i < main->mem.cyl && main->flag.cyl == 0)
		main->light->t_shadow[j++] = main->sph[i].inter.t;
	i = -1;
	while (++i < main->mem.cone && main->flag.cone == 0)
		main->light->t_shadow[j++] = main->sph[i].inter.t;
	return (len);
}

void	ft_count_shadow(t_main *main, double *r, double *g, double *b)
{
	int		i;
	int		j;
	double 	len;
	t_vec	light;
	int 	t;

	i = -1;
	while (++i < main->num)
	{
		main->ray[i].p = ft_add(main->ray[i].p, ft_mult(main->ray[i].n, 0.001));
		main->ray[i].l = ft_diff(main->light[i].l_position, main->ray[i].p);
		main->ray[i].l = ft_normalize(main->ray[i].l);
		ft_for_each_obj(main, main->ray[i].l, main->ray[i].p);
		light = ft_diff(main->light[i].l_position, main->ray[i].p);
		len = ft_magnitude(light);
		j = -1;
		t = ft_check_shadow(main);
		while (++j < t)
			if (main->light->t_shadow[j] != 0 && main->light->t_shadow[j] < len)
			{
				*r *= 0.8;
				*g *= 0.8;
				*b *= 0.8;
				break;
			}
		free(main->light->t_shadow);
	}
}

int	ft_shadow(t_main *main, double r, double g, double b)
{
	int		final;

	r = fmin(255, r);
	g = fmin(255, g);
	b = fmin(255, b);
	if (!main->flag.color)
		ft_count_shadow(main, &r, &g, &b);
	final = ((int)fmin(255, r) << 16) + ((int)fmin(255, g) << 8) +
			((int)fmin(255, b));
	return (final);
}

int	ft_color(t_main *main, t_vec col)
{
	double 			r;
	double 			g;
	double 			b;
	int 			i;

	i = -1;
	b = 0;
	g = 0;
	r = 0;
	while (++i < main->num)
	{
		r += (col.x * (AMB + DIFF * ft_dot_prod(main->ray[i].n,main->ray[i].l))
			  + main->light[i].l_color.x * SPEC *
						pow(ft_dot_prod(main->ray[i].n, main->ray[i].h), POW));
		g += (col.y * (AMB + DIFF * ft_dot_prod(main->ray[i].n, main->ray[i].l))
			  + main->light[i].l_color.y * SPEC *
						pow(ft_dot_prod(main->ray[i].n, main->ray[i].h), POW));
		b += (col.z * (AMB + DIFF * ft_dot_prod(main->ray[i].n, main->ray[i].l))
			  + main->light[i].l_color.z * SPEC *
						pow(ft_dot_prod(main->ray[i].n, main->ray[i].h), POW));
	}
	return (ft_shadow(main, r, g, b));
}