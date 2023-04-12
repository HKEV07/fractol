/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:39:59 by ibenaait          #+#    #+#             */
/*   Updated: 2023/03/06 17:10:25 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_window(t_utls *info)
{
	mlx_destroy_window(info->mlx, info->win);
	mlx_clear_window(info->mlx, info->win);
	exit(0);
	return (0);
}

int	ft_key_hook(int button, t_utls *info)
{
	if (button == 53)
	{
		mlx_destroy_window(info->mlx, info->win);
		mlx_clear_window(info->mlx, info->win);
		exit(0);
	}
	else if (button == 257)
		info->color_sheft += 50;
	else if (button == 124)
		info->output_start_x -= 0.01 / info->nzo;
	else if (button == 125)
		info->output_start_y -= 0.01 / info->nzo;
	else if (button == 123)
		info->output_start_x += 0.01 / info->nzo;
	else if (button == 126)
		info->output_start_y += 0.01 / info->nzo;
	ft_fractol_all(info);
	return (0);
}
