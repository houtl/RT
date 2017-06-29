/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:23:09 by thou              #+#    #+#             */
/*   Updated: 2017/05/28 16:41:41 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				err_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

static char		**init_tab(void)
{
	char	**tab;

	SAFEMALL((tab = (char**)malloc(sizeof(char*) * 6)));
	tab[0] = ft_strdup("light");
	tab[1] = ft_strdup("plane");
	tab[2] = ft_strdup("cylinder");
	tab[3] = ft_strdup("cone");
	tab[4] = ft_strdup("sphere");
	tab[5] = NULL;
	return (tab);
}

static void		*init_env(t_env *e)
{
	SAFEMALL((e->mlx.mlx = mlx_init()));
	SAFEMALL((e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "rtv1")));
	SAFEMALL((e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT)));
	e->mlx.data = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp),
						&(e->mlx.sl), &(e->mlx.endian));
	SAFEMALL((e->tab = init_tab()));
	e->hit_obj = NULL;
	e->aa = 1.0;
	e->up = (t_vector){0.0, 1.0, 0.0};
	e->obj = NULL;
	e->is_obj_selected = 0;
	e->help = -1;
	e->l = -1;
	return (0);
}

int				main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		err_exit("Usage : ./rtv1 scenes_file");
	init_env(&e);
	if (0 == get_scene(&e, argv[1]))
		err_exit("SCENE ERROR");
	drawer(&e);
	put_image(&e);
	light_position(&e);
	mlx_hook(e.mlx.win, 17, 18, err_exit, "EXIT");
	mlx_mouse_hook(e.mlx.win, mouse_hook_func, &(e.mlx));
	mlx_hook(e.mlx.win, 2, (1L << 0), key_hook_func, &(e.mlx));
	mlx_loop(e.mlx.mlx);
	return (0);
}
