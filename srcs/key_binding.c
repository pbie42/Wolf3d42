/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:02:23 by pbie              #+#    #+#             */
/*   Updated: 2016/03/29 18:44:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_mapset_check(int keycode, t_env *e)
{
	if (keycode == H)
		e->set = (e->set == 0 ? 1 : 0);
	if (keycode == M)
		e->mini = (e->mini == 0 ? 1 : 0);
	if (e->check && (keycode == ONE1 || keycode == ONE2))
	{
		ft_parse(e, MAP1);
		ft_init(e);
	}
	if (e->check && (keycode == TWO1 || keycode == TWO2))
	{
		ft_parse(e, MAP2);
		ft_init(e);
	}
	if (e->check && (keycode == THREE1 || keycode == THREE2))
	{
		ft_parse(e, MAP3);
		ft_init(e);
	}
}

int				ft_key_hit(int keycode, t_env *e)
{
	if (!e->check && (keycode == ONE1 || keycode == ONE2))
		ft_parse(e, MAP1);
	if (!e->check && (keycode == TWO1 || keycode == TWO2))
		ft_parse(e, MAP2);
	if (!e->check && (keycode == THREE1 || keycode == THREE2))
		ft_parse(e, MAP3);
	ft_mapset_check(keycode, e);
	if (keycode == W || keycode == UP)
		e->up = 1;
	if (keycode == S || keycode == DOWN)
		e->down = 1;
	if (keycode == A || keycode == LEFT)
		e->left = 1;
	if (keycode == D || keycode == RIGHT)
		e->right = 1;
	if ((keycode == MINUS1 || keycode == MINUS2) && e->speed > 0.02)
		e->speed -= 0.01;
	if ((keycode == PLUS1 || keycode == PLUS2) && e->speed < 0.3)
		e->speed += 0.01;
	if (keycode == RETURN || keycode == ENTER)
		ft_init(e);
	if (keycode == ESC)
		exit(1);
	return (0);
}

int				ft_key_release(int keycode, t_env *e)
{
	if (keycode == W || keycode == UP)
		e->up = 0;
	if (keycode == S || keycode == DOWN)
		e->down = 0;
	if (keycode == A || keycode == LEFT)
		e->left = 0;
	if (keycode == D || keycode == RIGHT)
		e->right = 0;
	return (0);
}

int				ft_core(t_env *e)
{
	if (e->check == 0)
		return (0);
	mlx_destroy_image(e->mlx, e->img.im);
	e->img.im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_move(e);
	ft_disp_screen(e);
	ft_draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->sky.im, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img.im, 0, 0);
	ft_controls(e);
	return (0);
}
