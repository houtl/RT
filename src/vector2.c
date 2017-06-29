/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:24:44 by thou              #+#    #+#             */
/*   Updated: 2017/05/28 15:14:55 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		normalize(t_vector *v1)
{
	double	norm;

	norm = 1.0 / sqrtf(v1->x * v1->x + v1->y * v1->y + v1->z * v1->z);
	v1->x = v1->x * norm;
	v1->y = v1->y * norm;
	v1->z = v1->z * norm;
}

double		prodscal(t_vector *v1, t_vector *v2)
{
	double	ret;

	ret = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (ret);
}

t_vector	opposite(t_vector *v)
{
	t_vector	n;

	n.x = -1.0 * v->x;
	n.y = -1.0 * v->y;
	n.z = -1.0 * v->z;
	return (n);
}
