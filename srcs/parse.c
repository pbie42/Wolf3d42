/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:14:29 by pbie              #+#    #+#             */
/*   Updated: 2016/03/30 13:09:30 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_freestr2d(t_env *e)
{
	int			i;

	i = 0;
	while (e->line[i])
	{
		ft_strdel(&(e->line[i]));
		++i;
	}
	ft_strdel(&(e->line[i]));
	free(e->line);
}

int				ft_split_line(t_env *e)
{
	char		*line;
	int			ret;

	ret = 0;
	if (ft_get_next_line(e->fd, &line) == 1)
	{
		e->line = ft_strsplit(line, ' ');
		free(line);
		++ret;
	}
	return (ret);
}

void			ft_int2d(t_env *e, char *file)
{
	char		*line;
	int			len;

	e->cnt_col = 0;
	e->cnt_line = 0;
	while (ft_get_next_line(e->fd, &line) == 1)
	{
		++e->cnt_line;
		len = ft_strlen(line);
		free(line);
	}
	free(line);
	if (e->cnt_line == 0 || len == 0)
		ft_exit("Error: Failed to Read File!");
	e->map = (int **)ft_memalloc(sizeof(int *) * e->cnt_line);
	close(e->fd);
	e->fd = open(file, O_RDONLY);
	ft_split_line(e);
	while (e->line[e->cnt_col])
		++e->cnt_col;
	while (e->cnt_line > 0)
	{
		e->map[e->cnt_line - 1] = (int *)ft_memalloc(sizeof(int) * e->cnt_col);
		--e->cnt_line;
	}
}

void			ft_parse(t_env *e, char *file)
{
	int			nbr_col;

	nbr_col = 0;
	if ((e->fd = open(file, O_RDONLY)) <= 0)
		ft_exit("Error: Failed to Open File!");
	ft_int2d(e, file);
	while (nbr_col < e->cnt_col)
	{
		e->map[0][nbr_col] = ft_atoi(e->line[nbr_col]);
		++nbr_col;
	}
	ft_freestr2d(e);
	while (ft_split_line(e) == 1)
	{
		++e->cnt_line;
		nbr_col = -1;
		while (e->line[++nbr_col])
			e->map[e->cnt_line][nbr_col] = ft_atoi(e->line[nbr_col]);
		if (nbr_col != e->cnt_col)
			ft_exit("Error: Invalid Map!");
	}
	++e->cnt_line;
	e->check = 1;
}
