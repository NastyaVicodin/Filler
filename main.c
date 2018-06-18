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

#include "filler.h"

t_filler	*make_struct(void)
{
	t_filler	*str_filler;

	str_filler = (t_filler *)malloc(sizeof(t_filler));
	str_filler->b_wid = 1;
	str_filler->b_height = 0;
	return (str_filler);
}

void		print_answer(t_filler *str_filler)
{
	int			i;
	t_answer	*ans;
	int			j;
	int			xy[2];

	i = -1;
	j = -1;
	ans = (t_answer *)malloc(sizeof(t_answer));
	ans->x_coord = -1;
	ans->y_coord = -1;
	ans->distance = -2;
	while (str_filler->board[++i])
	{
		while (str_filler->board[i][++j])
			if (str_filler->board[i][j] == str_filler->player)
			{
				xy[0] = i;
				xy[1] = j;
				paste_fig(xy, str_filler, ans);
			}
		j = -1;
	}
	ft_printf("%d %d\n", ans->x_coord, ans->y_coord);
	free(ans);
}

int			main(void)
{
	t_filler	*str_filler;

	str_filler = make_struct();
	read_player(str_filler);
	while (str_filler->b_wid)
	{
		str_filler->b_wid = 0;
		read_board(str_filler);
		if (str_filler->b_wid)
		{
			read_token(str_filler);
			print_answer(str_filler);
			free(str_filler->board);
			free(str_filler->token);
		}
	}
	free(str_filler);
	return (0);
}
