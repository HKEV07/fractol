/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:41:41 by ibenaait          #+#    #+#             */
/*   Updated: 2023/03/06 22:40:32 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>  
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>  
# include <string.h>  
# include <stdlib.h>

# define WIDTH 1000
# define HEIGHT 1000
# define ITER_MAX 80

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addrs;
	int		pixel_byt;
	int		line_byt;
	int		endain;
}	t_img;

typedef struct s_utls
{
	t_img	imag;
	void	*mlx;
	void	*win;
	double	im;
	double	re;
	double	im_new;
	double	re_new;
	int		color;
	int		iter;
	int		x;
	int		y;
	double	new_x;
	double	new_y;
	double	c_a;
	double	c_b;
	double	range_x;
	double	range_y;
	double	output_start_x;
	double	output_start_y;
	double	nzo;
	double	x_move;
	double	y_move;
	double	mlrud;
	int		fr;
	int		color_sheft;
	int		x_mouse;
	int		y_mouse;
	int		bool_j;
}	t_utls;

void	ft_mandelbrot(void);
void	ft_burnship(void);
void	ft_color(t_utls *info);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_julia(void);
int		ft_handl_mouse(int button, int x, int y, t_utls *info);
void	ft_mandelbrot_set(t_utls *info_a);
void	ft_burnship_set(t_utls *info);
void	ft_mandlebrot_f(t_utls *info);
void	ft_intial_var_j(t_utls *info);
void	ft_intial_var_f(t_utls *info);
void	ft_burnship_set(t_utls *info);
int		ft_close_window(t_utls *info);
int		ft_key_hook(int button, t_utls *info);
void	ft_fractol_all(t_utls *info);
void	ft_julia_set(t_utls *info);
int		ft_control_julia(int x, int y, t_utls *info);
#endif