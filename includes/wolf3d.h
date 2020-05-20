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

#ifndef WOLF_H
# define WOLF_H

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

#define VERBOSE 0

#define WIDTH 500
#define HEIGHT 500

#define BLACK 0
#define WHITE 0xFFFFFF
#define DAYSKY 0x2FC4EE
#define NIGHTSKY 0x084B83
#define DAYFLOOR 0xC5B087
#define NIGHTFLOOR 0x081c15
#define DAY_HUD 0x253237
#define NIGHT_HUD 0x5500a8
#define TITLE_HUD 0x89fc00
#define TEXT_HUD 0xFFFFFF

#define BEYOND_MAP 0x42321b
#define FLOOR 0xC5B087
#define RAY 0x89fc00
#define PLAYER_COL 0xd00000
#define BLOC_COLOR 0x1B9E77

#define BLOC_SIZE 1
#define BLOC_HEIGHT 95

#define ROT_SPEED 0.07

typedef struct		s_text
{	
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_text;

typedef struct		s_vector
{	
	t_pos			start; //x1 ; y1
	t_pos			end; //x2 ; y2	
	t_pos			dist; //distance ? dx; dy
	int 			sx;
	int 			sy;
	float 			a;
	float 			b;
	float 			err;
}					t_vector;

typedef struct		s_virtual
{	
	t_pos_d			start;
	t_pos_d			end;
	t_pos_d			dist; //distance ?
	float 			sx;
	float 			sy;
	float 			a;
	float 			b;
	float 			err;
}					t_virtual;

typedef	struct		s_parse
{	
	int 			*nums;
	struct s_parse *next;
}					t_parse;

typedef struct s_env
{
	t_text			text[9];
	t_mlx 			*mlx;
	int				map; //permet d'afficher 2D en appuyant sur espace
	t_parse			*map_lines;
	int				map_width; //nombre de colonnes
	int				map_height; //nombre de lignes
	int				line_cmp;
	int				**file;
	int				**tab;
	double			perp_size;
	t_pos_d			player; //x && y
	t_pos_d			dir_p; //player direction xdir / ydir [-1, 0, 1]
	t_pos_d			plane_p; //xplane & ypalne
	double 			oldx;
	int 			rows;
	int 			bloc_width; //taille d'un bloc = WIDTH / e->map_width;
	int 			bloc_height;
	t_pos			current_bloc; // e->player.y1 = e->current_bloc.y / e->player.x1 = e->current_bloc.x
	t_pos			cursor;
	int				lineheight;
	
	t_vector 		*dir; //rayon central partant du player
	t_vector 		*plane;
	t_vector 		*lray;
	t_vector 		*rray;

	t_pos_d			rayend;
	
	t_virtual		lray2;
	t_virtual		rray2;

	unsigned char 	red;
	unsigned char 	green;
	unsigned char 	blue;
	unsigned int 	color;

	char			help;
	char			nightshift;
}					t_env;

/*
** read_map.c
*/

int				open_file(char *filename);
t_parse			*ft_read_input(int fd, t_env *e);

/*
** parse.c
*/

void			del_map_lines(t_parse **lst);
t_parse			*new_elem(t_env *e, int len);
int				**map_tab(t_env *e);

/*
** init_env.c
*/

int				param_init(t_env *e);
t_env			*init_mlx(t_env *e);

/*
** error.c
*/

void			usage(void);
void			ft_error(void);
int				error_msg(char *message, t_env *env);
void			v_error_msg(char *message, t_env *env);

/*
** utils.c
*/

void			print_map(t_env *e);
void			calc_line(int e2, t_vector *v);

/*
** image.c
*/

void			put_pixel_color(t_env *e, int color, t_pos *pos);
void			draw_line(t_env *e, t_vector *v);

/*
** wolf.c
*/

void			render_2d_map(t_env *e);
void			player_position(t_env *e);
void			draw_grid(t_env *e);
void			render_raycasting(t_env *e);

/*
** key_hook.c
*/

int				key_hook(int key, t_env *e);

/*
** mouse_hook.c
*/

int				mouse_hook(int key, int x, int y, t_env *e);


/*
** draw_grid.c.c
*/

void			render_player_fov(t_env *e, t_vector *v);
int				text_init(t_env *e);


/*
** vector.c
*/

t_virtual		init_vector_pos(t_env *e);
void			draw_vector(t_env *e);
void	        vector_init(t_vector *v);
void	        ray_init(t_env *e);
void	        draw_rayons(t_env *e, t_vector *tmp);
void	        draw_vector(t_env *e);
void			draw_text(t_env *e, t_vector *v);

/*
** raycasting.c
*/

void			raycasting(t_env *e);

/*
** clean.c
*/

void			exit_program(t_env *e);

/*
** texture.c
*/

void			get_text_color(t_env *e, int i, int x, int pos);
unsigned int	render_texture(t_env *e, t_pos_d pos);
int				texture_init(t_env *e);

/*
** hud.c
*/

void			draw_info_line(t_env *e);
void			info(t_env *e);
void			hud_frame(t_env *e);
void			hud_background(t_env *e);

#endif
