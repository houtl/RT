/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:20:45 by thou              #+#    #+#             */
/*   Updated: 2017/06/29 13:57:15 by ibtraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	pixel_put(int x, int y, t_color col, t_mlx *mlx)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		*(unsigned int*)(mlx->data + (x * (mlx->bpp / 8)) + (y * mlx->sl)) =
			RGB(col.r, col.g, col.b);
	}
}

void	get_fresnel_coef(t_env *env, t_hit hit)
{
	double	rn;
	double	rt;

	rn = (hit.n1 * hit.cosi - hit.n2 * hit.cost) / (hit.n1 * hit.cosi + hit.n2
			* hit.cost);
	rt = (hit.n2 * hit.cosi - hit.n1 * hit.cost) / (hit.n2 * hit.cosi + hit.n1
			* hit.cost);
	rn *= rn;
	rt *= rt;
	env->krefl = ft_clamp((rn + rt) * 0.5, 0, 1);
	env->krefr = 1.0 - env->krefl;
}
