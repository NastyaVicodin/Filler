/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static t_filler	*make_struct(void)
{
	t_filler	*str_filler;

	str_filler = (t_filler *)malloc(sizeof(t_filler));
	str_filler->b_wid = 1;
	str_filler->b_height = 0;
	return (str_filler);
}

static t_vis	*count_sizes(t_filler *str_filler, t_vis *v)
{
	v->size_cell = (1000 - 3) / str_filler->b_height - 3;
	v->size_wid = (v->size_cell + 3) * str_filler->b_wid + 3;
	if (v->size_wid > 1000)
	{
		v->size_cell = (1000 - 3) / str_filler->b_wid - 3;
		v->size_wid = (v->size_cell + 3) * str_filler->b_wid + 3;
	}
	v->size_heig = (v->size_cell + 3) * str_filler->b_height + 3;
	return (v);
}

static int		draw_board(void **mlx_win, t_filler *f, t_vis *v)
{
	int	i;
	int	xy[2];

	while (1)
	{
		mlx_string_put(mlx_win[0], mlx_win[1], 200, 1010, 0x7B68EE, f->pl_o);
		mlx_string_put(mlx_win[0], mlx_win[1], 700, 1010, 0x4169E1, f->pl_x);
		xy[0] = 0;
		i = -1;
		v->b_x = 0;
		read_board_vis(f, mlx_win);
		if (f->b_wid == 0)
			break ;
		count_sizes(f, v);
		while (++i < f->b_height)
		{
			xy[0] = put_color_x(mlx_win, xy, 0xB0C4DE, 3);
			draw_cell(mlx_win, xy, f, v);
			v->b_x++;
		}
		xy[0] = put_color_x(mlx_win, xy, 0xB0C4DE, 1000 - v->size_heig + 4);
		f->board ? free_array(f->board) : 0;
	}
	free(f->pl_x);
	free(f->pl_o);
	free(f);
	free(v);
	return (0);
}
// static	int		key(int num, void **mlx_win)
// {
// 	(void)mlx_win;
// 	if (num == 53)
// 	{
// 		exit(1);
// 	}
// 	return (0);
// }
int				main(void)
{
	void		*mlx_win[2];
	t_vis		*v;
	t_filler	*f;

	mlx_win[0] = mlx_init();
	mlx_win[1] = mlx_new_window(mlx_win[0], 1000, 1050, "Filler");
	f = make_struct();
	v = (t_vis *)malloc(sizeof(t_vis));
	read_player_vis(f);
	read_player_vis(f);
	draw_board(mlx_win, f, v);
	//mlx_loop_hook(mlx_win[0], draw_board, mlx_win);
	//mlx_key_hook(mlx_win[0], key, &mlx_win);
	mlx_loop(mlx_win[0]);
	return (0);
}
