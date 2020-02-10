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

#define WIDTH 50
#define HEIGHT 50

#define BLACK 0
#define WHITE 0xFFFFFF

typedef struct	s_vector
{
	int 		x1;
	int 		x2;
	int 		y1;
	int 		y2;
	int 		dx;
	int 		dy;
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
/*
	void 		*mlx; // delete
	void 		*win; // delete
	void 		*ptr; // delete
	char 		*data; // delete
	int			bpp; // delete
	int			endlian; // delete
	int			sizeline; // delete
*/
	t_mlx 		*mlx;
	
	int 		image_x; // delete 720
	int 		image_y; // delete 480

	t_parse		*map_lines;
	int			map_width; 
	int			map_height;
	int			line_cmp;
	int			**file;
	int			**tab;

	double 		x;
	double 		y;
	double 		xdir;
	double 		ydir;
	double		xplane;
	double		yplane;
	double 		oldx;
	int 		rows;
	int 		col;

	int 		bloc_width; //taille d'un bloc
	int 		bloc_height;
	int 		x2;
	int 		y2;
	
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

/*
** image.c
*/

void			put_pixel_color(t_env *e, int color, t_pos *pos);


void	wolf(t_env *e);
int		key_hook(int key, t_env *e);
int		mouse_hook(int key, int x, int y, t_env *e);
void	put_pixel(t_env *e, int x, int y, unsigned int c);
void	draw_grid(t_env *e);
// int		**make_tab(t_env *e, char *str);
// int		check_error(char *str, t_env *e);
// char	**split_white_space(char *str);
void	player_position(t_env *e);
int		param_init(t_env *e);
void	new_image(t_env *e);
t_env	*init_mlx(t_env *e);

#endif
