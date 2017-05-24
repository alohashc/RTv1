/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:35:21 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 19:45:44 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_color_pixel(t_main *main, int x, int y, int color)
{
	*((int *)(main->win.data + x * main->win.bpp /
			8 + y * main->win.size_l)) = color;
}

int		ft_exit_cross(t_main *main)
{
	if (main)
		exit(0);
	return (0);
}

void	ft_rot_event(t_main *main, int keycode, int marker)
{
	keycode == 0 ? main->matrix.angle_y -= ROT_Y : 0;
	keycode == 2 ? main->matrix.angle_y += ROT_Y : 0;
	keycode == 13 ? main->matrix.angle_x -= ROT_X : 0;
	keycode == 1 ? main->matrix.angle_x += ROT_X : 0;
	keycode == 12 ? main->matrix.angle_z -= ROT_Z : 0;
	keycode == 14 ? main->matrix.angle_z += ROT_Z : 0;
	mlx_destroy_image(main->win.mlx, main->win.img);
	mlx_clear_window(main->win.mlx, main->win.win);
	main->cam_tmp = main->cam.c_position;
	ft_mat(main);
	main->cam_tmp = ft_m_mult_vec(main, main->cam_tmp);
	if (marker == 0)
		ft_sphere(main);
	if (marker == 1)
		ft_plane(main);
	if (marker == 2)
		ft_cylinder(main);
	if (marker == 3)
		ft_cone(main);
	if (marker == 4)
		ft_scene(main);
}

int		ft_press_key(int keycode, t_main *main)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 2 || keycode == 0)
		ft_rot_event(main, keycode, main->win.marker);
	if (keycode == 1 || keycode == 13)
		ft_rot_event(main, keycode, main->win.marker);
	if (keycode == 12 || keycode == 14)
		ft_rot_event(main, keycode, main->win.marker);
	return (0);
}
