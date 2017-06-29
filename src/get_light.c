/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:21:44 by thou              #+#    #+#             */
/*   Updated: 2017/05/28 16:21:19 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		light_position(t_env *e)
{
	t_list	*tmp;
	t_obj	*obj;
	int		i;

	tmp = e->obj;
	e->total_light = 0;
	while (tmp)
	{
		obj = (t_obj*)tmp->content;
		i = -1;
		if (obj && obj->name == LIGHT)
		{
			e->light[e->total_light] = obj;
			e->total_light++;
		}
		tmp = tmp->next;
	}
	if (e->total_light < MAX_LIGHT)
		e->light[e->total_light] = NULL;
}
