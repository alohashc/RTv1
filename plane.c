/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:50:58 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:51:03 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_light_plane(t_main *main, t_vec dir)
{
	int i;

	i = 0;
	while (i < main->num)
	{
		main->ray[i].p = ft_add(main->cam_tmp,
							ft_mult(dir, main->plane[main->index].inter.t));
		main->ray[i].n = main->plane[main->index].n;
		if (ft_dot_prod(main->ray[i].n, main->ray[i].l) < 0)
			main->ray[i].n = ft_negative(main->ray[i].n);
		main->ray[i].l = ft_diff(main->light[i].l_pos, main->ray[i].p);
		main->ray[i].l = ft_norm(main->ray[i].l);
		main->ray[i].h = ft_diff(main->ray[i].l, dir);
		main->ray[i].h = ft_norm(main->ray[i].h);
		i++;
	}
}

double	ft_plane_intersect(t_main *main, t_vec dir, t_vec pos, int i)
{
	double	den;
	double	ch;
	double	tmp;

	main->plane[i].inter.t = 0;
	den = ft_dot_prod(main->plane[i].n, dir);
	ch = ft_dot_prod(main->plane[i].n, ft_diff(main->plane[i].point, pos));
	tmp = ch / den;
	if (den != 0 && ch != 0 && tmp > 0)
		main->plane[i].inter.t = tmp;
	return (main->plane[i].inter.t);
}

void	ft_tracing_plane(t_main *main)
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
			if (ft_plane_intersect(main, dir, main->cam_tmp, 0) != 0)
			{
				ft_light_plane(main, dir);
				ft_color_pixel(main, x, y, ft_color(main, main->plane[0].col));
			}
		}
	}
}

void	ft_plane(t_main *main)
{
	main->win.img = mlx_new_image(main->win.mlx, WIDTH, HEIGHT);
	main->win.data = mlx_get_data_addr(main->win.img, &main->win.bpp,
									&main->win.size_l, &main->win.endian);
	main->plane = (t_plane*)malloc(sizeof(t_plane) * 1);
	main->flag.color = 1;
	main->win.marker = 1;
	main->plane[0].point = ft_vec(0, -1, -35);
	main->plane[0].n = ft_norm(ft_vec(0, 0, 1));
	main->plane[0].col = ft_vec(255, 255, 0);
	ft_tracing_plane(main);
	mlx_put_image_to_window(main->win.mlx, main->win.win, main->win.img, 0, 0);
	free(main->plane);
}
