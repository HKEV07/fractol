/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:10:28 by ibenaait          #+#    #+#             */
/*   Updated: 2023/03/06 20:40:55 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel(t_utls *info)
{
	unsigned char	*pixel;

	if ((info->x + info->new_x >= 0 || info->x + info->new_x < WIDTH) \
	&& (info->y + info->new_y < HEIGHT || info->y + info->new_y >= 0))
	{
		pixel = (unsigned char *)info->imag.img_addrs + \
		(info->y * info->imag.line_byt + info->x * (info->imag.pixel_byt / 8));
		*(int *)pixel = info->color;
	}
}

void	ft_color(t_utls *info)
{
	double	t;
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	t = 0.0;
	if (info->iter >= ITER_MAX)
		info->color = 0x00000000;
	if (info->iter < ITER_MAX)
	{
		t = (double) info->iter / ITER_MAX;
		r = (int)(7 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		info->color = ((r << 16) + (g << 8) + b) * info->color_sheft;
	}
	ft_pixel(info);
}
