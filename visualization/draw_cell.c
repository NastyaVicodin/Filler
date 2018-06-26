/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int				put_color_x(void **mlx_win, int *xy, int color, int loop)
{
	int k;

	k = -1;
	while (++k < loop)
	{
		xy[1] = -1;
		while (++xy[1] < 1000)
			mlx_pixel_put(mlx_win[0], mlx_win[1], xy[1], xy[0], color);
		xy[0]++;
	}
	return (xy[0]);
}

int				put_color_y(void **mlx_win, int *xy, int color, int loop)
{
	int k;

	k = -1;
	while (++k < loop)
	{
		mlx_pixel_put(mlx_win[0], mlx_win[1], xy[1], xy[0], color);
		xy[1]++;
	}
	return (xy[1]);
}

int				*draw_cell(void **mlx_win, int *xy, t_filler *f, t_vis *v)
{
	int g;
	int j;

	g = -1;
	while (++g < v->size_cell)
	{
		j = -1;
		xy[1] = -1;
		v->b_y = 0;
		while (++j < f->b_wid)
		{
			xy[1] = put_color_y(mlx_win, xy, 0xB0C4DE, 3);
			if (f->board[v->b_x][v->b_y] == '.')
				xy[1] = put_color_y(mlx_win, xy, 0x87CEEB, v->size_cell);
			else if (f->board[v->b_x][v->b_y] == 'X'
					|| f->board[v->b_x][v->b_y] == 'x')
				xy[1] = put_color_y(mlx_win, xy, 0x4169E1, v->size_cell);
			else
				xy[1] = put_color_y(mlx_win, xy, 0x7B68EE, v->size_cell);
			v->b_y++;
		}
		xy[1] = put_color_y(mlx_win, xy, 0xB0C4DE, 1000 - v->size_wid + 4);
		xy[0]++;
	}
	return (xy);
}
