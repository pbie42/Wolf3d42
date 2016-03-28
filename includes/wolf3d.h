/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:27:54 by pbie              #+#    #+#             */
/*   Updated: 2016/03/28 17:33:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_X 1900
# define WIN_Y 1400

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define LEFT 0
# define RIGHT 2
# define UP 13
# define DOWN 1
# define PLUS 69
# define MINUS 78
# define STAR 67
# define SLASH 75
# define PAGE_UP 116
# define PAGE_DOWN 121
# define ZERO 82
# define ESC 53

# define SKY "textures/sky.xpm"

# define COLOR_SKY 0x007fff
# define COLOR_FLOOR 0x008000
# define COLOR_NORTH 0Xc90016
# define COLOR_SOUTH 0xff9f00
# define COLOR_EAST 0X682860
# define COLOR_WEST 0X746cc0

# define WELCOME "Wolf3d by pbie"
# define PRESS "Press any key to start"

# define CONTROLS "#      CONTROLS "
# define H_UP "     move up    |    up"
# define H_DOWN "    move down   |   down"
# define H_LEFT "    move left   |   left"
# define H_RIGHT "   move right   |   right"
# define H_PLUS "    zoom in     |     +"
# define H_MINUS "    zoom out    |     -"
# define H_STAR "increase height |     *"
# define H_SLASH "decrease height |     /"
# define H_PAGE_UP "   next colors  | page up"
# define H_PAGE_DOWN "previous colors | page down"
# define H_ZERO "     reset      |     0"
# define H_ESC "  exit program  |    esc"

# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/includes/libft.h"

typedef struct				s_xy
{
	int						x;
	int						y;
}							t_xy;

typedef struct				s_dxy
{
	double					x;
	double					y;
}							t_dxy;

typedef struct				s_img
{
	void					*im;
	char					*imc;
	int						imlen;
	int						bpp;
	int						endi;
}							t_img;

typedef struct				s_env
{
	char					*choice;
	int						fd;
	char					**line;
	int						cnt_line;
	int						cnt_col;
	int						**map;
	int						check;

	void					*mlx;
	void					*win;
	int						color;

	t_img					img;
	t_img					sky;

	double					camera;
	int						wall;
	int						hit;

	t_dxy					pos;
	t_dxy					dir;
	t_dxy					rplane;
	t_dxy					rpos;
	t_dxy					rdir;
	t_dxy					rdist;
	t_dxy					rdisd;
	t_xy					rmap;
	t_xy					step;
	int						wstart;
	int						wend;
	int						rh;

	double					speed;
	int						left;
	int						right;
	int						up;
	int						down;

}							t_env;

void						ft_parse(t_env *e, char *line);
void						ft_put_help(t_env e);
static void						ft_put_pixel(t_env *e, int x, int y, int color);
int							ft_key_hit(int keycode, t_env *e);
int							ft_key_release(int keycode, t_env *e);
int							ft_core(t_env *e);
void						ft_disp_screen(t_env *e);
void						ft_ray_size(t_env *e);
void						ft_ray_hit(t_env *e);
void						ft_ray_direction(t_env *e);
void						ft_init_ray(t_env *e, int x);
void						ft_move(t_env *e);

#endif
