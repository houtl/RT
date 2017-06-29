/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:22:15 by thou              #+#    #+#             */
/*   Updated: 2017/05/29 14:58:35 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				mouse_hook_func(int button, int x, int y, t_env *e)
{
	if (button == 1 && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (1 == clicked_obj_info(x, y, e))
			put_image(e);
	}
	return (0);
}

int				key_hook_func(int key, t_env *e)
{
	if (key == KEY_ESC)
		err_exit("EXIT");
	if (key == KEY_V)
		e->aa *= 2;
	if (key == KEY_C)
		e->aa /= 2;
	e->aa = (e->aa < 1) ? 1 : e->aa;
	if (key == KEY_B)
		e->aa = 1;
	if (key == KEY_H)
		e->help *= -1;
	if (key == KEY_L)
	{
		e->l = (e->l == (e->total_light - 1) ? 0 : (e->l + 1));
		e->hit_obj = e->light[e->l];
		e->is_obj_selected = 1;
		put_image(e);
		return (0);
	}
	translate(key, e);
	rotate(key, e);
	drawer(e);
	put_image(e);
	return (0);
}
