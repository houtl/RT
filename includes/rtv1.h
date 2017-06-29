/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:50:30 by thou              #+#    #+#             */
/*   Updated: 2017/05/29 15:48:37 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include "mlx_key.h"

# define WHITE		0xFFFFFF
# define BLUE		0x0901F7
# define BLUE_C		0x015BF7
# define SKY		0x01B5F7
# define LAGON		0x33AB9B
# define WGREEN		0x01F79D
# define RAZER		0x01F74B
# define LIMON		0xADF701
# define YELLOW		0xEFF701
# define ORANGE		0xF78C01
# define RED		0xFE4D01

# define LIGHT		1
# define PLANE		2
# define CYLINDER	3
# define CONE		4
# define SPHERE		5

# define RGB(r, g, b)(256 * 256 * (int)r + 256 * (int)g + (int)b)
# define SAFEMALL(x) if (!x) return (NULL);
# define SAFEMALL0(x) if (!x) return (0);
# define MAX_LIGHT	10

# define TRUE		1
# define FALSE		0
# define FOC		2.0
# define WIDTH		500
# define HEIGHT		500

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_matrix
{
	double m[4][4];
}						t_matrix;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_cam
{
	t_vector			pos;
	t_vector			dir;
	t_vector			lookat;
	t_vector			normal;
	t_vector			right;
	t_vector			up;
}						t_cam;

typedef struct			s_ray
{
	t_vector			pos;
	t_vector			dir;
}						t_ray;

typedef struct			s_solver
{
	t_vector			dist;
	double				a;
	double				b;
	double				c;
	double				delta;
	double				t1;
	double				t2;
}						t_solver;

typedef struct			s_light
{
	t_vector			pos;
	t_color				col;
	struct s_light		*next;
}						t_light;

typedef struct			s_obj
{
	int					name;
	t_vector			pos;
	t_color				color;
	t_vector			rot;
	double				size;
	double				ambient;
	double				diffuse;
	double				specular;
	int					current;
}						t_obj;

typedef struct			s_img
{
	int					endian;
	int					size_line;
	char				*img_ptr;
	int					bpp;
}						t_img;

typedef struct			s_hit
{
	t_ray				*ray_origin;
	t_vector			point;
	t_vector			normal;
	t_color				color;
	double				t;
}						t_hit;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					sl;
	int					endian;
	int					bpp;
}						t_mlx;

typedef struct			s_env
{
	t_mlx				mlx;
	t_cam				cam;
	t_obj				*obj;
	t_vector			n;
	t_vector			r;
	t_vector			up;
	double				aa;
	double				t;
	double				p;
	char				*itoapos;
	char				*itoasize;
	char				*itoarot;
	char				*itoacampos;
	char				*itoacamdir;
	char				**tab;
	t_obj				*hit_obj;
	int					is_obj_selected;
	t_obj				*light[MAX_LIGHT];
	int					l;
	int					total_light;
	int					help;
}						t_env;

/*
**			main.c
*/

int						err_exit(char *str);

/*
**			closest_t.c
*/

double					find_closest_t(t_list *list,
							t_ray *ray, t_obj **hit_obj);

/*
**			color.c
*/

t_color					lighting(t_list *lst, t_obj **obj, t_ray ray, double t);

/*
**			copy.c
*/

void					copy_cam(t_cam *dst, t_cam src);
int						copy_list(t_list **dst, t_list *src);
void					copy_up(t_vector *dst, t_vector src);

/*
**			display_cam_info.c
*/

void					display_cam_info(t_env *e);

/*
**			display_obj_info.c
*/

void					ft_put_info(t_env *e);
void					display_info(t_env *e);
int						clicked_obj_info(int x, int y, t_env *e);

/*
**			draw.c
*/

void					pixel_put(int x, int y, t_color col, t_mlx *mlx);

/*
**			file_to_obj.c
*/

int						ft_a_atoi(const char *str, int *i);
int						parser_obj(t_list **obj, const char **tab, int i);

/*
**			ft_atof.c
*/

double					ft_atof(const char *nb, int *i);

/*
**			get.c
*/

int						get_colpos(t_obj *obj, const char **tab, int *i);
int						get_size(t_obj *obj, const char **tab, int *i);
int						get_rot(t_obj *obj, const char **tab, int *i);

/*
**			get_light.c
*/

void					light_position(t_env *e);

/*
**			get_scene.c
*/

int						check_param(const char *str, int i, int max);
int						input_vector(const char *tab, int *i, t_vector *vec);
int						get_scene(t_env *e, char *file);

/*
**			hook.c
*/

int						mouse_hook_func(int button, int x, int y, t_env *e);
int						key_hook_func(int key, t_env *e);

/*
**			inter.c
*/

double					sphere_inter(t_obj *obj, t_ray *ray);
double					cylinder_inter(t_obj *obj, t_ray *ray);
double					cone_inter(t_obj *obj, t_ray *ray);
double					plane_inter(t_obj *obj, t_ray *ray);

/*
**			inter_utils.c
*/

double					solver(t_solver *s);
void					get_hit_point_info(t_hit *hit_point, t_obj *obj,
											t_ray *ray);
/*
**			objet_hit.c
*/

void					drawer(t_env *e);
void					put_image(t_env *e);

/*
**			ray.c
*/

void					current_ray(double x, double y, t_env *e, t_ray *ray);

/*
**			rotate_event.c
*/

void					rotate(int key, t_env *e);

/*
**			translate_event.c
*/

void					translate(int key, t_env *e);

/*
**			vector.c
*/

t_vector				subvect(t_vector *v1, t_vector *v2);
t_vector				addvect(t_vector *v1, t_vector *v2);
t_vector				scalevect(double k, t_vector *v1);
float					normevect(t_vector *v1);
t_vector				crossvect(t_vector *v1, t_vector *v2);

/*
**			vector2.c
*/

void					normalize(t_vector *v);
double					prodscal(t_vector *v1, t_vector *v2);
t_vector				opposite(t_vector *v);

#endif
