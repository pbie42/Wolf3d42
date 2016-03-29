/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:27:54 by pbie              #+#    #+#             */
/*   Updated: 2016/03/29 17:27:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_X 1280
# define WIN_Y 800

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define A 0
# define D 2
# define W 13
# define S 1
# define H 4
# define M 46
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS1 24
# define PLUS2 69
# define MINUS1 27
# define MINUS2 78
# define RETURN 36
# define ENTER 76
# define ONE1 18
# define ONE2 83
# define TWO1 19
# define TWO2 84
# define THREE1 20
# define THREE2 85
# define ESC 53

# define MAP1 "maps/map01.w3d"
# define MAP2 "maps/map02.w3d"
# define MAP3 "maps/map03.w3d"
# define SKY "textures/sky.xpm"

# define COLOR_SKY 0x007fff
# define COLOR_FLOOR 0x4E1619
# define COLOR_NORTH 0x233F67
# define COLOR_SOUTH 0x655077
# define COLOR_EAST 0x68C0B9
# define COLOR_WEST 0x936C83

# define WELCOME "Wolf3d by pbie"
# define SELECT "Please Select Maze Difficulty"
# define EASY "1 for Easy"
# define MEDIUM "2 for Medium"
# define HARD "3 for Hard"

# define L_CONTROLS "         CONTROL "
# define L_UP "|Forward    |  Up or W  |"
# define L_DOWN "|Backward   | Down or S |"
# define L_LEFT "|Turn Left  | Left or A |"
# define L_RIGHT "|Turn Right | Right or D|"
# define L_PLUS "|Speed Up   |     +     |"
# define L_MINUS "|Slow Down  |     -     |"
# define L_MAP "|Hide Map   |     M     |"
# define L_HIDE "|Hide This  |     H     |"
# define L_RESET "|Start Over |   Enter   |"
# define L_LINE " -----------------------"
# define L_ESC "|Quit Game  |    Esc    |"

# include "../minilibx_macros/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/includes/libft.h"

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
	int						set;
	int						mini;

}							t_env;

void						ft_parse(t_env *e, char *line);
void						ft_put_help(t_env e);
int							ft_key_hit(int keycode, t_env *e);
int							ft_key_release(int keycode, t_env *e);
int							ft_core(t_env *e);
void						ft_disp_screen(t_env *e);
void						ft_ray_size(t_env *e);
void						ft_ray_hit(t_env *e);
void						ft_ray_direction(t_env *e);
void						ft_init_ray(t_env *e, int x);
void						ft_move(t_env *e);
void						ft_draw_map(t_env *e);
void						ft_init(t_env *e);
void						ft_welcome(t_env *e);
void						ft_controls(t_env *e);

#endif
