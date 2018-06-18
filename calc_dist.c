/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	t_answer	*find_min_dist(t_answer *ans, t_filler *f, int x, int y)
{
	int		i;
	int		j;
	char	fig;
	int		dist;

	fig = f->player == 'X' ? 'O' : 'X';
	i = -1;
	while (ans->new_board[++i])
	{
		j = -1;
		while (ans->new_board[i][++j])
		{
			if (ans->new_board[i][j] == fig)
			{
				dist = ABS(x - i) + ABS(y - j);
				if (ans->cur_distance == -1 || dist < ans->cur_distance)
					ans->cur_distance = dist;
			}
		}
	}
	return (ans);
}

t_answer			*calc_dist(t_answer *ans, t_filler *f)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (ans->new_board[++i])
	{
		while (ans->new_board[i][++j])
		{
			if (ans->new_board[i][j] == f->player)
				find_min_dist(ans, f, i, j);
		}
		j = -1;
	}
	return (ans);
}
