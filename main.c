/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:55:48 by pbie              #+#    #+#             */
/*   Updated: 2016/03/25 16:42:57 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "wolf3d");
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->imc = mlx_get_data_addr(e->im, &e->bpp, &e->imlen, &e->endi);
	e->pos.x = 2;
	e->pos.y = 2;
	e->dir.x = 1;
	e->dir.y = 0;
	e->rplane.x = 0;
	e->rplane.y = -0.80;
	e->speed = 0.1;
}

int		main(int ac, char **av)
{
	t_env e;

	e.check = 0;
	ac != 2 ? ft_error("error wrong number of arguments") : ft_parse(&e, av[1]);
	ft_init(&e);
	mlx_string_put(e.mlx, e.win, 760, 250, 0xccccff, WELCOME);
	mlx_string_put(e.mlx, e.win, 760, 279, 0xccccff, PRESS);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &e);
	mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &e);
	mlx_loop_hook(e.mlx, ft_core, &e);
	mlx_loop(e.mlx);
	return (0);
}
