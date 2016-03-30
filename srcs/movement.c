/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:33:59 by pbie              #+#    #+#             */
/*   Updated: 2016/03/30 13:10:40 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_rotate(t_env *e, int advance)
{
	double		dir;
	double		plane;

	dir = e->dir.x;
	plane = e->rplane.x;
	e->dir.x = e->dir.x * cos(advance * 0.1) - e->dir.y * sin(advance * 0.1);
	e->dir.y = dir * sin(advance * 0.1) + e->dir.y * cos(advance * 0.1);
	e->rplane.x = e->rplane.x * cos(advance * 0.1)
		- e->rplane.y * sin(advance * 0.1);
	e->rplane.y = plane * sin(advance * 0.1) + e->rplane.y * cos(advance * 0.1);
}

void			ft_move(t_env *e)
{
	if (e->up == 1)
	{
		if (!(e->map[(int)(e->pos.x + e->dir.x * e->speed)][(int)(e->pos.y)]))
			e->pos.x += e->dir.x * e->speed;
		if (!(e->map[(int)(e->pos.x)][(int)(e->pos.y + e->dir.y * e->speed)]))
			e->pos.y += e->dir.y * e->speed;
	}
	if (e->left == 1)
		ft_rotate(e, 1);
	if (e->right == 1)
		ft_rotate(e, -1);
	if (e->down == 1)
	{
		if (!(e->map[(int)(e->pos.x - e->dir.x * e->speed)][(int)(e->pos.y)]))
			e->pos.x -= e->dir.x * e->speed;
		if (!(e->map[(int)(e->pos.x)][(int)(e->pos.y - e->dir.y * e->speed)]))
			e->pos.y -= e->dir.y * e->speed;
	}
}
