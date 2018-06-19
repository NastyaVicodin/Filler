/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_high_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_answer	*paste_fig_hl(int *xy, t_filler *str_filler, t_answer *ans)
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
				insert_fig(xy, ij, str_filler, ans);
				if (ans->error == 0)
				{
					ans->x_coord = xy[0] - ij[0];
					ans->y_coord = xy[1] - ij[1];
				}
				free(ans->new_board);
			}
	}
	return (ans);
}

static t_answer	*paste_high(t_filler *filler, t_answer *ans, t_where *w)
{
	int		i;
	int		j;
	int		xy[2];

	i = w->sten_you[1];
	while (filler->board[i])
	{
		j = -1;
		while (filler->board[i][++j])
		{
			if (filler->board[i][j] == filler->player)
			{
				xy[0] = i;
				xy[1] = j;
				paste_fig_hl(xy, filler, ans);
			}
		}
		i--;
	}
	return (ans);
}

static t_answer	*paste_low(t_filler *filler, t_answer *ans)
{
	int		i;
	int		j;
	int		xy[2];

	i = -1;
	while (filler->board[++i])
	{
		j = -1;
		while (filler->board[i][++j])
		{
			if (filler->board[i][j] == filler->player)
			{
				xy[0] = i;
				xy[1] = j;
				paste_fig_hl(xy, filler, ans);
			}
		}
	}
	return (ans);
}

t_answer		*paste_high_low(t_filler *f, t_answer *ans, t_where *w)
{
	if (w->you == 'h')
		paste_high(f, ans, w);
	else if (w->you == 'l')
		paste_low(f, ans);
	return (ans);
}
