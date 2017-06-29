/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:23:43 by thou              #+#    #+#             */
/*   Updated: 2017/06/29 15:43:23 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	current_ray(double x, double y, t_env *e, t_ray *ray)
{
	double	xindent;
	double	yindent;

	e->cam.normal = subvect(&e->cam.pos, &e->cam.dir);
	normalize(&e->cam.normal);
	e->cam.right = crossvect(&e->cam.normal, &e->up);
	normalize(&e->cam.right);
	e->cam.up = crossvect(&e->cam.right, &e->cam.normal);
	xindent = (WIDTH - x * 2.0) / HEIGHT;
	yindent = (HEIGHT - y * 2.0) / WIDTH;
	ray->pos.x = e->cam.pos.x;
	ray->pos.y = e->cam.pos.y;
	ray->pos.z = e->cam.pos.z;
	ray->dir.x = FOC * e->cam.normal.x + yindent * e->cam.up.x + xindent *
		e->cam.right.x;
	ray->dir.y = FOC * e->cam.normal.y + yindent * e->cam.up.y + xindent *
		e->cam.right.y;
	ray->dir.z = FOC * e->cam.normal.z + yindent * e->cam.up.z + xindent *
		e->cam.right.z;
	normalize(&ray->dir);
}

t_ray	reflection_ray(t_ray ray, t_hit hit)
{
	double		scalar;
	t_vector	tmp;
	t_ray		refl_ray;
	t_vector	offset;

	scalar = prodscal(&hit.normal, &ray.dir);
	tmp = scalevect(-2.0 * scalar, &hit.normal);
	refl_ray.dir = addvect(&tmp, &ray.dir);
	normalize(&refl_ray.dir);
	offset = (t_vector){refl_ray.dir.x * BIAS, refl_ray.dir.y * BIAS,
		refl_ray.dir.z * BIAS};
	refl_ray.pos  = (t_vector){hit.point.x - offset.x, hit.point.y - offset.y,
		hit.point.z - offset.z};
	return (refl_ray);
}

t_ray	refraction_ray(t_ray ray, t_hit hit, t_env *e)
{
	t_ray		refr_ray;
	double		n;
	t_vector	dir1;
	t_vector	dir2;
	t_vector	offset;

	n = hit.n1 / hit.n2;
	if (n == 1.0)
		return ray;
	if (1.0 - (hit.cost * hit.cost) < 0.0)
	{
		e->krefl = 1.0;
		e->krefr = 0.0;
		return(reflection_ray(ray, hit));
	}
	dir1 = scalevect(n, &ray.dir);
	dir2 = scalevect((n * hit.cosi - hit.cost), &hit.normal);
	refr_ray.dir = addvect(&dir1, &dir2);
	normalize(&refr_ray.dir);
	offset = (t_vector){ray.dir.x * BIAS, ray.dir.y * BIAS, ray.dir.z * BIAS};
	refr_ray.pos = (t_vector){hit.point.x - offset.x, hit.point.y - offset.y,
		hit.point.z - offset.z};
	return (refr_ray);
}
