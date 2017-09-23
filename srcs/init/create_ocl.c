/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ocl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 02:51:19 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/22 00:55:35 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			c_color(float r, float g, float b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_matiere	create_matiere(void)
{
	t_matiere	mat;

	mat.reflex = 0;
	mat.specular = 0;
	mat.opacite = 1;
	return (mat);
}

int			camera_create(t_rt *e)
{
	e->scene.cam.pos = vec_new3(0, 0, -500);
	e->scene.cam.dir = vec_new3(0, 0, 0);
	e->scene.cam.fov = 45;
	e->scene.cam.ctw = id_matrx4();
	e->scene.cam.ratio_x = (LARGEUR > HAUTEUR) ? (float)LARGEUR / (float)HAUTEUR : 1;
	e->scene.cam.ratio_y = (HAUTEUR > LARGEUR) ? (float)HAUTEUR / (float)LARGEUR : 1;
	e->scene.cam.reso = 300;
	return (CAMERA);
}

int			create_obj(int type, t_rt *e)
{
	int		i;

	i = e->scene.nbr_obj;
	e->COBJ.is_init = 1;
	e->COBJ.type = type;
	e->COBJ.color = c_color(255, 255, 255);
	e->COBJ.pos = vec_new3(0, 0, 0);
	e->COBJ.dir = vec_new3(0, 0, 0);
	e->COBJ.k = tan(10 * DEG2RAD / 2);;
	e->COBJ.maxp = vec_new3(0, 0, 0);
	e->COBJ.minp = vec_new3(0, 0, 0);
	e->COBJ.r = 0;
	e->COBJ.t = -1;
	e->COBJ.mat = create_matiere();
	e->COBJ.normal = vec_new3(0, 0, 0);
	e->COBJ.vector = vec_new3(0, 0, 0);
	e->scene.nbr_obj++;
	return (type);
}

int			create_light(t_rt *e)
{
	int		i;

	i = e->scene.nbr_light;
	e->CLIGHT.is_init = 1;
	e->CLIGHT.ray.pos = vec_new3(0, 0, 0);
	e->CLIGHT.ray.dir = vec_new3(0, 0, 0);
	e->CLIGHT.color = c_color(255, 255, 255);
	e->CLIGHT.intensity = 0;
	e->scene.nbr_light++;
	return (LIGHT);
}