/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:20:00 by thou              #+#    #+#             */
/*   Updated: 2017/05/28 15:11:59 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		copy_cam(t_cam *dst, t_cam src)
{
	dst->pos.x = src.pos.x;
	dst->pos.y = src.pos.y;
	dst->pos.z = src.pos.z;
	dst->dir.x = src.dir.x;
	dst->dir.y = src.dir.y;
	dst->dir.z = src.dir.z;
}

static void	copy_obj(t_obj *dst, t_obj src)
{
	dst->name = src.name;
	dst->pos.x = src.pos.x;
	dst->pos.y = src.pos.y;
	dst->pos.z = src.pos.z;
	dst->color.r = src.color.r;
	dst->color.g = src.color.g;
	dst->color.b = src.color.b;
	dst->rot.x = src.rot.x;
	dst->rot.y = src.rot.y;
	dst->rot.z = src.rot.z;
	dst->size = src.size;
	dst->ambient = src.ambient;
	dst->diffuse = src.diffuse;
	dst->specular = src.specular;
	dst->current = src.current;
}

int			copy_list(t_list **dst, t_list *src)
{
	t_list	*new;
	t_list	*tmp;
	t_obj	*obj;
	t_obj	*tmp_obj;

	*dst = NULL;
	tmp = src;
	while (tmp != NULL)
	{
		obj = (t_obj *)tmp->content;
		if (NULL == (tmp_obj = (t_obj *)malloc(sizeof(t_obj))))
			return (-1);
		copy_obj(tmp_obj, *obj);
		if (NULL == (new = (ft_lstnew((void *)tmp_obj, sizeof(t_obj)))))
			return (-1);
		ft_lstadd(dst, new);
		tmp = tmp->next;
	}
	return (0);
}

void		copy_up(t_vector *dst, t_vector src)
{
	dst->x = src.x;
	dst->y = src.y;
	dst->z = src.z;
}
