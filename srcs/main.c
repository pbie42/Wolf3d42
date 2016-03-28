/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:55:48 by pbie              #+#    #+#             */
/*   Updated: 2016/03/28 16:56:46 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_init(t_env *e)
{
	int			win_x;
	int			win_y;

	win_x = WIN_X;
	win_y = WIN_Y / 2;
	e->pos.x = 2.001;
	e->pos.y = 2.001;
	e->dir.x = 1;
	e->dir.y = 0;
	e->rplane.x = 0;
	e->rplane.y = -0.80;
	e->speed = 0.1;
	e->sky.im = mlx_xpm_file_to_image(e->mlx, SKY, &win_x, &win_y);
	e->sky.imc = mlx_get_data_addr(e->sky.im, &e->sky.bpp, &e->sky.imlen,
			&e->sky.endi);
}

int				main(void)
{
	t_env e;

	e.check = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "wolf3d");
	e.img.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	e.img.imc = mlx_get_data_addr(e.img.im, &e.img.bpp, &e.img.imlen,
			&e.img.endi);
	ft_welcome(e);
	ft_init(&e);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &e);
	mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &e);
	mlx_loop_hook(e.mlx, ft_core, &e);
	mlx_loop(e.mlx);
	return (0);
}
