/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:15:00 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:15:06 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_find_shadow__min_t(t_main *main, int k, int len)
{
	double	t;
	int		i;
	int		j;

	i = 0;
	j = -1;
	t = 0;
	while (++j < len)
		if (main->light[k].t_shadow[j] > t)
			t = main->light[k].t_shadow[j];
	while (i < len)
	{
		if (main->light[k].t_shadow[i] < t && main->light[k].t_shadow[i] != 0)
			t = main->light[k].t_shadow[i];
		i++;
	}
	return (t);
}

double	ft_check_shadow(t_main *main, int k)
{
	int		i;
	int		j;
	int		len;
	double	t;

	i = -1;
	j = 0;
	len = main->mem.sph + main->mem.plane + main->mem.cyl + main->mem.cone;
	main->light[k].t_shadow = (double*)malloc(sizeof(double) * len);
	while (++i < main->mem.sph && main->flag.sph == 0)
		main->light[k].t_shadow[j++] = main->sph[i].inter.t;
	i = -1;
	while (++i < main->mem.plane && main->flag.plane == 0)
		main->light[k].t_shadow[j++] = main->plane[i].inter.t;
	i = -1;
	while (++i < main->mem.cyl && main->flag.cyl == 0)
		main->light[k].t_shadow[j++] = main->cyl[i].inter.t;
	i = -1;
	while (++i < main->mem.cone && main->flag.cone == 0)
		main->light[k].t_shadow[j++] = main->cone[i].inter.t;
	t = ft_find_shadow__min_t(main, k, len);
	free(main->light[k].t_shadow);
	return (t);
}

void	ft_count_shadow(t_main *main, double *r, double *g, double *b)
{
	int		i;
	t_vec	light;
	double	t;

	i = -1;
	while (++i < main->num)
	{
		main->ray[i].p = ft_add(main->ray[i].p,
								ft_mult(main->ray[i].n, 0.001));
		main->ray[i].l = ft_norm(ft_diff(main->light[i].l_pos, main->ray[i].p));
		ft_for_each_obj(main, main->ray[i].l, main->ray[i].p);
		light = ft_diff(main->light[i].l_pos, main->ray[i].p);
		t = ft_check_shadow(main, i);
		if (t != 0 && t < ft_len(light))
		{
			*r *= 0.8;
			*g *= 0.8;
			*b *= 0.8;
		}
	}
}

int		ft_shadow(t_main *main, double r, double g, double b)
{
	int		final;

	if (!main->flag.color)
		ft_count_shadow(main, &r, &g, &b);
	final = ((int)fmin(255, r) << 16) + ((int)fmin(255, g) << 8) +
			((int)fmin(255, b));
	return (final);
}

int		ft_color(t_main *main, t_vec col)
{
	double	r;
	double	g;
	double	b;
	int		i;

	i = -1;
	b = 0.0;
	g = 0.0;
	r = 0.0;
	while (++i < main->num)
	{
		r += (col.x * (AMB + DIFF * ft_dot_prod(main->ray[i].n, main->ray[i].l))
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
