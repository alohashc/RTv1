/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:27:08 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:27:11 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_light_cyl(t_main *main, t_vec dir)
{
	double	t;
	t_vec	tmp;
	int		i;

	i = 0;
	while (i < main->num)
	{
		main->ray[i].p = ft_add(main->cam_tmp,
				ft_mult(dir, main->cyl[main->index].inter.t));
		t = ft_dot_prod(ft_diff(main->ray[i].p,
				main->cyl[main->index].center_cyl), main->cyl[main->index].dir);
		tmp = ft_add(main->cyl[main->index].center_cyl,
				ft_mult(main->cyl[main->index].dir, t));
		main->ray[i].n = ft_diff(main->ray[i].p, tmp);
		main->ray[i].n = ft_norm(main->ray[i].n);
		main->ray[i].l = ft_diff(main->light[i].l_pos, main->ray[i].p);
		main->ray[i].l = ft_norm(main->ray[i].l);
		main->ray[i].h = ft_diff(main->ray[i].l, dir);
		main->ray[i].h = ft_norm(main->ray[i].h);
		i++;
	}
}

double	ft_cyl_intersect(t_main *main, t_vec dir, t_vec pos, int i)
{
	double	disc;
	double	t1;
	double	t2;

	main->cyl[i].inter.disc = ft_disc_cyl(main, dir, pos, i);
	disc = main->cyl[i].inter.disc;
	main->cyl[i].inter.t = 0;
	if (disc >= 0)
	{
		t1 = (-main->cyl[i].inter.b + sqrt(disc)) / 2. / main->cyl[i].inter.a;
		t2 = (-main->cyl[i].inter.b - sqrt(disc)) / 2. / main->cyl[i].inter.a;
		if (t1 > 0 || t2 > 0)
		{
			if (t1 < 0 || t2 < 0)
				main->cyl[i].inter.t = fmax(t1, t2);
			else
				main->cyl[i].inter.t = fmin(t1, t2);
		}
	}
	return (main->cyl[i].inter.t);
}

double	ft_disc_cyl(t_main *main, t_vec dir, t_vec pos, int i)
{
	t_disc	dis;
	t_vec	a;
	t_vec	c;

	a = ft_diff(dir, ft_mult(main->cyl[i].dir,
					ft_dot_prod(dir, main->cyl[i].dir)));
	main->cyl[i].inter.diff = ft_diff(pos, main->cyl[i].center_cyl);
	dis.a = ft_dot_prod(a, a);
	c = ft_diff(main->cyl[i].inter.diff, ft_mult(main->cyl[i].dir,
					ft_dot_prod(main->cyl[i].inter.diff, main->cyl[i].dir)));
	dis.c = ft_dot_prod(c, c) - pow(main->cyl[i].radius, 2);
	dis.b = 2 * ft_dot_prod(a, c);
	main->cyl[i].inter.a = dis.a;
	main->cyl[i].inter.b = dis.b;
	main->cyl[i].inter.c = dis.c;
	dis.disc = dis.b * dis.b - 4 * dis.a * dis.c;
	return (dis.disc);
}

void	ft_tracing_cylinder(t_main *main)
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
			if (ft_cyl_intersect(main, dir, main->cam_tmp, 0) != 0)
			{
				ft_light_cyl(main, dir);
				ft_color_pixel(main, x, y, ft_color(main, main->cyl[0].col));
			}
		}
	}
}

void	ft_cylinder(t_main *main)
{
	main->win.img = mlx_new_image(main->win.mlx, WIDTH, HEIGHT);
	main->win.data = mlx_get_data_addr(main->win.img, &main->win.bpp,
									&main->win.size_l, &main->win.endian);
	main->cyl = (t_cylinder*)malloc(sizeof(t_cylinder) * 1);
	main->flag.color = 1;
	main->win.marker = 2;
	main->cyl[0].radius = 2.0;
	main->cyl[0].center_cyl = ft_vec(-20, 0, -10);
	main->cyl[0].dir = ft_norm(ft_vec(0, 1, 0));
	main->cyl[0].col = ft_vec(200, 0, 125);
	ft_tracing_cylinder(main);
	mlx_put_image_to_window(main->win.mlx, main->win.win, main->win.img, 0, 0);
	free(main->cyl);
}
