//
// Created by Andrii Lohashchuk on 4/26/17.
//

#include "rtv1.h"

int	ft_intersect(t_main *main, t_vec dir)
{
	int i;

	i = main->index;
	if (main->type == 0 && main->sph[i].inter.disc >= 0)
		ft_light_sph(main, dir);
	else if (main->type == 1)
		ft_light_plane(main, dir);
	else if (main->type == 2 && main->cyl[i].inter.disc >= 0)
		ft_light_cyl(main, dir);
	else if (main->type == 3 && main->cone[i].inter.disc >= 0)
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

int	ft_type_and_color(t_main *main, t_vec dir)
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
	int 	x;
	int 	y;
	int		color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pix.x = (2 * ((x + 0.5) / WIDTH) - 1) * A_RATIO * tan(FOV / 2);
			pix.y = (1 - 2 * ((y + 0.5) / HEIGHT)) * tan(FOV / 2);
			pix.z = main->cam.c_position.z - 1;
			dir = ft_normalize(ft_diff(pix, main->cam.c_position));
//			ft_mat(main);
			dir = ft_m_mult_vec(main, dir);
			ft_for_each_obj(main, dir, main->cam_tmp);
			ft_compare_all(main);
			color = ft_type_and_color(main, dir);
			mlx_pixel_put(main->win.mlx, main->win.win, x, y, color);
		}
	}
}

void	ft_scene(t_main *main)
{
	main->mem.sph = 2;
	main->mem.plane = 2;
	main->mem.cyl = 1;
	main->mem.cone = 0;
	main->flag.color = 0;
	ft_mat(main);
	main->cam_tmp = ft_m_mult_vec(main, main->cam_tmp);
	main->sph = (t_sphere *) malloc(sizeof(t_sphere) * main->mem.sph);
	main->plane = (t_plane*)malloc(sizeof(t_plane) * main->mem.plane);
	main->cyl = (t_cylinder*)malloc(sizeof(t_cylinder) * main->mem.cyl);
	main->cone = (t_cone*)malloc(sizeof(t_cone) * main->mem.cone);
	ft_check(main);
	if (main->flag.sph == 0)
		ft_param_sph(main);
	if (main->flag.plane == 0)
		ft_param_plane(main);
	if (main->flag.cyl == 0)
		ft_param_cyl(main);
	if (main->flag.cone == 0)
		ft_param_cone(main);
	ft_tracing(main);
	mlx_key_hook(main->win.win, ft_press_key, &main);
	mlx_loop(main->win.mlx);
}