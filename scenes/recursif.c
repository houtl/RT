/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:32:40 by ibtraore          #+#    #+#             */
/*   Updated: 2017/06/29 15:40:26 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define ADDCOL(x, a, b, c) add_col(t_color a1, t_color a2, t_color a3);
#define	SCACOL(a,b) scale_col(double tmp, t_color color);

t_color		scale_col(double tmp, t_color color)
{
	t_color color;

	color.r *= tmp;
	color.g *= tmp;
	color.b *= tmp;
	return (color);
}

t_color		add_col(t_color amb, t_color a1, t_color a2, t_color a2)
{
	t_color color;
	int		tmp[3];

	tmp[0] = amb.r + a1.r + a2.r + a3.r ;
	tmp[1] = amb.g + a1.g + a2.g + a3.g ;
	tmp[2] = amb.b + a1.b + a2.b + a3.b ;
	color.r = (tmp[0] > 255) ? 255 : tmp[0] & 0xFF;
	color.g = (tmp[1] > 255) ? 255 : tmp[1] & 0xFF;
	color.b = (tmp[2] > 255) ? 255 : tmp[2] & 0xFF;
	return (color);
}

t_color		recursif_trajet(t_ray ray, int depth,  t_env *env)
{
	t_color	color;
	t_color	res;
	t_obj	*hit_obj

	hit_obj = NULL;
	if (depth > MAX_DEPTH)
		return ((t_color){0, 0, 0});
	else if ((t = find_closest_t(env->obj, ray, &hit_obj)) && hit_obj)
	{
		hit.t = t;
		color = lighting(env->obj, &hit_obj, ray, env->t);
		get_hit_point_info(&hit, &hit_obj, &ray);
		env->refl = reflection_ray(ray, hit);
		env->refr = refraction_ray(ray, hit, env);
		res = ADDCOL(color, SCACOL(env->krefl, recursif_trajet(env->refl, depth + 1, env)),
					SCACOL(env->krefr, recursif_trajet(env->refr, depth + 1, env)));
		if (hit_obj != NULL)
			hit_obj->current = 0;
	}
	else
		return ((t_color){0, 0, 0});
}
