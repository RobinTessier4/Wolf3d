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

#define VERBOSE 1

#define WIDTH 500
#define HEIGHT 500

#define BLACK 0
#define WHITE 0xFFFFFF

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

typedef struct 		s_key
{
	int				k_left;
	int				k_down;
	int				k_up;
	int				k_right;
	int				k_w;
	int				k_a;
	int				k_s;
	int				k_d;
}					t_key;

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
	int 			midray;
	int 			leftray;
	int 			rightray;
	int				lineheight;
	
	t_vector 		*dir; //rayon central partant du player
	t_vector 		*plane;
	t_vector 		*lray;
	t_vector 		*rray;
	
	t_virtual		lray2;
	t_virtual		rray2;
	unsigned char 	red;
	unsigned char 	green;
	unsigned char 	blue;
	unsigned int 	color;
	char			help;
	t_key			key;
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
** error.c
*/

void			usage(char *program);
void			ft_error(void);
int				error_msg(char *message, t_env *env);


/*
** utils.c
*/

void			print_map(t_env *e);
//int			ft_abs(int nbr); on peut utiliser abs de math.h je crois donc pas utile


/*
** image.c
*/

void			put_pixel_color(t_env *e, int color, t_pos *pos);
void			draw_line(t_env *e, t_vector *v);

/*
** wolf.c
*/

void			draw_2D_map(t_env *e);
void			player_position(t_env *e);
void			draw_grid(t_env *e);
void			draw_raycasting(t_env *e);

/*
** key_hook.c
*/

int				key_hook(int key, t_env *e);
int				key_release_hook(int key, t_env *env);

/*
** mouse_hook.c
*/

int				mouse_hook(int key, int x, int y, t_env *e);

/*
** mlx.c
*/

int				param_init(t_env *e);
t_env			*init_mlx(t_env *e);

/*
** draw_grid.c.c
*/

void			draw_inf_line(t_env *e, t_vector *v);
int				text_init(t_env *e);


/*
** vector.c
*/

void			draw_vector(t_env *e);
void	        vector_init(t_env *e, t_vector *v);
void	        ray_init(t_env *e);
void	        draw_rayons(t_env *e, t_vector *tmp);
void	        draw_vector(t_env *e);
void			draw_text(t_env *e, t_vector *v, t_pos_d rayend);

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

int				texture_init(t_env *e);

/*
** hud.c
*/

void			draw_info_line(t_env *e);
void			info(t_env *e);

#endif
