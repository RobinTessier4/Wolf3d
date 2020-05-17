/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:20:43 by alebui            #+#    #+#             */
/*   Updated: 2020/02/05 15:06:29 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	clean_map_lines(t_env *e)
{
	// printf("e->map_lines = %p\n", e->map_lines);
	if (e->map_lines)
	{
		while (e->map_lines)
		{
			free(e->map_lines->nums);
			e->map_lines->nums = NULL;
			e->map_lines = e->map_lines->next;
		}
	}
}

static void	clean_text(t_env *e)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (e->text[i].img)
		{
			// printf("Before: e->text[%d].img = %p\n", i, e->text[i].img);
			free(e->text[i].img);
			e->text[i].img = NULL;
			// printf("After: e->text[%d].img = %p\n", i, e->text[i].img);
		}
		if (e->text[i].data)
		{
			// printf("Before: e->text[%d].img = %p\n", i, e->text[i].data);
			free(e->text[i].data);
			e->text[i].data = NULL;
			// printf("After: e->text[%d].img = %p\n", i, e->text[i].data);
		}
		i++;
	}
}

static void	clean_vector(t_env *e)
{
	printf("attention je clean vector\n\n");
	if (e->dir)
	{
		// printf("Before: e->dir = %p\n", e->dir);
		free(e->dir);
		e->dir = NULL;
		// printf("After: e->dir = %p\n\n", e->dir);
	}
	if (e->plane)
	{
		// printf("Before: e->plane = %p\n", e->plane);
		free(e->plane);
		e->plane = NULL;
		// printf("After: e->plane = %p\n\n", e->plane);
	}
	if (e->lray)
	{
		// printf("Before: e->lray = %p\n", e->lray);
		free(e->lray);
		e->lray = NULL;
		// printf("After: e->lray = %p\n\n", e->lray);
	}
	if (e->rray)
	{
		// printf("Before: e->rray = %p\n", e->rray);
		free(e->rray);
		e->rray = NULL;
		// printf("After: e->rray = %p\n\n", e->rray);
	}
	// printf("j'ai clean\n");
}

void		exit_program(t_env *e)
{
	clean_map_lines(e);
	clean_vector(e);
	clean_text(e);
	exit(EXIT_SUCCESS);
}