//
// Created by Andrii Lohashchuk on 5/13/17.
//

#include "rtv1.h"

int 	ft_press_key(int keycode, t_main *main)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 0)
		main->angle += ROT;
	else if (keycode == 2)
		main->angle -= ROT;
	ft_mat(main);
	main->cam_tmp = ft_m_mult_vec(main, main->cam.c_position);
//	main->cam_tmp = main->cam.c_position;
	ft_scene(main);
	return (0);
}