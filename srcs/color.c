/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 20:14:59 by bbeldame          #+#    #+#             */
/*   Updated: 2017/09/21 15:01:39 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			copy_color(t_color color)
{
	t_color		newcolor;

	newcolor.r = color.r;
	newcolor.g = color.g;
	newcolor.b = color.b;
	return (newcolor);
}

/*
** @param color rbg between 0 and 255
** We convert the number 0 - 255 to 0 - 0.5
** @todo : explain why
*/

t_color			ft_map_color(t_color color1, t_color color2, float taux1)
{
	t_color		new_color;
	float 		taux2;

	if(taux1 >= 1)
		return color2;
	taux2 = 1 - taux1;
	color1 = color_mult(color1, taux2);	
	color2 = color_mult(color2, taux1);
	new_color.r = color1.r + color2.r;
	new_color.g = color1.g + color2.g;
	new_color.b = color1.b + color2.b;
	return (new_color);
}

t_color			color_mult(t_color color, float taux)
{
	t_color		new_color;

	new_color = copy_color(color);
	new_color.r = color.r * taux;
	new_color.g = color.g * taux;
	new_color.b = color.b * taux;
	new_color.r = (new_color.r > 255) ? 255 : new_color.r;
	new_color.g = (new_color.g > 255) ? 255 : new_color.g;
	new_color.b = (new_color.b > 255) ? 255 : new_color.b;
	new_color.r = (new_color.r < 0) ? 0 : new_color.r;
	new_color.g = (new_color.g < 0) ? 0 : new_color.g;
	new_color.b = (new_color.b < 0) ? 0 : new_color.b;
	return (new_color);
}

unsigned int	ret_colors(t_color colo)
{
	unsigned int	total;
	unsigned int	temp;

	total = 0;
	if (colo.r > 0)
	{
		temp = (int)colo.r * 65536;
		total += temp;
	}
	if (colo.g > 0)
	{
		temp = (int)colo.g * 256;
		total += temp;
	}
	if (colo.b > 0)
	{
		temp = (int)colo.b;
		total += temp;
	}
	return (total);
}
