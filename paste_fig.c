/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_answer		*make_new_board(t_answer *ans, t_filler *f)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	ans->new_board = (char **)malloc(sizeof(char *) * (f->b_height + 1));
	ans->new_board[f->b_height] = NULL;
	while (f->board[++i])
	{
		ans->new_board[i] = (char *)malloc(sizeof(char) * (f->b_wid + 1));
		ans->new_board[i][f->b_wid] = '\0';
		while (f->board[i][++j])
			ans->new_board[i][j] = f->board[i][j];
		j = -1;
	}
	return (ans);
}

static t_answer	*insert_fig(int *xy, int *ij, t_filler *f, t_answer *a)
{
	int		i;
	int		j;
	int		x;
	int		y;

	a->error = 0;
	make_new_board(a, f);
	i = -1;
	while (f->token[++i])
	{
		j = -1;
		while (f->token[i][++j])
			if (f->token[i][j] == '*')
			{
				if ((x = xy[0] + i - ij[0]) >= 0 && x < f->b_height && y >= 0 &&
					(y = xy[1] + j - ij[1]) < f->b_wid &&
					((i == ij[0] && j == ij[1]) || a->new_board[x][y] == '.'))
					a->new_board[x][y] = f->player;
				else
					a->error = -1;
				if (a->error == -1)
					return (a);
			}
	}
	return (a);
}

static t_answer	*find_answer(t_answer *ans, int *xy, t_filler *f, int *ij)
{
	ans->cur_distance = -1;
	insert_fig(xy, ij, f, ans);
	if (ans->error == 0)
	{
		calc_dist(ans, f);
		if (ans->distance == -2 || ans->cur_distance < ans->distance)
		{
			ans->distance = ans->cur_distance;
			ans->x_coord = xy[0] - ij[0];
			ans->y_coord = xy[1] - ij[1];
		}
	}
	return (ans);
}

t_answer		*paste_fig(int *xy, t_filler *str_filler, t_answer *ans)
{
	int	i;
	int	j;
	int ij[2];

	i = -1;
	while (str_filler->token[++i])
	{
		j = -1;
		while (str_filler->token[i][++j])
			if (str_filler->token[i][j] == '*')
			{
				ij[0] = i;
				ij[1] = j;
				find_answer(ans, xy, str_filler, ij);
				free(ans->new_board);
				if (ans->distance == 1 || ans->distance == 0)
					return (ans);
			}
	}
	return (ans);
}
