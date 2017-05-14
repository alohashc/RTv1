//
// Created by Andrii Lohashchuk on 4/26/17.
//

#include "rtv1.h"

int	ft_shadow(t_main *main, double red, double green, double blue)
{
	int		final;
	int		i;
	int 	j;
	double	len;
	t_vec	light;

	i = 0;
	final = 0;
	while (i < main->num)
	{
		main->ray[i].p = ft_add(main->ray[i].p, ft_mult(main->ray[i].n, 0.0001));
		main->ray[i].l = ft_diff(main->light[i].l_position, main->ray[i].p);
		main->ray[i].l = ft_normalize(main->ray[i].l);
		ft_intersect_sph(main, main->ray[i].l, main->ray[i].p);
		ft_plane_intersect(main, main->ray[i].l, main->ray[i].p);
		ft_cyl_intersect(main, main->ray[i].l, main->ray[i].p);
		ft_cone_intersect(main, main->ray[i].l, main->ray[i].p);
		light = ft_diff(main->light[i].l_position, main->ray[i].p);
		len = sqrt(ft_dot_prod(light, light));
		j = 0;
		while (j < 3)
		{
			if (main->inter.t[j] != 0 && main->inter.t[j] < len)
			{
				red *= 0.8;
				green *= 0.8;
				blue *= 0.8;
				break;
			}
			j++;
		}
		final = ((int)fmin(255, red) << 16) + ((int)fmin(255, green) << 8) +
				 										((int)fmin(255, blue));
		i++;
	}
	return (final);
}

void ft_param_obj(t_main *main)
{
	main->sph.center_sph = ft_vec(0, 0, -10);
	main->sph.radius = 5;
	main->sph.col = ft_vec(255, 0, 0);
	main->plane.point = ft_vec(0, -1, -16);
	main->plane.n = ft_normalize(ft_vec(0, 0, 1));
	main->plane.col = ft_vec(255, 255, 0);
	main->cyl.radius = 2.0;
	main->cyl.center_cyl = ft_vec(10, 0, -10);
	main->cyl.dir = ft_normalize(ft_vec(0, 1, 0));
	main->cyl.col = ft_vec(0, 255, 0);
	main->cone.center_cone = ft_vec(10, 0, -5);
	main->cone.dir = ft_normalize(ft_vec(0, 1, 0));
	main->cone.col = ft_vec(0, 0, 255);
}

void	ft_tracing(t_main *main)
{
	t_vec	pix;
	t_vec	dir;
	int 	x;
	int 	y;
	int 	i;
	int 	index;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			index = -1;
			pix.x = (2 * ((x + 0.5) / WIDTH) - 1) * A_RATIO * tan(FOV / 2);
			pix.y = (1 - 2 * ((y + 0.5) / HEIGHT)) * tan(FOV / 2);
			pix.z = main->cam.c_position.z - 1;
			dir = ft_normalize(ft_diff(pix, main->cam.c_position));
			ft_intersect_sph(main, dir, main->cam.c_position);
			ft_plane_intersect(main, dir, main->cam.c_position);
			ft_cyl_intersect(main, dir, main->cam.c_position);
			ft_cone_intersect(main, dir, main->cam.c_position);
			main->tmp = fmax(fmax(main->inter.t[0], main->inter.t[1]), fmax(main->inter.t[2], main->inter.t[3]));
			i = 0;
			while (i < 3)
			{
				if (main->inter.t[i] <= main->tmp && main->inter.t[i] != 0)
				{
					main->tmp = main->inter.t[i];
					index = i;
				}
				i++;
			}
			if (index == 0 && main->inter.disc[0] >= 0)
			{
				ft_light_sph(main, dir);
				mlx_pixel_put(main->win.mlx, main->win.win, x, y, ft_color(main, main->sph.col));
			}
			else if (index == 1)
			{
				ft_light_plane(main, dir);
				mlx_pixel_put(main->win.mlx, main->win.win, x, y, ft_color(main, main->plane.col));
			}
			else if (index == 2 && main->inter.disc[2] >= 0)
			{
				ft_light_cyl(main, dir);
				mlx_pixel_put(main->win.mlx, main->win.win, x, y, ft_color(main, main->cyl.col));
			}
			else if (index == 3 && main->inter.disc[3] >= 0)
			{
				ft_light_cone(main, dir);
				mlx_pixel_put(main->win.mlx, main->win.win, x, y, ft_color(main, main->cone.col));
			}
		}
	}
}

void	ft_scene(t_main *main)
{
	ft_param_obj(main);
	ft_tracing(main);
	mlx_key_hook(main->win.win, ft_press_key, &main->win);
	mlx_loop(main->win.mlx);
}