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
	ans->distance = -1;
	//ans->cur_distance = 2000000;
	//write(2, "--------------\n", 15);
	while (str_filler->board[++i])
	{
		while (str_filler->board[i][++j])
			if (str_filler->board[i][j] == str_filler->player)
			{
				//write(2, "--------------\n", 15);
				xy[0] = i;
				xy[1] = j;
				paste_fig(xy, str_filler, ans);
			}
		j = -1;
	}
	//write(2, "--------------\n", 15);
	// write(2, ft_itoa(loop_count), ft_strlen(ft_itoa(loop_count)));
	// write(2, "\n", 1);
	// write(2, "--------------\n", 15);
	//make_answer(ans, str_filler);
	ft_printf("%d %d\n", ans->x_coord, ans->y_coord);
	//free(ans->new_board);
	free(ans);
}

int			main(void)
{
	t_filler	*str_filler;
	int i;
	str_filler = make_struct();
	read_player(str_filler);
	while (str_filler->b_wid)
	{
		str_filler->b_wid = 0;

		read_board(str_filler);
		i = 0;
		// write(2, "\x1B[31m", 6);
		// write(2, "-----\n", 6);
		// write(2, "BOARD\n", 6);
		// while (str_filler->board[i])
		// {
		// 	write(2, str_filler->board[i], ft_strlen(str_filler->board[i]));
		// 	write(2, "\n", 1);
		// 	i++;
		// }
		// write(2, "-----\n", 6);
		// write(2, "\x1B[0m", 5);
		// write(2, "--------------\n", 15);
		// write(2, ft_itoa(str_filler->b_wid), ft_strlen(ft_itoa(str_filler->b_wid)));
		// write(2, "\n", 1);
		//write(2, "--------------\n", 15);
		if (str_filler->b_wid)
		{
			//write(2, "--------------\n", 15);
			read_token(str_filler);
			//write(2, "--------------\n", 15);
			print_answer(str_filler);
			free(str_filler->board);
			free(str_filler->token);
		}
	}
	free(str_filler);
	return (0);
}
