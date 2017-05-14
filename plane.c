//
// Created by Andrii Lohashchuk on 4/21/17.
//

#include "rtv1.h"

void	ft_light_plane(t_main *main, t_vec dir)
{
	int i;

	i = 0;
	while (i < main->num)
	{
		main->ray[i].p = ft_add(main->cam.c_position,
							 ft_mult(dir, main->inter.t[1]));
		main->ray[i].n = main->plane.n;
		if (ft_dot_prod(main->ray[i].n, main->ray[i].l) < 0)
			main->ray[i].n = ft_negative(main->ray[i].n);
		main->ray[i].l = ft_diff(main->light[i].l_position, main->ray[i].p);
		main->ray[i].l = ft_normalize(main->ray[i].l);
		main->ray[i].h = ft_diff(main->ray[i].l, dir);
		main->ray[i].h = ft_normalize(main->ray[i].h);
		i++;
	}
}

double	ft_plane_intersect(t_main *main, t_vec dir, t_vec pos)
{
	double	den;
	double 	ch;
	double 	tmp;

	main->inter.t[1] = 0;
	den = ft_dot_prod(main->plane.n, dir);
	ch = ft_dot_prod(main->plane.n, ft_diff(main->plane.point, pos));
	tmp = ch / den;
	if (den != 0 && ch != 0 && tmp > 0)
		main->inter.t[1] = tmp;
	return (main->inter.t[1]);
}

void	ft_tracing_plane(t_main *main)
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
			if (ft_plane_intersect(main, dir, main->cam.c_position) != 0)
			{
				ft_light_plane(main, dir);
				mlx_pixel_put(main->win.mlx, main->win.win, x, y, ft_color(main, main->plane.col));
			}
			x++;
		}
		y++;
	}
}

void	ft_plane(t_main *main)
{
	main->plane.point = ft_vec(0, -1, -35);
	main->plane.n = ft_normalize(ft_vec(0, 0, 1));
	main->plane.col = ft_vec(255, 255, 0);
	ft_tracing_plane(main);
	mlx_key_hook(main->win.win, ft_press_key, &main->win);
	mlx_loop(main->win.mlx);
}