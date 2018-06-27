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

static int		draw_board(void *vis)
{
	int			i;
	int			xy[2];
	t_filler	*f;
	t_vis		*v;

	v = (t_vis *)vis;
	f = make_struct();
	xy[0] = 0;
	i = -1;
	v->b_x = 0;
	read_board_vis(f, v);
	if (f->b_wid != 0)
	{
		count_sizes(f, v);
		while (++i < f->b_height)
		{
			xy[0] = put_color_x(v, xy, 0xB0C4DE, 3);
			draw_cell(xy, f, v);
			v->b_x++;
		}
		xy[0] = put_color_x(v, xy, 0xB0C4DE, 1000 - v->size_heig + 4);
		free_array(f->board);
	}
	free(f);
	return (0);
}

static	int		key(int num, void *vis)
{
	t_vis		*v;

	v = (t_vis *)vis;
	if (num == 53)
	{
		free(v->pl_x);
		free(v->pl_o);
		free(v);
		exit(1);
	}
	return (0);
}

int				main(void)
{
	t_vis	*v;

	v = (t_vis *)malloc(sizeof(t_vis));
	read_player_vis(v);
	read_player_vis(v);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, 1000, 1050, "Filler");
	mlx_string_put(v->mlx, v->win, 200, 1010, 0x7B68EE, v->pl_o);
	mlx_string_put(v->mlx, v->win, 700, 1010, 0x4169E1, v->pl_x);
	mlx_loop_hook(v->mlx, draw_board, v);
	mlx_key_hook(v->win, key, v);
	mlx_loop(v->mlx);
	return (0);
}
