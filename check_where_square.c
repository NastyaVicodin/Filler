/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_where_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_where	*calculate_where(t_where *w, t_filler *str_filler)
{
	int		half_height;

	half_height = str_filler->b_height / 2;
	if (w->sten_you[1] > half_height && w->sten_you[0] > half_height)
		w->you = 'l';
	if (w->sten_you[1] < half_height && w->sten_you[0] < half_height)
		w->you = 'h';
	if (w->sten_he[1] > half_height && w->sten_he[0] > half_height)
		w->he = 'l';
	if (w->sten_he[1] < half_height && w->sten_he[0] < half_height)
		w->he = 'h';
	w->res = w->he != w->you ? 'y' : 'n';
	return (w);
}

t_where			*check_where_square(t_filler *str_filler, t_where *w)
{
	int			i;
	int			j;
	char		enemy;

	enemy = str_filler->player == 'X' ? 'O' : 'X';
	i = -1;
	while (str_filler->board[++i])
	{
		j = -1;
		while (str_filler->board[i][++j])
		{
			if (str_filler->board[i][j] == str_filler->player)
			{
				w->sten_you[0] = w->sten_you[0] < i ? w->sten_you[0] : i;
				w->sten_you[1] = w->sten_you[1] < i ? i : w->sten_you[1];
			}
			if (str_filler->board[i][j] == enemy)
			{
				w->sten_he[0] = w->sten_he[0] < i ? w->sten_he[0] : i;
				w->sten_he[1] = w->sten_he[1] < i ? i : w->sten_he[1];
			}
		}
	}
	calculate_where(w, str_filler);
	return (w);
}
