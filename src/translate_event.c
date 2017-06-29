/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:24:05 by thou              #+#    #+#             */
/*   Updated: 2017/05/29 14:52:00 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	repere(t_env *e)
{
	e->n = subvect(&e->cam.pos, &e->cam.dir);
	normalize(&e->n);
	e->r = crossvect(&e->n, &(t_vector){0.0, 1.0, 0.0});
	normalize(&e->r);
	e->up = crossvect(&e->r, &e->n);
	normalize(&e->up);
}

static void	translate_pos(int key, t_vector *pos, t_env *e)
{
	t_vector	tmp;

	tmp = *pos;
	if (key == KEY_LEFT)
		*pos = (t_vector){tmp.x + e->r.x * 10.0,
			tmp.y + e->r.y * 10.0, tmp.z + e->r.z * 10.0};
	else if (key == KEY_RIGHT)
		*pos = (t_vector){tmp.x - e->r.x * 10.0, tmp.y
			- e->r.y * 10.0, tmp.z - e->r.z * 10.0};
	else if (key == KEY_UP)
		*pos = (t_vector){tmp.x + e->up.x * 10.0,
			tmp.y + e->up.y * 10.0, tmp.z + e->up.z * 10.0};
	else if (key == KEY_DOWN)
		*pos = (t_vector){tmp.x - e->up.x * 10.0,
			tmp.y - e->up.y * 10.0, tmp.z - e->up.z * 10.0};
	else if (key == KEY_PAD_ADD)
		*pos = (t_vector){tmp.x + e->n.x * 10.0,
			tmp.y + e->n.y * 10.0, tmp.z + e->n.z * 10.0};
	else if (key == KEY_PAD_SUB)
		*pos = (t_vector){tmp.x - e->n.x * 10.0, tmp.y -
			e->n.y * 10.0, tmp.z - e->n.z * 10.0};
}

void		translate(int key, t_env *e)
{
	repere(e);
	if (e->is_obj_selected == 1)
		translate_pos(key, &e->hit_obj->pos, e);
	else
	{
		translate_pos(key, &e->cam.pos, e);
		translate_pos(key, &e->cam.dir, e);
	}
	if (key == KEY_R)
	{
		e->is_obj_selected = 0;
		e->hit_obj = NULL;
	}
}
