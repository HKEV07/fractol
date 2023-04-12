/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis_fun_fr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:11:38 by ibenaait          #+#    #+#             */
/*   Updated: 2023/03/05 21:00:23 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_all(t_utls *info)
{
	if (info->fr == 1)
		ft_mandelbrot_set(info);
	else if (info->fr == 2)
		ft_burnship_set(info);
	else if (info->fr == 3)
		ft_julia_set(info);
}

void	ft_intial_var_j(t_utls *info)
{
	info->new_x = 0;
	info->new_y = 0;
	info->iter = 0;
	info->re = 0;
	info->im = 0;
}

void	ft_intial_var_f(t_utls *info)
{
	info->color_sheft = 1;
	info->output_start_x = 2.0;
	info->output_start_y = 2.0;
	info->range_x = 4.0 / WIDTH;
	info->range_y = 4.0 / HEIGHT;
	info->x_move = 0;
	info->y_move = 0;
	info->nzo = 0.1;
	info->mlrud = 0;
}
