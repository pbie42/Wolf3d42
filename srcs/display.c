/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:14:02 by pbie              #+#    #+#             */
/*   Updated: 2016/03/29 16:47:29 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_put_pixel(t_env *e, int x, int y, int color)
{
	int			*tmp;

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->img.imc[(y * e->img.imlen) + (x * (e->img.bpp / 8))];
	*tmp = color;
}

static void		ft_disp_vert(t_env *e, int x)
{
	int			y;

	y = 0;
	while (y < e->wstart)
		ft_put_pixel(e, x, y++, 0xC00000A0);
	while (y >= e->wstart && y <= e->wend)
		ft_put_pixel(e, x, y++, e->color);
	while (y < WIN_Y)
		ft_put_pixel(e, x, y++, COLOR_FLOOR);
}

void			ft_disp_screen(t_env *e)
{
	int			x;

	x = 0;
	while (x < WIN_X)
	{
		ft_init_ray(e, x);
		ft_ray_direction(e);
		ft_ray_hit(e);
		ft_ray_size(e);
		if (e->wall == 0)
			e->color = (e->step.x < 0 ? COLOR_NORTH : COLOR_SOUTH);
		else
			e->color = (e->step.y > 0 ? COLOR_EAST : COLOR_WEST);
		ft_disp_vert(e, x++);
	}
}

static void		ft_draw_map_coord(t_env *e, int x, int y, int color)
{
	int			i;
	int			j;

	i = -1;
	while (++i <= 5)
	{
		j = -1;
		while (++j <= 5)
			ft_put_pixel(e, x + i, y + j, color);
	}
}

void			ft_draw_map(t_env *e)
{
	int			i;
	int			j;

	if (e->cnt_col * 5 > WIN_X / 2 || e->cnt_line * 5 > WIN_Y / 2)
		return ;
	i = -1;
	if (e->mini == 0)
	{
		while (++i < e->cnt_col)
		{
			j = -1;
			while (++j < e->cnt_line)
			{
				if (e->map[j][i] == 1)
					ft_draw_map_coord(e, i + (5 * (i + 1)), j + (5 * (j + 1)),
							0x000000);
				else if ((int)e->pos.x == j && (int)e->pos.y == i)
					ft_draw_map_coord(e, i + (5 * (i + 1)), j + (5 * (j + 1)),
							0xFF0000);
				else
					ft_draw_map_coord(e, i + (5 * (i + 1)), j + (5 * (j + 1)),
							0xFFFFFF);
			}
		}
	}
}
