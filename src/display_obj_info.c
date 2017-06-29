/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_obj_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:20:32 by thou              #+#    #+#             */
/*   Updated: 2017/05/29 15:07:06 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_put_info(t_env *e)
{
	char	*line;
	int		fd;
	int		i;

	i = 5;
	line = "press H for more information";
	mlx_string_put(e->mlx.mlx, e->mlx.win, 20, 5, YELLOW, line);
	fd = open(".info", O_RDONLY);
	while (e->help == 1 && (get_next_line(fd, &line)) > 0)
	{
		mlx_string_put(e->mlx.mlx, e->mlx.win, 20, (i += 20), RAZER, line);
		free(line);
	}
	close(fd);
}

static void	display_hit_obj_info(t_env *e)
{
	char *x;
	char *y;
	char *z;
	char *s1;
	char *s2;

	e->itoapos = NULL;
	if (!(e->hit_obj))
		return ;
	x = ft_itoa(e->hit_obj->pos.x);
	y = ft_itoa(e->hit_obj->pos.y);
	z = ft_itoa(e->hit_obj->pos.z);
	s1 = ft_strjoin(x, ",");
	s2 = ft_strjoin(s1, y);
	ft_strdel(&x);
	ft_strdel(&s1);
	s1 = ft_strjoin(s2, ",");
	ft_strdel(&s2);
	s2 = ft_strjoin(s1, z);
	ft_strdel(&s1);
	e->itoapos = ft_strjoin(s2, "]");
	ft_strdel(&s2);
}

void		display_info(t_env *e)
{
	if (e->is_obj_selected)
	{
		e->itoapos = NULL;
		display_hit_obj_info(e);
		mlx_string_put(e->mlx.mlx, e->mlx.win, 340, 415, 0x00FEDC,
				e->tab[e->hit_obj->name - 1]);
		mlx_string_put(e->mlx.mlx, e->mlx.win, 340, 425, 0x00FEDC,
				"--------------");
		mlx_string_put(e->mlx.mlx, e->mlx.win, 340, 435, 0x00FEDC,
				"pos:[");
		mlx_string_put(e->mlx.mlx, e->mlx.win, 392, 435, 0x00FEDC,
				e->itoapos);
		if (e->hit_obj->name == SPHERE || e->hit_obj->name == CYLINDER
				|| e->hit_obj->name == CONE)
		{
			e->itoasize = 0;
			mlx_string_put(e->mlx.mlx, e->mlx.win, 340, 455, 0x00FEDC,
					"size:[");
			e->itoasize = ft_itoa(e->hit_obj->size);
			mlx_string_put(e->mlx.mlx, e->mlx.win, 400, 455, 0x00FEDC,
					e->itoasize);
			mlx_string_put(e->mlx.mlx, e->mlx.win, 420, 455, 0x00FEDC, "]");
		}
	}
}

int			clicked_obj_info(int x, int y, t_env *e)
{
	double		t;
	t_ray		ray;

	e->hit_obj = NULL;
	current_ray(x, y, e, &ray);
	t = find_closest_t(e->obj, &ray, &e->hit_obj);
	if (t > 0.0001 && t < 8000.0 && e->hit_obj)
	{
		e->hit_obj->current = 0;
		e->is_obj_selected = 1;
		return (1);
	}
	return (0);
}
