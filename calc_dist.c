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

t_answer *find_min_dist(t_answer *ans, t_filler *str_filler, int x, int y)
{
	int		i;
	int		j;
	char	fig;
	int		k;
	int		dist;

	k = 0;
	fig = str_filler->player == 'X' ? 'O' : 'X';
	i = -1;
	j = -1;
	while (ans->new_board[++i])
	{
		while (ans->new_board[i][++j])
		{
			if (ans->new_board[i][j] == fig)
			{
				dist = ABS(x - i) + ABS(y - j);
				if (k == 0 || dist < ans->cur_distance)
				{
					ans->cur_distance = dist;
					k++;
				}
				
				//ans->cur_distance = dist < ans->distance ? dist : ;
				// ans->x_coord = dist < ans->distance ? cf[0] : ans->x_coord;
				// ans->y_coord = dist < ans->distance ? cf[1] : ans->y_coord;
			}
		}
		j = -1;
	}
	return (ans);
}

t_answer *calc_dist(t_answer *ans, t_filler *f, int *cf)
{
	int		i;
	int		j;
	(void)cf;
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
