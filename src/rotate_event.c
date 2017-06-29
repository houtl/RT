/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:23:53 by thou              #+#    #+#             */
/*   Updated: 2017/05/28 17:41:35 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	rotate_rot(int key, t_vector *rot)
{
	if (key == KEY_PAD_1)
		*rot = (t_vector){rot->x * cosf(0.13) + rot->y *
			sinf(-0.13), rot->x * sinf(0.13) + rot->y * cosf(0.13), rot->z};
	if (key == KEY_PAD_2)
		*rot = (t_vector){rot->x * cosf(0.13) + rot->y * sinf(0.13)
			, rot->x * sinf(-0.13) + rot->y * cosf(0.13), rot->z};
	if (key == KEY_PAD_4)
		*rot = (t_vector){rot->x * cosf(0.13) + rot->z * sinf(0.13)
			, rot->y, rot->x * sinf(-0.13) + rot->z * cosf(0.13)};
	if (key == KEY_PAD_5)
		*rot = (t_vector){rot->x * cosf(0.13) + rot->z *
			sinf(-0.13), rot->y, rot->x * sinf(0.13) + rot->z * cosf(0.13)};
	if (key == KEY_PAD_7)
		*rot = (t_vector){rot->x, rot->y * cosf(0.13) + rot->z *
			sinf(-0.13), rot->y * sinf(0.13) + rot->z * cosf(0.13)};
	if (key == KEY_PAD_8)
		*rot = (t_vector){rot->x, rot->y * cosf(0.13) + rot->z *
			sinf(0.13), rot->y * sinf(-0.13) + rot->z * cosf(0.13)};
}

void		rotate(int key, t_env *e)
{
	if (e->is_obj_selected != 1)
	{
		rotate_rot(key, &e->cam.pos);
		rotate_rot(key, &e->cam.dir);
	}
	else
		rotate_rot(key, &e->hit_obj->rot);
}
