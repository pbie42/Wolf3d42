/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:02:23 by pbie              #+#    #+#             */
/*   Updated: 2016/03/28 17:07:32 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				ft_key_hit(int keycode, t_env *e)
{
	if (!e->check && (keycode == ONE || keycode))
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
	ft_settings(*e);
	return (0);
}
