/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_filler		*get_board_size(t_filler *str_filler)
{
	char	*line;
	int		i;
	int		start;
	char	*num;

	i = get_next_line(0, &line);
	if (!i)
		return (str_filler);
	i = 0;
	while (!('0' <= line[i] && line[i] <= '9'))
		i++;
	start = i;
	while ('0' <= line[i] && line[i] <= '9')
		i++;
	num = ft_strsub(line, start, i - start);
	str_filler->b_height = ft_atoi(num);
	free(num);
	num = ft_strsub(line, i + 1, ft_strlen(line) - 2 - i);
	str_filler->b_wid = ft_atoi(num);
	free(num);
	free(line);
	get_next_line(0, &line);
	free(line);
	return (str_filler);
}

static t_filler		*fill_board(t_filler *f)
{
	int		i;
	char	*line;
	int		start;

	i = 0;
	f->board = (char **)malloc(sizeof(char *) * (f->b_height + 1));
	f->board[f->b_height] = NULL;
	while (i < f->b_height)
	{
		start = 0;
		get_next_line(0, &(line));
		while (line[start] && line[start] != ' ')
			start++;
		f->board[i] = ft_strsub(line, start + 1, ft_strlen(line));
		free(line);
		i++;
	}
	return (f);
}

t_filler			*read_board(t_filler *str_filler)
{
	get_board_size(str_filler);
	if (str_filler->b_wid)
		fill_board(str_filler);
	return (str_filler);
}
