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

t_answer	*make_new_board(t_answer *ans, t_filler *f)
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

t_answer	*insert_fig(int *xy, int *ij, t_filler *str_filler, t_answer *ans)
{
	int		i;
	int		j;
	int k;
	ans->error = 0;
	make_new_board(ans, str_filler);
	//write(2, "***********************\n", 24);
	i = -1;
	j = -1;
	while (str_filler->token[++i])
	{
		while(str_filler->token[i][++j])
			if (str_filler->token[i][j] == '*')
			{
				if ((xy[0] + i - ij[0]) >= 0 && (xy[0] + i - ij[0]) < str_filler->b_height &&
					(xy[1] + j - ij[1]) >= 0 && (xy[1] + j - ij[1]) < str_filler->b_wid &&
					((i == ij[0] && j == ij[1]) || ans->new_board[xy[0] + i - ij[0]][xy[1] + j - ij[1]] == '.'))
				{
					ans->new_board[xy[0] + i - ij[0]][xy[1] + j - ij[1]] = str_filler->player;
					k = 0;
					// write(2, "\x1B[32m", 6);
					// write(2, "-----\n", 6);
					// write(2, "NEW BOARD\n", 10);
					// while (ans->new_board[k])
					// {
					// 	write(2, ans->new_board[k], ft_strlen(ans->new_board[k]));
					// 	write(2, "\n", 1);
					// 	k++;
					// }
					// write(2, "-----\n", 6);
					// write(2, "\x1B[0m", 5);
				}
				else
				{
					ans->error = -1;
					free(ans->new_board);
					return (ans);
				}
			}
		j = -1;
	}
	return (ans);
}

t_answer	*paste_fig(int *xy, t_filler *str_filler, t_answer *ans)
{
	int	i;
	int	j;
	int ij[2];
	//int k;
	//int dist; 
	i = -1;
	j = -1;//ans->distance = 2147483647;
	//k = 0;
	while (str_filler->token[++i])
	{
		while(str_filler->token[i][++j])
			if (str_filler->token[i][j] == '*')
			{
				ans->cur_distance = 0;
				ij[0] = i;
				ij[1] = j;
				//write(2, "***********************\n", 24);
				insert_fig(xy, ij, str_filler, ans);
				//write(2, "***********************\n", 24);
				if (ans->error == 0)
				{

					
					// write(2, ft_itoa(ans->distance), ft_strlen(ft_itoa(ans->distance)));
					// write(2, "\n", 1);
					// write(2, "***********************\n", 24);
					calc_dist(ans, str_filler, ij);
					// write(2, "\x1B[32m", 6);
					// write(2, "-----\n", 6);
					// write(2, "COORDS\n", 7);
					// write(2, ft_itoa(xy[0]), ft_strlen(ft_itoa(xy[0])));
					// write(2, "\n", 1);
					// write(2, ft_itoa(xy[1]), ft_strlen(ft_itoa(xy[1])));
					// write(2, "\n", 1);
					// write(2, ft_itoa(ij[0]), ft_strlen(ft_itoa(ij[0])));
					// write(2, "\n", 1);
					// write(2, ft_itoa(ij[1]), ft_strlen(ft_itoa(ij[1])));
					// write(2, "\n", 1);
					// write(2, ft_itoa(ans->cur_distance), ft_strlen(ft_itoa(ans->cur_distance)));
					// write(2, "\n", 1);
					// write(2, ft_itoa(ans->distance), ft_strlen(ft_itoa(ans->distance)));
					// write(2, "\n", 1);
					// while (ans->new_board[k])
					// {
					// 	write(2, ans->new_board[k], ft_strlen(ans->new_board[k]));
					// 	write(2, "\n", 1);
					// 	k++;
					// }
					// write(2, "-----\n", 6);
					// write(2, "\x1B[0m", 5);
					if (ans->distance == -1 || ans->cur_distance < ans->distance)
					{
						//k++;
						ans->distance = ans->cur_distance;
						ans->x_coord = xy[0] - ij[0];
						ans->y_coord = xy[1] - ij[1];
						if (ans->distance == 1 || ans->distance == 0)
						{
							free(ans->new_board);
							return (ans);
						}
					}
					
					free(ans->new_board);
				}
			}
		j = -1;
	}
	return (ans);
}
