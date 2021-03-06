/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:38:17 by mhalit            #+#    #+#             */
/*   Updated: 2017/10/03 16:54:38 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		cylinder_norm(t_obj cyl, t_vec3 poi)
{
	t_vec3		normal;
	t_vec3		tmp;
	t_vec3		project;
	float		dot;

	tmp = vec_sub3(poi, cyl.pos);
	dot = vec_dot3(tmp, cyl.vector);
	project = vec_scale3(cyl.vector, dot);
	normal = vec_sub3(tmp, project);
	if (cyl.mat.sin == 1)
	{
		normal.x = normal.x;
		normal.y = sin(normal.y) * 20;
		normal.z = normal.z;
	}
	return (vec_norme3(normal));
}

float		intersect_cylinder(t_ray ray, t_obj *cyl)
{
	t_calc	op;
	float	dotdv;
	float	dotxv;
	t_vec3	x;

	x = vec_sub3(ray.pos, cyl->pos);
	dotdv = vec_dot3(ray.dir, cyl->vector);
	dotxv = vec_dot3(x, cyl->vector);
	op.a = vec_dot3(ray.dir, ray.dir) - p(dotdv);
	op.b = 2 * (vec_dot3(ray.dir, x) - dotdv * dotxv);
	op.c = vec_dot3(x, x) - p(dotxv) - p(cyl->r);
	op.eq = get_res_of_quadratic(&op, cyl);
	if (op.eq == op.t0)
		return (limit_dist(*cyl, ray, op.eq, op.t1));
	else
		return (limit_dist(*cyl, ray, op.eq, op.t0));
}
