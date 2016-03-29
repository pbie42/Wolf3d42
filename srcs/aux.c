/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:44:05 by pbie              #+#    #+#             */
/*   Updated: 2016/03/29 18:50:39 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_welcome(t_env *e)
{
	int			x;
	int			y;

	x = 510;
	y = 200;
	mlx_string_put(e->mlx, e->win, x, y, 0x009999FF, WELCOME);
	mlx_string_put(e->mlx, e->win, x, y + 20, 0x009999FF, SELECT);
	mlx_string_put(e->mlx, e->win, x, y + 50, 0x009999FF, EASY);
	mlx_string_put(e->mlx, e->win, x, y + 70, 0x009999FF, MEDIUM);
	mlx_string_put(e->mlx, e->win, x, y + 90, 0x009999FF, HARD);
}

void			ft_controls(t_env *e)
{
	int			x;

	x = 990;
	if (e->set == 0)
	{
		mlx_string_put(e->mlx, e->win, x, 16, 0xccccff, L_CONTROLS);
		mlx_string_put(e->mlx, e->win, x, 24, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 32, 0xccccff, L_UP);
		mlx_string_put(e->mlx, e->win, x, 40, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 48, 0xccccff, L_DOWN);
		mlx_string_put(e->mlx, e->win, x, 56, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 64, 0xccccff, L_LEFT);
		mlx_string_put(e->mlx, e->win, x, 72, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 80, 0xccccff, L_RIGHT);
		mlx_string_put(e->mlx, e->win, x, 88, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 96, 0xccccff, L_PLUS);
		mlx_string_put(e->mlx, e->win, x, 104, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 112, 0xccccff, L_MINUS);
		mlx_string_put(e->mlx, e->win, x, 120, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 128, 0xccccff, L_MAP);
		mlx_string_put(e->mlx, e->win, x, 136, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 144, 0xccccff, L_HIDE);
		mlx_string_put(e->mlx, e->win, x, 152, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 160, 0xccccff, L_EASY);
		mlx_string_put(e->mlx, e->win, x, 168, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 176, 0xccccff, L_MEDIUM);
		mlx_string_put(e->mlx, e->win, x, 184, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 192, 0xccccff, L_HARD);
		mlx_string_put(e->mlx, e->win, x, 200, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 208, 0xccccff, L_RESET);
		mlx_string_put(e->mlx, e->win, x, 216, 0xccccff, L_LINE);
		mlx_string_put(e->mlx, e->win, x, 224, 0xccccff, L_ESC);
		mlx_string_put(e->mlx, e->win, x, 232, 0xccccff, L_LINE);
	}
}
