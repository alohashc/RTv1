/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:04:03 by alohashc          #+#    #+#             */
/*   Updated: 2017/05/21 20:00:55 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "./libft/libft.h"
# define FOV 45 * M_PI / 180
# define HEIGHT 800
# define WIDTH 1000
# define RATIO WIDTH / HEIGHT
# define AMB 0.2
# define DIFF 0.5
# define SPEC 0.3
# define POW  100
# define ANGLE 20 * M_PI / 180
# define ROT_X 10 * M_PI / 180
# define ROT_Y 10 * M_PI / 180
# define ROT_Z 10 * M_PI / 180

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			marker;
}				t_win;

typedef struct	s_matrix
{
	double		m[4][4];
}				t_matrix;

typedef struct	s_matrices
{
	t_matrix	m_x;
	t_matrix	m_y;
	t_matrix	m_z;
	t_matrix	m_res;
	double		angle_x;
	double		angle_y;
	double		angle_z;
}				t_matrices;

typedef struct	s_mem
{
	int			sph;
	int			plane;
	int			cyl;
	int			cone;
}				t_mem;

typedef struct	s_flag
{
	int			sph;
	int			plane;
	int			cyl;
	int			cone;
	int			color;
}				t_flag;

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_intersect
{
	double		t;
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vec		diff;
}				t_intersect;

typedef struct	s_cam
{
	t_vec		c_position;
}				t_cam;

typedef struct	s_ray
{
	t_vec		p;
	t_vec		l;
	t_vec		n;
	t_vec		h;
}				t_ray;

typedef struct	s_light
{
	t_vec		l_pos;
	t_vec		l_color;
	double		*t_shadow;
}				t_light;

typedef struct	s_plane
{
	t_vec		n;
	t_vec		point;
	t_vec		col;
	t_intersect	inter;
}				t_plane;

typedef struct	s_sphere
{
	t_vec		center_sph;
	t_vec		col;
	double		radius;
	t_intersect	inter;
}				t_sphere;

typedef struct	s_cylinder
{
	t_vec		center_cyl;
	t_vec		dir;
	double		radius;
	t_vec		col;
	t_intersect	inter;
}				t_cylinder;

typedef struct	s_cone
{
	t_vec		center_cone;
	t_vec		dir;
	t_vec		col;
	t_intersect	inter;
}				t_cone;

typedef struct	s_main
{
	t_sphere	*sph;
	t_plane		*plane;
	t_cylinder	*cyl;
	t_cone		*cone;
	t_win		win;
	t_cam		cam;
	t_intersect	inter;
	t_light		*light;
	t_ray		*ray;
	t_mem		mem;
	t_flag		flag;
	t_matrices	matrix;
	double		tmp;
	int			num;
	int			type;
	int			index;
	t_vec		cam_tmp;
}				t_main;

typedef struct	s_disc
{
	double		a;
	double		b;
	double		c;
	double		disc;
}				t_disc;

/*
** vec functions
*/

t_vec			ft_vec(double a, double b, double c);
double			ft_dot_prod(t_vec vec, t_vec vec1);
t_vec			ft_diff(t_vec vec, t_vec vec1);
t_vec			ft_negative(t_vec vec);
t_vec			ft_cross_prod(t_vec vec, t_vec vec1);
t_vec			ft_norm(t_vec vec);
double			ft_len(t_vec vec);
t_vec			ft_mult(t_vec vec, double a);
t_vec			ft_add(t_vec vec, t_vec vec1);

/*
** other functions
*/

int				ft_exit_cross(t_main *main);
int				ft_press_key(int keycode, t_main *main);
void			ft_scene_param(t_main *main, int num);

/*
** obj functions
*/

void			ft_plane(t_main *main);
void			ft_cylinder(t_main *main);
void			ft_cone(t_main *main);
void			ft_scene(t_main *main);
void			ft_sphere(t_main *main);

/*
** tracing functions
*/

void			ft_tracing_sphere(t_main *main);
void			ft_tracing_plane(t_main *main);
void			ft_tracing_cylinder(t_main *main);
void			ft_tracing_cone(t_main *main);

/*
** disc
*/

double			ft_disc_sph(t_main *main, t_vec dir, t_vec pos, int i);
double			ft_disc_cyl(t_main *main, t_vec dir, t_vec pos, int i);
double			ft_disc_cone(t_main *main, t_vec dir, t_vec pos, int i);

/*
** intersect
*/

double			ft_intersect_sph(t_main *main, t_vec dir, t_vec pos, int i);
double			ft_plane_intersect(t_main *main, t_vec dir, t_vec pos, int i);
double			ft_cyl_intersect(t_main *main, t_vec dir, t_vec pos, int i);
double			ft_cone_intersect(t_main *main, t_vec dir, t_vec pos, int i);

/*
** light
*/

void			ft_light_sph(t_main *main, t_vec dir);
void			ft_light_plane(t_main *main, t_vec dir);
void			ft_light_cyl(t_main *main, t_vec dir);
void			ft_light_cone(t_main *main, t_vec dir);

/*
** shadow and color
*/

void			ft_color_pixel(t_main *main, int x, int y, int color);
int				ft_color(t_main *main, t_vec col);
int				ft_shadow(t_main *main, double red, double green, double blue);

/*
** all primitives functions
*/

void			ft_compare_all(t_main *main);
void			ft_for_each_obj(t_main *main, t_vec dir, t_vec pos);

/*
** params obj
*/

void			ft_param_sph(t_main *main);
void			ft_param_plane(t_main *main);
void			ft_param_cyl(t_main *main);
void			ft_param_cone(t_main *main);
void			ft_check(t_main *main);

/*
** matrices functions
*/

void			ft_mat(t_main *main);
t_vec			ft_m_mult_vec(t_main *main, t_vec vec);

#endif
