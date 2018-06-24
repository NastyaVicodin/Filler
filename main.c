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

static t_filler	*make_struct(void)
{
	t_filler	*str_filler;

	str_filler = (t_filler *)malloc(sizeof(t_filler));
	str_filler->b_wid = 1;
	str_filler->b_height = 0;
	return (str_filler);
}

void			free_array(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	if (arr)
		free(arr);
}

static t_answer	*paste_manhattan(t_filler *str_filler, t_answer *ans)
{
	int			i;
	int			j;
	int			xy[2];

	i = -1;
	while (str_filler->board[++i])
	{
		j = -1;
		while (str_filler->board[i][++j])
			if (str_filler->board[i][j] == str_filler->player)
			{
				xy[0] = i;
				xy[1] = j;
				paste_fig(xy, str_filler, ans);
			}
	}
	return (ans);
}

static void		print_answer(t_filler *str_filler)
{
	t_answer	*ans;
	t_where		*w;

	ans = (t_answer *)malloc(sizeof(t_answer));
	w = (t_where *)malloc(sizeof(t_where));
	w->sten_you[0] = str_filler->b_height;
	w->sten_you[1] = 0;
	w->sten_he[0] = str_filler->b_height;
	w->sten_he[1] = 0;
	ans->x_coord = -1;
	ans->y_coord = -1;
	ans->distance = -2;
	paste_manhattan(str_filler, ans);
	ft_printf("%d %d\n", ans->x_coord, ans->y_coord);
	free(ans);
	free(w);
}

int				main(void)
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
			free_array(str_filler->board);
			free_array(str_filler->token);
		}
	}
	free(str_filler);
	return (0);
}
