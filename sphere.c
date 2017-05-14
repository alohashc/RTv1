//
// Created by Andrii Lohashchuk on 4/11/17.
//
#include "rtv1.h"

int 	ft_press_key(int keycode, void	*params)
{
	if (keycode == 53 && params)
		exit(0);
	return (0);
}


int	ft_color(t_main *main, t_vec col)
{
	double 			red;
	double 			green;
	double 			blue;

	int 			final;
	int 			i;

	i = 0;
	blue = 0;
	green = 0;
	red = 0;
	while (i < main->num)
	{
		red += (col.x * (AMB + DIFF * ft_dot_prod(main->ray[i].n, main->ray[i].l)) +
			   main->light[i].l_color.x * SPEC * pow(ft_dot_prod(main->ray[i].n, main->ray[i].h), POW));
		green += (col.y * (AMB + DIFF * ft_dot_prod(main->ray[i].n, main->ray[i].l)) +
				 main->light[i].l_color.y * SPEC * pow(ft_dot_prod(main->ray[i].n, main->ray[i].h), POW));
		blue += (col.z * (AMB + DIFF * ft_dot_prod(main->ray[i].n, main->ray[i].l)) +
				main->light[i].l_color.z * SPEC * pow(ft_dot_prod(main->ray[i].n, main->ray[i].h), POW));
		i++;
	}
	red = fmin(255, red);
	green = fmin(255, green);
	blue = fmin(255, blue);
	final = ft_shadow(main, red, green, blue);
	return (final);
}

void	ft_light_sph(t_main *main, t_vec dir)
{
	int i;

	i = 0;
	while (i < main->num)
	{
		main->ray[i].p = ft_add(main->cam.c_position,
							 ft_mult(dir, main->inter.t[0]));
		main->ray[i].n = ft_diff(main->ray[i].p, main->sph.center_sph);
		main->ray[i].n = ft_normalize(main->ray[i].n);
		main->ray[i].l = ft_diff(main->light[i].l_position, main->ray[i].p);
		main->ray[i].l = ft_normalize(main->ray[i].l);
		main->ray[i].h = ft_diff(main->ray[i].l, dir);
		main->ray[i].h = ft_normalize(main->ray[i].h);
		i++;
	}
}

double ft_intersect_sph(t_main *main, t_vec dir, t_vec pos)
{
	double 	disc;
	
	main->inter.disc[0] = ft_disc_sph(main, dir, pos);
	disc = main->inter.disc[0];
	main->inter.t[0] = 0;
	if (disc >= 0)
	{
		main->inter.t1 = (-main->inter.b + sqrt(disc)) / 2 / main->inter.a;
		main->inter.t2 = (-main->inter.b - sqrt(disc)) / 2 / main->inter.a;
		if (main->inter.t1 > 0 || main->inter.t2 > 0)
		{
			if (main->inter.t1 < 0 || main->inter.t2 < 0)
				main->inter.t[0] = fmax(main->inter.t1, main->inter.t2);
			else
				main->inter.t[0] = fmin(main->inter.t1, main->inter.t2);
		}
	}
	return (main->inter.t[0]);
}

double	ft_disc_sph(t_main *main, t_vec dir, t_vec pos)
{
	t_disc dis;
	double 	radius;
	t_vec	tmp;

	tmp = pos;
	radius = main->sph.radius;
	main->inter.diff = ft_diff(tmp, main->sph.center_sph);
	dis.a = ft_dot_prod(dir, dir);
	dis.b = 2 * ft_dot_prod(dir, main->inter.diff);
	dis.c = ft_dot_prod(main->inter.diff, main->inter.diff) - radius * radius;
	dis.disc = dis.b * dis.b - 4 * dis.a * dis.c;
	main->inter.a = dis.a;
	main->inter.b = dis.b;
	main->inter.c = dis.c;
	return (dis.disc);
}


void	ft_tracing_sphere(t_main *main)
{
	t_vec	pix;
	t_vec	dir;
	int 	x;
	int		y;

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
			if(ft_intersect_sph(main, dir, main->cam.c_position) != 0)
			{
				ft_light_sph(main, dir);
				mlx_pixel_put(main->win.mlx, main->win.win, x, y, ft_color(main, main->sph.col));
			}
			x++;
		}
		y++;
	}
}

void	ft_sphere(t_main *main)
{
	main->sph.center_sph = ft_vec(0, 0, -10);
	main->sph.radius = 10.0;
	main->sph.col= ft_vec(255, 0, 0);
	ft_tracing_sphere(main);
	mlx_key_hook(main->win.win, ft_press_key, &main->win);
	mlx_loop(main->win.mlx);
}