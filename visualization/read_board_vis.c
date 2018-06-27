/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board_vis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static t_filler		*fill_board_size(t_filler *str_filler, char *line)
{
	int		i;
	int		start;
	char	*num;

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
	return (str_filler);
}

static void			put_results(char *line, t_vis *v)
{
	int		i;
	char	*res_o;
	char	*res_x;

	i = 0;
	while (line[i] && !('0' <= line[i] && line[i] <= '9'))
		i++;
	res_o = ft_strsub(line, i, ft_strlen(line));
	free(line);
	get_next_line(0, &line);
	i = 0;
	while (line[i] && !('0' <= line[i] && line[i] <= '9'))
		i++;
	res_x = ft_strsub(line, i, ft_strlen(line));
	free(line);
	mlx_string_put(v->mlx, v->win, 400, 1010, 0x7B68EE, res_o);
	mlx_string_put(v->mlx, v->win, 900, 1010, 0x4169E1, res_x);
	free(res_o);
	free(res_x);
}

static t_filler		*get_board_size(t_filler *str_filler, t_vis *v)
{
	char	*line;
	int		i;

	while (1)
	{
		i = get_next_line(0, &line);
		if (i && line[0] == '=')
		{
			i = 0;
			put_results(line, v);
			break ;
		}
		else if (i && line[1] != 'l')
			free(line);
		else
			break ;
	}
	if (!i)
		return (str_filler);
	fill_board_size(str_filler, line);
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

t_filler			*read_board_vis(t_filler *str_filler, t_vis *v)
{
	str_filler->b_wid = 0;
	get_board_size(str_filler, v);
	if (str_filler->b_wid)
		fill_board(str_filler);
	return (str_filler);
}
