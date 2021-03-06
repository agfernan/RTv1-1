/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:09:53 by mhalit            #+#    #+#             */
/*   Updated: 2017/10/03 18:37:04 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			display_args(void)
{
	ft_putstr("\nusage: rtv1 [-s source] [-w width] [-h height]\n");
	ft_putstr("-s : Set the specified source file\n");
	ft_putstr("-w : Width of the window, default 500px\n");
	ft_putstr("-h : Height of the window, default 500px\n");
	ft_putstr("--help : Show help\n");
	ft_putstr("-a : Set the antialiasing technique to the image\n");
	exit(42);
}

void			key_init(t_rt *e)
{
	e->keys.key_up = 0;
	e->keys.key_down = 0;
	e->keys.key_right = 0;
	e->keys.key_left = 0;
	e->keys.key_pagup = 0;
	e->keys.key_pagdwn = 0;
	e->keys.key_w = 0;
	e->keys.key_a = 0;
	e->keys.key_s = 0;
	e->keys.key_d = 0;
	e->keys.key_q = 0;
	e->keys.key_e = 0;
	e->keys.key_n = 0;
	e->keys.key_o = 0;
	e->keys.key_plus = 0;
	e->keys.key_minus = 0;
}

void			init_rt(t_rt *e)
{
	e->mlx.init = mlx_init();
	LARGEUR = 1024;
	HAUTEUR = 768;
	RES = calcul_res(e, 400000);
	RES_BUFF = RES;
	ALIASING = 1;
	e->scene.nbr_obj = 0;
	e->scene.nbr_complex = 0;
	e->scene.nbr_light = 0;
	e->scene.nbr_tot = 0;
	e->scene.ambient = 0.1;
	e->scene.skybox.is_init = 0;
	if (!(e->scene.obj = (t_obj *)malloc(sizeof(t_obj) * MAXOBJ)))
		exit(42);
	if (!(e->scene.lights = (t_light *)malloc(sizeof(t_light) * MAXLIGHT)))
		exit(5);
	e->scene.supersampling = 1;
	e->scene.filters = 0;
	e->scene.selected = -1;
	SFILE = NULL;
	e->gtk.started = 0;
	e->frame = 0;
	e->scene.max_iter = 3;
	key_init(e);
}

void			ft_start_rt(t_rt *e)
{
	e->gtk.started = 1;
	if (!HAUTEUR || !LARGEUR)
		exit(0);
	WIN = mlx_new_window(INIT, LARGEUR, HAUTEUR, "RT");
	IMG = mlx_new_image(INIT, LARGEUR, HAUTEUR);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_L, &ENDIAN);
	frame(e);
	mlx_hook(WIN, 2, 0, keypress, e);
	mlx_hook(WIN, 3, 0, keyrelease, e);
	mlx_hook(WIN, 17, 0, ft_close, NULL);
	mlx_mouse_hook(WIN, select_obj, e);
	mlx_loop_hook(INIT, no_event, e);
	mlx_loop(INIT);
}

int				main(int argc, char **argv)
{
	t_rt	*e;

	if (!(e = (t_rt *)malloc(sizeof(t_rt))))
		return (0);
	init_rt(e);
	if (argc > 2)
	{
		if (!parse_args(argv, argc, e))
			return (0);
		ft_start_rt(e);
	}
	else
		ft_gtk_start_launcher(e);
	return (0);
}
