/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:52:17 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:52:20 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_light_sph(t_main *main, t_vec dir)
{
	int i;

	i = 0;
	while (i < main->num)
	{
		main->ray[i].p = ft_add(main->cam_tmp,
							ft_mult(dir, main->sph[main->index].inter.t));
		main->ray[i].n = ft_diff(main->ray[i].p,
							main->sph[main->index].center_sph);
		main->ray[i].n = ft_norm(main->ray[i].n);
		main->ray[i].l = ft_diff(main->light[i].l_pos, main->ray[i].p);
		main->ray[i].l = ft_norm(main->ray[i].l);
		main->ray[i].h = ft_diff(main->ray[i].l, dir);
		main->ray[i].h = ft_norm(main->ray[i].h);
		i++;
	}
}

double	ft_intersect_sph(t_main *main, t_vec dir, t_vec pos, int i)
{
	double	disc;
	double	t1;
	double	t2;

	main->sph[i].inter.disc = ft_disc_sph(main, dir, pos, i);
	disc = main->sph[i].inter.disc;
	main->sph[i].inter.t = 0;
	if (disc >= 0)
	{
		t1 = (-main->sph[i].inter.b + sqrt(disc)) / 2 / main->sph[i].inter.a;
		t2 = (-main->sph[i].inter.b - sqrt(disc)) / 2 / main->sph[i].inter.a;
		if (t1 > 0 || t2 > 0)
		{
			if (t1 < 0 || t2 < 0)
				main->sph[i].inter.t = fmax(t1, t2);
			else
				main->sph[i].inter.t = fmin(t1, t2);
		}
	}
	return (main->sph[i].inter.t);
}

double	ft_disc_sph(t_main *main, t_vec dir, t_vec pos, int i)
{
	t_disc	dis;
	t_vec	tmp;

	tmp = pos;
	main->sph[i].inter.diff = ft_diff(tmp, main->sph[i].center_sph);
	dis.a = ft_dot_prod(dir, dir);
	dis.b = 2 * ft_dot_prod(dir, main->sph[i].inter.diff);
	dis.c = ft_dot_prod(main->sph[i].inter.diff,
		main->sph[i].inter.diff) - main->sph[i].radius * main->sph[i].radius;
	dis.disc = dis.b * dis.b - 4 * dis.a * dis.c;
	main->sph[i].inter.a = dis.a;
	main->sph[i].inter.b = dis.b;
	main->sph[i].inter.c = dis.c;
	return (dis.disc);
}

void	ft_tracing_sphere(t_main *main)
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
			if (ft_intersect_sph(main, dir, main->cam_tmp, 0) != 0)
			{
				ft_light_sph(main, dir);
				ft_color_pixel(main, x, y, ft_color(main, main->sph[0].col));
			}
		}
	}
}

void	ft_sphere(t_main *main)
{
	main->win.img = mlx_new_image(main->win.mlx, WIDTH, HEIGHT);
	main->win.data = mlx_get_data_addr(main->win.img, &main->win.bpp,
									&main->win.size_l, &main->win.endian);
	main->sph = (t_sphere*)malloc(sizeof(t_sphere) * 1);
	main->flag.color = 1;
	main->win.marker = 0;
	main->sph[0].center_sph = ft_vec(0, 0, -10);
	main->sph[0].radius = 5.0;
	main->sph[0].col = ft_vec(255, 0, 0);
	ft_tracing_sphere(main);
	mlx_put_image_to_window(main->win.mlx, main->win.win, main->win.img, 0, 0);
	free(main->sph);
}
