/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:20:43 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:06:29 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "controls.h"
# include <errno.h>
# include <libft.h>
# include <draw.h>
# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>

/*
** print error
*/

# define VERBOSE 1

/*
** wolf set up
*/

# define WIDTH 500
# define HEIGHT 500
# define BLOC_HEIGHT 95
# define ROT_SPEED 0.07

/*
** game's colors
*/

# define BLACK 0
# define WHITE 0xFFFFFF
# define DAYSKY 0x2FC4EE
# define NIGHTSKY 0x084B83
# define DAYFLOOR 0xC5B087
# define NIGHTFLOOR 0x081c15
# define DAY_HUD 0x253237
# define NIGHT_HUD 0x5500a8
# define TITLE_HUD 0x89fc00
# define TEXT_HUD 0xFFFFFF
# define BEYOND_MAP 0x42321b
# define FLOOR 0xC5B087
# define RAY 0x89fc00
# define PLAYER_COL 0xd00000
# define BLOC_COLOR 0x1B9E77

typedef struct		s_vector
{
	t_pos			start;
	t_pos			end;
	t_pos			dist;
	int				sx;
	int				sy;
	float			a;
	float			b;
	float			err;
}					t_vector;

typedef struct		s_virtual
{
	t_pos_d			start;
	t_pos_d			end;
	t_pos_d			dist;
	float			sx;
	float			sy;
	float			a;
	float			b;
	float			err;
}					t_virtual;

typedef	struct		s_parse
{
	int				*nums;
	struct s_parse	*next;
}					t_parse;

typedef struct		s_env
{
	int				gnl_ret;
	int				file_descriptor;
	t_img			**texture_tab;
	t_mlx			*mlx;
	int				map;
	t_parse			*map_lines;
	int				map_width;
	int				map_height;
	int				**file;
	int				**tab;
	double			perp_size;
	t_pos_d			player;
	t_pos_d			dir_p;
	t_pos_d			plane_p;
	double			oldx;
	int				rows;
	int				bloc_width;
	int				bloc_height;
	t_pos			current_bloc;
	t_pos			cursor;
	int				lineheight;
	t_vector		*dir;
	t_vector		*plane;
	t_vector		*lray;
	t_vector		*rray;
	t_virtual		lray2;
	t_virtual		rray2;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned int	color;
	char			help;
	char			nightshift;
}					t_env;

/*
** read_map.c
*/

int					open_file(char *filename);
t_parse				*ft_read_input(int fd, t_env *e);

/*
** parse.c
*/

t_parse				*new_elem(t_env *e, int len);
int					**map_tab(t_env *e);

/*
** init_env.c
*/

int					param_init(t_env *e);
t_env				*init_mlx(t_env *e);

/*
** error.c
*/

void				usage(void);
void				ft_error(void);
int					error_msg(char *message, t_env *env);
void				v_error_msg(char *message, t_env *env);

/*
** utils.c
*/

void				calc_line(int e2, t_vector *v);

/*
** image.c
*/

void				put_pixel_color(t_env *e, int color, t_pos *pos);
void				draw_line(t_env *e, t_vector *v);

/*
** wolf.c
*/

void				render_2d_map(t_env *e);
void				player_position(t_env *e);
void				draw_grid(t_env *e);
void				render_raycasting(t_env *e);

/*
** key_hook.c
*/

int					key_hook(int key, t_env *e);

/*
** mouse_hook.c
*/

int					mouse_hook(int key, int x, int y, t_env *e);

/*
** draw_grid.c.c
*/

void				render_player_fov(t_env *e, t_vector *v);
int					text_init(t_env *e);

/*
** vector.c
*/

t_virtual			init_vector_pos(t_env *e);
void				draw_vector(t_env *e);
void				vector_init(t_vector *v);
void				ray_init(t_env *e);
void				draw_rayons(t_env *e, t_vector *tmp);
void				draw_vector(t_env *e);
void				draw_text(t_env *e, t_vector *v, t_pos_d rayend);

/*
** raycasting.c
*/

void				raycasting(t_env *e);

/*
** clean.c
*/

void				clean_map_lines(t_parse **lst);
void				exit_program(int ret, char *msg, t_env *e);

/*
** texture.c
*/

void				get_text_color(t_env *e, int i, int x, int pos);
unsigned int		render_texture(t_env *e, t_pos_d pos, t_pos_d rayend);

/*
** init_texture.c
*/

int					**malloc_texture(t_env *e);
void				set_texture_stone(t_env *e, int a, int b);
void				set_texture_wood(t_env *e, int a, int b);
int					texture_init(t_env *e);

/*
** hud.c
*/

void				draw_info_line(t_env *e);
void				info(t_env *e);
void				hud_frame(t_env *e);
void				hud_background(t_env *e);

#endif
