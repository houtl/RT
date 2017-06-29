/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:19:31 by thou              #+#    #+#             */
/*   Updated: 2017/05/22 13:21:51 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#define INIT 0
#define ADD 1
#define SUM 2

static void	get_tmp(double *tmp, t_obj *obj, t_ray *ray)
{
	if (obj->name == SPHERE)
		*tmp = sphere_inter(obj, ray);
	else if (obj->name == CYLINDER)
		*tmp = cylinder_inter(obj, ray);
	else if (obj->name == CONE)
		*tmp = cone_inter(obj, ray);
	else if (obj->name == PLANE)
		*tmp = plane_inter(obj, ray);
}

double		find_closest_t(t_list *list, t_ray *ray, t_obj **hit_obj)
{
	t_list		*node;
	t_obj		*obj;
	double		t;
	double		tmp;

	t = 8000.0;
	tmp = 8000.0;
	node = list;
	while (node)
	{
		obj = (t_obj *)node->content;
		if (obj->name != LIGHT && 0 == obj->current)
			get_tmp(&tmp, obj, ray);
		if (0.0001 < tmp && tmp < t)
		{
			t = tmp;
			*hit_obj = obj;
		}
		node = node->next;
	}
	if (0.0001 < t && t < 8000.0 && (*hit_obj))
		(*hit_obj)->current = 1;
	return (t);
}
