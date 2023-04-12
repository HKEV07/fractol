/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:05:44 by ibenaait          #+#    #+#             */
/*   Updated: 2023/03/06 20:20:22 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandlebrot_f(t_utls *info)
{
	info->c_a = (info->x * info->range_x) - info->output_start_x ;
	info->c_b = (info->y * info->range_y) - info->output_start_y ;
	while (info->iter <= ITER_MAX \
	&& (info->re * info->re + info->im * info->im) <= 4)
	{
		info->im = info->new_y;
		info->re = info->new_x;
		info->new_x = (info->re * info->re) - (info->im * info->im) + info->c_a;
		info->new_y = 2 * info->re * info->im + info->c_b;
		info->iter++;
	}
	ft_color(info);
}

void	ft_mandelbrot_set(t_utls *info)
{
	mlx_clear_window(info->mlx, info->win);
	info->imag.img_ptr = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->imag.img_addrs = mlx_get_data_addr(info->imag.img_ptr, \
	&info->imag.pixel_byt, &info->imag.line_byt, &info->imag.endain);
	info->x = 0;
	while (info->x < WIDTH)
	{
		info->y = 0;
		while (info->y < HEIGHT)
		{
			ft_intial_var_j(info);
			ft_mandlebrot_f(info);
			info->y++;
		}
		info->x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->imag.img_ptr, 0, 0);
}

void	ft_mandelbrot(void)
{
	t_utls	info;

	info.fr = 1;
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "mandelbrot");
	ft_intial_var_f(&info);
	ft_mandelbrot_set(&info);
	mlx_hook(info.win, 2, 0, ft_key_hook, &info);
	mlx_hook(info.win, 4, 0, ft_handl_mouse, &info);
	mlx_hook(info.win, 17, 0, ft_close_window, &info);
	mlx_loop(info.mlx);
}
