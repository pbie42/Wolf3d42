/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:33:59 by pbie              #+#    #+#             */
/*   Updated: 2016/03/28 18:13:32 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_rotate(t_env *e, int advance)
{
	double		dir;
	double		plane;

	dir = e->dir.x;
	plane = e->rplane.x;
	e->dir.x = e->dir.x * cos(advance * 0.1)
		- e->dir.y sin(advance * 0.1);
	e->dir.y = e->dir * sin(advance * 0.1)
}
