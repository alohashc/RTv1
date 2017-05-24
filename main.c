/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:42:07 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 19:44:03 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_usage(void)
{
	ft_putendl("\033\e[91musage: ./RTv1 <name primitives>");
	ft_putendl("\033\e[33m<Sphere>\n<Plane>\n<Cyl>\n<Cone>\n<Scene>");
	exit(0);
}

void	ft_scene_param(t_main *main, int num)
{
	main->num = num;
	main->light = (t_light*)malloc(sizeof(t_light) * num);
	main->ray = (t_ray*)malloc(sizeof(t_ray) * num);
	main->cam.c_position = ft_vec(0, 0, 50);
	main->cam_tmp = main->cam.c_position;
	ft_mat(main);
	main->cam_tmp = ft_m_mult_vec(main, main->cam_tmp);
	main->light[0].l_pos = ft_vec(10, 0, 50);
	main->light[0].l_color = ft_vec(100, 100, 100);
}

int		ft_cmp(char *av, t_main *main)
{
	if (ft_strcmp(av, "Sphere") == 0)
		main->win.win = mlx_new_window(main->win.mlx, WIDTH, HEIGHT, "Sphere");
	else if (ft_strcmp(av, "Plane") == 0)
		main->win.win = mlx_new_window(main->win.mlx, WIDTH, HEIGHT, "Plane");
	else if (ft_strcmp(av, "Cyl") == 0)
		main->win.win = mlx_new_window(main->win.mlx, WIDTH, HEIGHT, "Cyl");
	else if (ft_strcmp(av, "Cone") == 0)
		main->win.win = mlx_new_window(main->win.mlx, WIDTH, HEIGHT, "Cone");
	else if (ft_strcmp(av, "Scene") == 0)
		main->win.win = mlx_new_window(main->win.mlx, WIDTH, HEIGHT, "Scene");
	else
		return (0);
	ft_scene_param(main, 1);
	return (1);
}

void	ft_window(char *av, t_main *main)
{
	if (ft_strcmp(av, "Sphere") == 0)
		ft_sphere(main);
	else if (ft_strcmp(av, "Plane") == 0)
		ft_plane(main);
	else if (ft_strcmp(av, "Cyl") == 0)
		ft_cylinder(main);
	else if (ft_strcmp(av, "Cone") == 0)
		ft_cone(main);
	else if (ft_strcmp(av, "Scene") == 0)
		ft_scene(main);
	else
		ft_usage();
}

int		main(int ac, char **av)
{
	t_main main;

	main.win.mlx = mlx_init();
	main.matrix.angle_x = 0;
	main.matrix.angle_y = 0;
	main.matrix.angle_z = 0;
	if (ac == 2)
	{
		if (ft_cmp(av[1], &main) == 0)
			ft_usage();
		ft_window(av[1], &main);
		mlx_key_hook(main.win.win, ft_press_key, &main);
		mlx_hook(main.win.win, 17, 1L << 17, ft_exit_cross, &main);
		mlx_loop(main.win.mlx);
	}
	else
		ft_usage();
	return (0);
}
