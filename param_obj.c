/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:49:47 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:49:49 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_param_sph(t_main *main)
{
	main->sph[0].center_sph = ft_vec(0, 0, -10);
	main->sph[0].radius = 3;
	main->sph[0].col = ft_vec(255, 0, 0);
	main->sph[1].center_sph = ft_vec(7, 0, -3);
	main->sph[1].radius = 5;
	main->sph[1].col = ft_vec(255, 100, 0);
}

void	ft_param_plane(t_main *main)
{
	main->plane[0].point = ft_vec(0, -5, -16);
	main->plane[0].n = ft_norm(ft_vec(0, -1, 0));
	main->plane[0].col = ft_vec(100, 100, 100);
	main->plane[1].point = ft_vec(0, -1, -16);
	main->plane[1].n = ft_norm(ft_vec(0, 0, 1));
	main->plane[1].col = ft_vec(100, 100, 100);
}

void	ft_param_cyl(t_main *main)
{
	main->cyl[0].radius = 2.0;
	main->cyl[0].center_cyl = ft_vec(15, 0, -1);
	main->cyl[0].dir = ft_norm(ft_vec(0, 1, 0));
	main->cyl[0].col = ft_vec(0, 100, 100);
}

void	ft_param_cone(t_main *main)
{
	main->cone[0].center_cone = ft_vec(-15, 0, -5);
	main->cone[0].dir = ft_norm(ft_vec(1, 1, 0));
	main->cone[0].col = ft_vec(100, 20, 50);
}

void	ft_check(t_main *main)
{
	main->sph = (t_sphere*)malloc(sizeof(t_sphere) * main->mem.sph);
	main->plane = (t_plane*)malloc(sizeof(t_plane) * main->mem.plane);
	main->cyl = (t_cylinder*)malloc(sizeof(t_cylinder) * main->mem.cyl);
	main->cone = (t_cone*)malloc(sizeof(t_cone) * main->mem.cone);
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
	main->flag.sph == 0 ? ft_param_sph(main) : 0;
	main->flag.plane == 0 ? ft_param_plane(main) : 0;
	main->flag.cyl == 0 ? ft_param_cyl(main) : 0;
	main->flag.cone == 0 ? ft_param_cone(main) : 0;
}
