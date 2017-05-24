/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_primitives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:05:34 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:05:46 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_intersect(t_main *main, t_vec dir)
{
	if (main->type == 0)
		ft_light_sph(main, dir);
	else if (main->type == 1)
		ft_light_plane(main, dir);
	else if (main->type == 2)
		ft_light_cyl(main, dir);
	else if (main->type == 3)
		ft_light_cone(main, dir);
	return (main->type);
}

void	ft_for_each_obj(t_main *main, t_vec dir, t_vec pos)
{
	int i;

	i = -1;
	while (++i < main->mem.sph && main->flag.sph == 0)
		ft_intersect_sph(main, dir, pos, i);
	i = -1;
	while (++i < main->mem.plane && main->flag.plane == 0)
		ft_plane_intersect(main, dir, pos, i);
	i = -1;
	while (++i < main->mem.cyl && main->flag.cyl == 0)
		ft_cyl_intersect(main, dir, pos, i);
	i = -1;
	while (++i < main->mem.cone && main->flag.cone == 0)
		ft_cone_intersect(main, dir, pos, i);
}

int		ft_type_and_color(t_main *main, t_vec dir)
{
	int color;

	color = 0;
	if (ft_intersect(main, dir) == 0 && main->flag.sph == 0)
		color = ft_color(main, main->sph[main->index].col);
	else if (ft_intersect(main, dir) == 1 && main->flag.plane == 0)
		color = ft_color(main, main->plane[main->index].col);
	else if (ft_intersect(main, dir) == 2 && main->flag.cyl == 0)
		color = ft_color(main, main->cyl[main->index].col);
	else if (ft_intersect(main, dir) == 3 && main->flag.cone == 0)
		color = ft_color(main, main->cone[main->index].col);
	return (color);
}

void	ft_tracing(t_main *main)
{
	t_vec	pix;
	t_vec	dir;
	int		x;
	int		y;
	int		color;

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
			ft_for_each_obj(main, dir, main->cam_tmp);
			ft_compare_all(main);
			color = ft_type_and_color(main, dir);
			ft_color_pixel(main, x, y, color);
		}
	}
}

void	ft_scene(t_main *main)
{
	main->mem.sph = 2;
	main->mem.plane = 2;
	main->mem.cyl = 1;
	main->mem.cone = 1;
	main->flag.color = 0;
	main->win.marker = 4;
	main->win.img = mlx_new_image(main->win.mlx, WIDTH, HEIGHT);
	main->win.data = mlx_get_data_addr(main->win.img, &main->win.bpp,
									&main->win.size_l, &main->win.endian);
	ft_check(main);
	ft_tracing(main);
	mlx_put_image_to_window(main->win.mlx, main->win.win, main->win.img, 0, 0);
	free(main->sph);
	free(main->plane);
	free(main->cyl);
	free(main->cone);
}
