/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:45:43 by alebui            #+#    #+#             */
/*   Updated: 2019/07/24 15:45:44 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define MLX_BIG_ENDIAN 1
# define STACK_MAX 10000
# include "libft.h"
# include <math.h>
# include <mlx.h>

typedef unsigned int	t_uint32;

typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_pos_d
{
	double				x;
	double				y;
}						t_pos_d;

typedef struct			s_img
{
	void				*ptr;
	char				*data;
	int					bpp;
	int					s_line;
	int					endian;
	int					color;
	t_pos				img_s;
}						t_img;

typedef struct			s_mlx
{
	void				*ptr;
	void				*wind;
	t_pos				mlx_s;
	t_pos				start;
	t_pos				end;
	int					var;
	t_img				*img;
}						t_mlx;

typedef	struct			s_color
{
	unsigned char		green;
	unsigned char		blue;
	unsigned char		red;
}						t_color;

/*
** mlx.c
*/

t_mlx					*mlx_start(int width, int height, char *title);
void					mlx_destroy(t_mlx *mlx);

/*
** img.c
*/

t_img					*ft_new_image(void *mlx_ptr, int width, int height);
int						img_pixel_put(t_mlx *mlx, t_pos pos);
void					ft_destroy_image(void *ptr, t_img *img);
int						pixel_color(t_mlx *mlx, t_pos pos);
t_uint32				true_color(void *mlx, int endian, int rgb);

/*
** draw.c
*/

int						drawline(t_mlx *mlx, t_pos start, t_pos end);
int						draw_circle(t_mlx *mlx, t_pos *origin,
							int angle, int rayon);
int						draw_square(t_mlx *mlx,
							t_pos mouse, int var);

/*
** fill.c
*/

int						fill_img(t_mlx *mlx, int color, int width, int height);
int						fill_img_pos(t_mlx *mlx, int color,
							t_pos start, t_pos end);

#endif
