/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:20:45 by thou              #+#    #+#             */
/*   Updated: 2017/05/28 15:03:27 by thou             ###   ########.fr       */
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
