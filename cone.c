/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:16:22 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:16:25 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_light_cone(t_main *main, t_vec dir)
{
	double	t;
	t_vec	tmp;
	t_vec	b;
	double	a;
	int		i;

	i = 0;
	while (i < main->num)
	{
		main->ray[i].p = ft_add(main->cam_tmp,
							ft_mult(dir, main->cone[main->index].inter.t));
		tmp = ft_diff(main->ray[i].p, main->cone[main->index].center_cone);
		t = ft_dot_prod(ft_norm(tmp), main->cone[main->index].dir);
		a = sqrt(ft_dot_prod(tmp, tmp)) / t;
		b = ft_mult(main->cone[main->index].dir, a);
		main->ray[i].n = ft_norm(ft_diff(tmp, b));
		main->ray[i].l = ft_diff(main->light[i].l_pos, main->ray[i].p);
		main->ray[i].l = ft_norm(main->ray[i].l);
		main->ray[i].h = ft_diff(main->ray[i].l, dir);
		main->ray[i].h = ft_norm(main->ray[i].h);
		i++;
	}
}

double	ft_cone_intersect(t_main *main, t_vec dir, t_vec pos, int i)
{
	double	disc;
	double	t1;
	double	t2;

	main->cone[i].inter.disc = ft_disc_cone(main, dir, pos, i);
	disc = main->cone[i].inter.disc;
	main->cone[i].inter.t = 0;
	if (disc >= 0)
	{
		t1 = (-main->cone[i].inter.b + sqrt(disc)) / 2. / main->cone[i].inter.a;
		t2 = (-main->cone[i].inter.b - sqrt(disc)) / 2. / main->cone[i].inter.a;
		if (t1 > 0 || t2 > 0)
		{
			if (t1 < 0 || t2 < 0)
				main->cone[i].inter.t = fmax(t1, t2);
			else
				main->cone[i].inter.t = fmin(t1, t2);
		}
	}
	return (main->cone[i].inter.t);
}

double	ft_disc_cone(t_main *main, t_vec dir, t_vec pos, int i)
{
	t_disc	dis;
	t_vec	a;
	t_vec	c;

	dir = ft_norm(dir);
	main->cone[i].inter.diff = ft_diff(pos, main->cone[i].center_cone);
	a = ft_diff(dir, ft_mult(main->cone[i].dir,
			ft_dot_prod(dir, main->cone[i].dir)));
	dis.a = pow(cos(ANGLE), 2) * ft_dot_prod(a, a) - pow(sin(ANGLE), 2) *
			pow(ft_dot_prod(dir, main->cone[i].dir), 2);
	c = ft_diff(main->cone[i].inter.diff, ft_mult(main->cone[i].dir,
			ft_dot_prod(main->cone[i].inter.diff, main->cone[i].dir)));
	dis.c = pow(cos(ANGLE), 2) * ft_dot_prod(c, c) - pow(sin(ANGLE), 2) *
			pow(ft_dot_prod(main->cone[i].inter.diff, main->cone[i].dir), 2);
	dis.b = 2 * (pow(cos(ANGLE), 2) * ft_dot_prod(a, c) - pow(sin(ANGLE), 2) *
			ft_dot_prod(dir, main->cone[i].dir) *
			ft_dot_prod(main->cone[i].inter.diff, main->cone[i].dir));
	main->cone[i].inter.a = dis.a;
	main->cone[i].inter.b = dis.b;
	main->cone[i].inter.c = dis.c;
	dis.disc = dis.b * dis.b - 4 * dis.a * dis.c;
	return (dis.disc);
}

void	ft_tracing_cone(t_main *main)
{
	t_vec	pix;
	t_vec	dir;
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pix.x = (2 * ((x + 0.5) / WIDTH) - 1) * RATIO * tan(FOV / 2);
			pix.y = (1 - 2 * ((y + 0.5) / HEIGHT)) * tan(FOV / 2);
			pix.z = main->cam.c_position.z - 1;
			dir = ft_norm(ft_diff(pix, main->cam.c_position));
			dir = ft_m_mult_vec(main, dir);
			if (ft_cone_intersect(main, dir, main->cam_tmp, 0) != 0)
			{
				ft_light_cone(main, dir);
				ft_color_pixel(main, x, y, ft_color(main, main->cone[0].col));
			}
		}
	}
}

void	ft_cone(t_main *main)
{
	main->win.img = mlx_new_image(main->win.mlx, WIDTH, HEIGHT);
	main->win.data = mlx_get_data_addr(main->win.img, &main->win.bpp,
									&main->win.size_l, &main->win.endian);
	main->cone = (t_cone*)malloc(sizeof(t_cone) * 1);
	main->flag.color = 1;
	main->win.marker = 3;
	main->cone[0].center_cone = ft_vec(0, 0, -10);
	main->cone[0].dir = ft_norm(ft_vec(0, 1, 0));
	main->cone[0].col = ft_vec(100, 20, 50);
	ft_tracing_cone(main);
	mlx_put_image_to_window(main->win.mlx, main->win.win, main->win.img, 0, 0);
	free(main->cone);
}
