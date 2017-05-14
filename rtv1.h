/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:04:03 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/27 14:51:34 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include "./libft/libft.h"
# define FOV 45 * M_PI / 180
# define HEIGHT 800
# define WIDTH 1000
# define A_RATIO WIDTH / HEIGHT
# define AMB 0.2
# define DIFF 0.5
# define SPEC 0.3
# define POW  50
# define ANGLE 20 * M_PI / 180

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_win;

typedef struct		s_vec
{
	double 			x;
	double 			y;
	double 			z;
}					t_vec;

typedef struct		s_intersect
{
	double 			t[4];
	double 			t1; // ???
	double 			t2; // ????
	double 			a;
	double 			b;
	double 			c;
	double 			disc[4];
	t_vec			diff; // ?????????
}					t_intersect;

typedef struct		s_cam
{
	t_vec			c_position;
}					t_cam;

typedef struct		s_ray
{
	t_vec			p;
	t_vec			l;
	t_vec			n;
	t_vec			h;
}					t_ray;

typedef struct		s_light
{
	t_vec			l_position;
	t_vec			l_color;
}					t_light;

typedef struct		s_plane
{
	t_vec			n;
	t_vec			point;
	t_vec			col;
}					t_plane;

typedef struct		s_sphere
{
	t_vec			center_sph;
	t_vec			col;
	double 			radius;
}					t_sphere;

typedef struct		s_cylinder
{
	t_vec			center_cyl;
	t_vec			dir;
	double 			radius;
	t_vec			col;
}					t_cylinder;

typedef struct		s_cone
{
	t_vec			center_cone;
	t_vec			dir;
	t_vec			col;
}					t_cone;

typedef struct		s_main
{
	t_sphere		sph;
	t_plane			plane;
	t_cylinder		cyl;
	t_cone			cone;
	t_win			win;
	t_cam			cam;
	t_intersect		inter;
	t_light			*light;
	t_ray			*ray;
	double 			tmp;
	int 			num;
}					t_main;

typedef struct		s_disc
{
	double			a;
	double			b;
	double			c;
	double 			disc;
}					t_disc;

t_vec	ft_vec(double a, double b, double c);
double	ft_dot_prod(t_vec vec, t_vec vec1);
t_vec	ft_diff(t_vec vec, t_vec vec1);
t_vec	ft_negative(t_vec vec);
t_vec	ft_cross_prod(t_vec vec, t_vec vec1);
t_vec	ft_normalize(t_vec vec);
t_vec	ft_mult(t_vec vec, double a);
t_vec	ft_add(t_vec vec, t_vec vec1);
int 	ft_press_key(int keycode, void	*params);
void	ft_scene_param(t_main *main, int num);
int		ft_color(t_main *main, t_vec col);
void	ft_plane(t_main *main);
void	ft_cylinder(t_main *main);
void	ft_cone(t_main *main);
void	ft_scene(t_main *main);
void	ft_sphere(t_main *main);
int 	ft_press_key(int keycode, void	*params);

void	ft_tracing_sphere(t_main *main);
void	ft_tracing_plane(t_main *main);
void	ft_tracing_cylinder(t_main *main);
void	ft_tracing_cone(t_main *main);

double	ft_disc_sph(t_main *main, t_vec dir, t_vec pos);
double	ft_disc_cyl(t_main *main, t_vec dir, t_vec pos);
double	ft_disc_cone(t_main *main, t_vec dir, t_vec pos);

double	ft_intersect_sph(t_main *main, t_vec dir, t_vec pos);
double	ft_plane_intersect(t_main *main, t_vec dir, t_vec pos);
double	ft_cyl_intersect(t_main *main, t_vec dir, t_vec pos);
double	ft_cone_intersect(t_main *main, t_vec dir, t_vec pos);

void	ft_light_sph(t_main *main, t_vec dir);
void	ft_light_plane(t_main *main, t_vec dir);
void	ft_light_cyl(t_main *main, t_vec dir);
void	ft_light_cone(t_main *main, t_vec dir);

int	ft_shadow(t_main *main, double red, double green, double blue);


#endif
