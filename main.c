//
// Created by Andrii Lohashchuk on 4/6/17.
//

#include "rtv1.h"

void	ft_scene_param(t_main *main, int num)
{
	main->num = num;
	main->light = (t_light*)malloc(sizeof(t_light) * num);
	main->ray = (t_ray*)malloc(sizeof(t_ray) * num);
	main->cam.c_position = ft_vec(0, 0, 50);
	main->light[0].l_position = ft_vec(10, 5, 0);
	main->light[0].l_color = ft_vec(100, 100, 100);
	main->light[1].l_position = ft_vec(-10, 5, 0);
	main->light[1].l_color = ft_vec(100, 100, 100);
}

void	ft_cmp(char *av, t_win *win)
{
	if (ft_strcmp(av, "Sphere") == 0)
		win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "Sphere");
	else if (ft_strcmp(av, "Plane") == 0)
		win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "Plane");
	else if (ft_strcmp(av, "Cyl") == 0)
		win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "Cyl");
	else if (ft_strcmp(av, "Cone") == 0)
		win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "Cone");
	else if (ft_strcmp(av, "Scene") == 0)
		win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "Scene");
}

void	ft_window(int ac, char **av, t_main *main)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		ft_cmp(av[i], &main->win);
		if (ft_strcmp(av[i], "Sphere") == 0)
			ft_sphere(main);
		else if (ft_strcmp(av[i], "Plane") == 0)
			ft_plane(main);
		else if (ft_strcmp(av[i], "Cylinder") == 0)
			ft_cylinder(main);
		else if (ft_strcmp(av[i], "Cone") == 0)
			ft_cone(main);
		else if (ft_strcmp(av[i], "Scene") == 0)
			ft_scene(main);
	}
}

int main(int ac, char **av)
{
	t_main main;

	main.win.mlx = mlx_init();
	if (ac >= 2)
	{
		ft_scene_param(&main, 2);
		ft_window(ac, av, &main);
	}
	return (0);
}