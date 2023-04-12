/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:35:38 by ibenaait          #+#    #+#             */
/*   Updated: 2023/03/06 17:50:29 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_choix_fract(void)
{
	write(1, "\\\\\\\\\\\\\\\\\\\\\\ \n", 13);
	write(1, "\1 - mandelbrot\n", 16);
	write(1, "\2 - burnship\n", 14);
	write(1, "\3 - julia\n", 11);
	write(1, "\\\\\\\\\\\\\\\\\\\\\\ \n", 13);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_choix_fract();
	else if (!ft_strcmp(av[1], "mandelbrot") && !av[2])
		ft_mandelbrot();
	else if (!ft_strcmp(av[1], "burnship") && !av[2])
		ft_burnship();
	else if (!ft_strcmp(av[1], "julia") && !av[2])
		ft_julia();
	else
		ft_choix_fract();
}
