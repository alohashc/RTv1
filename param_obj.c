//
// Created by Andrii Lohashchuk on 5/14/17.
//

#include "rtv1.h"

void	ft_param_sph(t_main *main)
{
	main->sph[0].center_sph = ft_vec(4, 0, -11);
	main->sph[0].radius = 5;
	main->sph[0].col = ft_vec(255, 0, 0);
	main->sph[1].center_sph = ft_vec(0, 0, -6);
	main->sph[1].radius = 5;
	main->sph[1].col = ft_vec(255, 0, 0);
}

void	ft_param_plane(t_main *main)
{
	main->plane[0].point = ft_vec(0, -5, -16);
	main->plane[0].n = ft_normalize(ft_vec(0, -1, 0));
	main->plane[0].col = ft_vec(100, 100, 100);
	main->plane[1].point = ft_vec(0, -1, -16);
	main->plane[1].n = ft_normalize(ft_vec(0, 0, 1));
	main->plane[1].col = ft_vec(100, 100, 100);
}

void	ft_param_cyl(t_main *main)
{
	main->cyl[0].radius = 2.0;
	main->cyl[0].center_cyl = ft_vec(15, 0, -1);
	main->cyl[0].dir = ft_normalize(ft_vec(0, 1, 0));
	main->cyl[0].col = ft_vec(0, 255, 0);
}

void	ft_param_cone(t_main *main)
{
	main->cone[0].center_cone = ft_vec(-15, 0, -5);
	main->cone[0].dir = ft_normalize(ft_vec(0, 1, 0));
	main->cone[0].col = ft_vec(0, 0, 255);
}

void	ft_check(t_main *main)
{
	main->flag.sph = 0;
	main->flag.plane = 0;
	main->flag.cyl = 0;
	main->flag.cone = 0;
	if (!main->mem.sph)
		main->flag.sph = 1;
	if (!main->mem.plane)
		main->flag.plane = 1;
	if (!main->mem.cyl)
		main->flag.cyl = 1;
	if (!main->mem.cone)
		main->flag.cone = 1;
}