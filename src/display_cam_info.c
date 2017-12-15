/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cam_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:20:13 by thou              #+#    #+#             */
/*   Updated: 2017/12/15 14:19:03 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	display_cam_pos_info(t_env *e)
{
	char	*x;
	char	*y;
	char	*z;
	char	*s1;
	char	*s2;

	x = ft_itoa(e->cam.pos.x);
	y = ft_itoa(e->cam.pos.y);
	z = ft_itoa(e->cam.pos.z);
	s1 = ft_strjoinfree(x, ",");
	s2 = ft_strjoinfree2(s1, y);
	s1 = ft_strjoinfree(s2, ",");
	s2 = ft_strjoinfree2(s1, z);
	e->itoacampos = ft_strjoinfree(s2, "]");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 10, 415, 0x00FEDC, "Camera");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 10, 425, 0x00FEDC, "-----------");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 5, 435, 0x00FEDC, "pos[");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 45, 435, 0x00FEDC, e->itoacampos);
}

static void	display_cam_dir_info(t_env *e)
{
	char	*x;
	char	*y;
	char	*z;
	char	*s1;
	char	*s2;

	e->itoacamdir = NULL;
	x = ft_itoa(e->cam.lookat.x);
	y = ft_itoa(e->cam.lookat.y);
	z = ft_itoa(e->cam.lookat.z);
	s1 = ft_strjoinfree(x, ",");
	s2 = ft_strjoinfree2(s1, y);
	s1 = ft_strjoinfree(s2, ",");
	s2 = ft_strjoinfree2(s1, z);
	e->itoacamdir = ft_strjoinfree(s2, "]");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 5, 453, 0x00FEDC, "lookat[");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 75, 453, 0x00FEDC, e->itoacamdir);
}

void		display_cam_info(t_env *e)
{
	display_cam_pos_info(e);
	display_cam_dir_info(e);
	e->itoacampos ? ft_strdel(&e->itoacampos) : 0;
	e->itoacamdir ? ft_strdel(&e->itoacamdir) : 0;
}
