/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ocl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 06:21:43 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/23 19:37:28 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		set_last(t_rt *e, char **params)
{
	if (SPHERE == e->scene.last || PLANE == e->scene.last ||
		CONE == e->scene.last || MICKEY == e->scene.last ||
 		DICK == e->scene.last || CYLINDER == e->scene.last)
		return (set_obj(e, params));
	if (LIGHT == e->scene.last)
		return (set_light(e, params));
	if (CAMERA == e->scene.last)
		return (set_camera(e, params));
	return (0);
}

int		set_obj(t_rt *e, char **a)
{
	int		i;

	i = 0;
	while (a[i])
		i++;
	if (i == 4 && !ft_strcmp("pos:", a[0]))
		SOBJ.pos = vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else if (i == 4 && !ft_strcmp("minp:", a[0]))
		SOBJ.minp = vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else if (i == 4 && !ft_strcmp("maxp:", a[0]))
		SOBJ.maxp = vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else if (i == 4 && !ft_strcmp("vector:", a[0]))
		SOBJ.vector = vec_norme3(vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3])));
	else if (!ft_strcmp("reflection:", a[0]))
		SOBJ.mat.reflex = ft_atof(a[1]);
	else if (!ft_strcmp("refraction:", a[0]))
		SOBJ.mat.refract = ft_atof(a[1]);
	else if (i == 4 && !ft_strcmp("normal:", a[0]))
		SOBJ.vector = vec_norme3(vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3])));
	else if (i == 4 && !ft_strcmp("rot:", a[0]))
		SOBJ.dir = vec_norme3(vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3])));
	else if (i == 2 && !ft_strcmp("radius:", a[0]))
		SOBJ.r = ft_atof(a[1]);
	else if (i == 4 && !ft_strcmp("color:", a[0]))
		SOBJ.color = c_color(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else if (i == 2 && !ft_strcmp("angle:", a[0]))
		SOBJ.k = tan(ft_atoi(a[1]) * DEG2RAD / 2);
	else
		return (0);
	return (1);
}

int		set_light(t_rt *e, char **a)
{
	int		i;

	i = 0;
	while (a[i])
		i++;
	if (i == 4 && !ft_strcmp("pos:", a[0]))
		SLIGHT.ray.pos = vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else if (i == 4 && !ft_strcmp("dir:", a[0]))
		SLIGHT.ray.dir = vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else if (i == 2 && !ft_strcmp("intensity:", a[0]))
		SLIGHT.intensity = ft_atof(a[1]);
	else if (i == 4 && !ft_strcmp("color:", a[0]))
		SLIGHT.color = c_color(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else
		return (0);
	return (1);
}

int		set_camera(t_rt *e, char **a)
{
	int		i;

	i = 0;
	while (a[i])
		i++;
	if (i == 4 && !ft_strcmp("pos:", a[0]))
		e->scene.cam.pos =
			vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else if (i == 4 && !ft_strcmp("dir:", a[0]))
		e->scene.cam.dir =
			vec_new3(ft_atof(a[1]), ft_atof(a[2]), ft_atof(a[3]));
	else if (i == 2 && !ft_strcmp("fov:", a[0]))
		e->scene.cam.fov = ft_atoi(a[1]);
	else
		return (0);
	return (1);
}
