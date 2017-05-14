//
// Created by Andrii Lohashchuk on 4/25/17.
//

#include "rtv1.h"

void	ft_light_cone(t_main *main , t_vec dir)
{
	double 	t;
	t_vec	tmp;
	t_vec	b;
	double	a;
	int		i;

	i = 0;
	while (i < main->num)
	{
		main->ray[i].p = ft_add(main->cam.c_position,
							 ft_mult(dir, main->inter.t[3]));
		tmp = ft_diff(main->ray[i].p, main->cone.center_cone);
		t = ft_dot_prod(ft_normalize(tmp), main->cone.dir);
		a = sqrt(ft_dot_prod(tmp, tmp)) / t;
		b = ft_mult(main->cone.dir, a);
		main->ray[i].n = ft_normalize(ft_diff(tmp, b));
		main->ray[i].l = ft_diff(main->light[i].l_position, main->ray[i].p);
		main->ray[i].l = ft_normalize(main->ray[i].l);
		dir = ft_normalize(dir);
		main->ray[i].h = ft_diff(main->ray[i].l, dir);
		main->ray[i].h = ft_normalize(main->ray[i].h);
		i++;
	}
}

double	ft_cone_intersect(t_main *main, t_vec dir, t_vec pos)
{
	double 	disc;


	main->inter.disc[3] = ft_disc_cone(main, dir, pos);
	disc = main->inter.disc[3];
	main->inter.t[3] = 0;
	if (disc >= 0)
	{
		main->inter.t1 = (-main->inter.b + sqrt(disc)) / 2 / main->inter.a;
		main->inter.t2 = (-main->inter.b - sqrt(disc)) / 2 / main->inter.a;
		if (main->inter.t1 > 0 || main->inter.t2 > 0)
		{
			if (main->inter.t1 < 0 || main->inter.t2 < 0)
				main->inter.t[3] = fmax(main->inter.t1, main->inter.t2);
			else
				main->inter.t[3] = fmin(main->inter.t1, main->inter.t2);
		}
	}
	return (main->inter.t[3]);
}

double	ft_disc_cone(t_main *main, t_vec dir, t_vec pos)
{
	t_disc dis;
	t_vec 	a;
	t_vec 	c;

	dir = ft_normalize(dir);
	main->inter.diff = ft_diff(pos, main->cone.center_cone);
	a = ft_diff(dir, ft_mult(main->cone.dir, ft_dot_prod(dir, main->cone.dir)));
	dis.a = pow(cos(ANGLE), 2) * ft_dot_prod(a, a) - pow(sin(ANGLE), 2) *
									pow(ft_dot_prod(dir, main->cone.dir), 2);
	c = ft_diff(main->inter.diff, ft_mult(main->cone.dir,
								ft_dot_prod(main->inter.diff, main->cone.dir)));
	dis.c = pow(cos(ANGLE), 2) * ft_dot_prod(c, c) - pow(sin(ANGLE), 2) *
						pow(ft_dot_prod(main->inter.diff, main->cone.dir), 2);
	dis.b = 2 * (pow(cos(ANGLE), 2) * ft_dot_prod(a, c) - pow(sin(ANGLE), 2) *
	ft_dot_prod(dir, main->cone.dir) * ft_dot_prod(main->inter.diff, main->cone.dir));
	main->inter.a = dis.a;
	main->inter.b = dis.b;
	main->inter.c = dis.c;
	dis.disc = dis.b * dis.b - 4 * dis.a * dis.c;
	return (dis.disc);
}


void	ft_tracing_cone(t_main *main)
{
	t_vec	pix;
	t_vec	dir;
	int 	x;
	int 	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pix.x = (2 * ((x + 0.5) / WIDTH) - 1) * A_RATIO * tan(FOV / 2);
			pix.y = (1 - 2 * ((y + 0.5) / HEIGHT)) * tan(FOV / 2);
			pix.z = main->cam.c_position.z - 1;
			dir = ft_normalize(ft_diff(pix, main->cam.c_position));
			if(ft_cone_intersect(main, dir, main->cam.c_position) != 0)
			{

				ft_light_cone(main , dir);
				mlx_pixel_put(main->win.mlx, main->win.win, x, y, ft_color(main, main->cone.col));
			}
			x++;
		}
		y++;
	}
}

void	ft_cone(t_main *main)
{
	main->cone.center_cone = ft_vec(0, 0, -10);
	main->cone.dir = ft_normalize(ft_vec(0, 1, 0));
	main->cone.col = ft_vec(100, 20, 50);
	ft_tracing_cone(main);
	mlx_key_hook(main->win.win, ft_press_key, &main->win);
	mlx_loop(main->win.mlx);
}