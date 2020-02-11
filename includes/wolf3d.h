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
# include </usr/local/include/mlx.h>

#define VERBOSE 1

#define WIDTH 780
#define HEIGHT 420

#define BLACK 0
#define WHITE 0xFFFFFF

typedef struct	s_vector
{
	t_pos		start;
	//int 		x1; //t_pos start
	//int 		y1;

	t_pos		end;
	//int 		x2; //t_pos end
	//int 		y2;
	
	t_pos		dist; //distance ?
	//int 		dx;
	//int 		dy;

	int 		sx;
	int 		sy;

	float 		a;
	float 		b;
	float 		err;
}				t_vector;

typedef	struct	s_parse
{
	int 		*nums;
	struct 		s_parse *next;
}				t_parse;

typedef struct s_env
{

	t_mlx 		*mlx;

	t_parse		*map_lines;
	int			map_width; //nombre de colonnes
	int			map_height; //nombre de lignes
	int			line_cmp;
	int			**file;
	int			**tab;

	t_pos_d		player; //x && y

	t_pos_d		dir_p; //player direction xdir / ydir

	t_pos_d		plane_p; //xplane & ypalne
	double 		oldx;
	int 		rows;
	int 		col;

	int 		bloc_width; //taille d'un bloc = WIDTH / e->map_width;
	int 		bloc_height;
	t_pos		current_bloc; // e->player.y1 = e->current_bloc.y / e->player.x1 = e->current_bloc.x 
	t_pos		cursor;
	
	int 		midray;
	int 		leftray;
	int 		rightray;
	int			lineheight;

	t_vector 	*dir;
	t_vector 	*plane;
	t_vector 	*lray;
	t_vector 	*rray;
}				t_env;

/*
Séparer par des commentaires les fonctions en les classant par fichier
*/


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

/*
** wolf.c
*/

void			draw_2D_map(t_env *e);
void			player_position(t_env *e);
void			draw_grid(t_env *e);

/*
** key_hook.c
*/

int				key_hook(int key, t_env *e);

/*
** mouse_hook.c
*/

int				mouse_hook(int key, int x, int y, t_env *e);

/*
** mlx.c
*/

int				param_init(t_env *e);
t_env			*init_mlx(t_env *e);

#endif
