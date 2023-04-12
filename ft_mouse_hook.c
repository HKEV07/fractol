/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:25:25 by ibenaait          #+#    #+#             */
/*   Updated: 2023/03/06 15:48:59 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_control_julia(int x, int y, t_utls *info)
{
	if (info->fr == 3 && !info->bool_j)
	{
		info->c_a = ((x + (WIDTH / 3)) * info->range_x) - info->output_start_x;
		info->c_b = ((y + (HEIGHT / 3)) * info->range_y) - info->output_start_y;
	}
	ft_fractol_all(info);
	return (0);
}

int	ft_handl_mouse(int button, int x, int y, t_utls *info)
{
	if (button == 1)
		info->bool_j = 1;
	else if (button == 2)
		info->bool_j = 0;
	else if (button == 4)
	{
		info->output_start_x += (x * info->range_x);
		info->output_start_y += (y * info->range_y);
		info->range_x *= 2;
		info->range_y *= 2;
		if (info->nzo > 0)
			info->nzo -= 0.06;
	}
	else if (button == 5)
	{
		info->range_x /= 2;
		info->range_y /= 2;
		info->output_start_x -= (x * info->range_x);
		info->output_start_y -= (y * info->range_y);
		info->nzo += 0.06;
	}
	ft_fractol_all(info);
	return (0);
}
