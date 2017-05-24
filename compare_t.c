/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:15:28 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 16:15:32 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_compare_sph_t(t_main *main)
{
	int		i;

	i = 0;
	while (i < main->mem.sph)
	{
		if (main->sph[i].inter.t <= main->tmp && main->sph[i].inter.t != 0)
		{
			main->tmp = main->sph[i].inter.t;
			main->index = i;
			main->type = 0;
		}
		i++;
	}
}

void	ft_compare_plane_t(t_main *main)
{
	int		i;

	i = 0;
	while (i < main->mem.plane)
	{
		if (main->plane[i].inter.t <= main->tmp && main->plane[i].inter.t != 0)
		{
			main->tmp = main->plane[i].inter.t;
			main->index = i;
			main->type = 1;
		}
		i++;
	}
}

void	ft_compare_cyl_t(t_main *main)
{
	int		i;

	i = 0;
	while (i < main->mem.cyl)
	{
		if (main->cyl[i].inter.t <= main->tmp && main->cyl[i].inter.t != 0)
		{
			main->tmp = main->cyl[i].inter.t;
			main->index = i;
			main->type = 2;
		}
		i++;
	}
}

void	ft_compare_cone_t(t_main *main)
{
	int		i;

	i = 0;
	while (i < main->mem.cone)
	{
		if (main->cone[i].inter.t <= main->tmp && main->cone[i].inter.t != 0)
		{
			main->tmp = main->cone[i].inter.t;
			main->index = i;
			main->type = 3;
		}
		i++;
	}
}

void	ft_compare_all(t_main *main)
{
	main->index = -1;
	main->tmp = 1000000;
	main->type = -1;
	if (main->flag.sph == 0)
		ft_compare_sph_t(main);
	if (main->flag.plane == 0)
		ft_compare_plane_t(main);
	if (main->flag.cyl == 0)
		ft_compare_cyl_t(main);
	if (main->flag.cone == 0)
		ft_compare_cone_t(main);
}
