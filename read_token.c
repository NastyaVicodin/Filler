/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_filler	*get_token_size(t_filler *str_filler)
{
	char	*line;
	int		i;
	int		start;
	char	*num;

	i = 0;
	get_next_line(0, &line);
	while (!('0' <= line[i] && line[i] <= '9'))
		i++;
	start = i;
	while ('0' <= line[i] && line[i] <= '9')
		i++;
	//write(2, "SIZE\n", 5);
	num = ft_strsub(line, start, i - start);
	// write(2, num, ft_strlen(num));
	// write(2, "\n", 1);
	str_filler->t_height = ft_atoi(num);
	free(num);
	num = ft_strsub(line, i + 1, ft_strlen(line) - i - 2);
	// write(2, num, ft_strlen(num));
	// write(2, "\n", 1);
	// write(2, "-----\n", 6);
	str_filler->t_wid = ft_atoi(num);
	free(num);
	free(line);
	//get_next_line(0, &line);
	//free(line);
	return (str_filler);
}

static t_filler	*fill_token(t_filler *f)
{
	size_t	i;
	int		start;

	i = 0;
	f->token = (char **)malloc(sizeof(char *) * (f->t_height + 1));
	f->token[f->t_height] = NULL;
	while (i < f->t_height)
	{
		start = 0;
		f->token[i] = (char *)malloc(sizeof(char) * (f->t_wid + 1));
		get_next_line(0, &(f->token[i]));
		i++;
	}
	i = 0;
	// write(2, "\x1B[33m", 6);
	// write(2, "-----\n", 6);
	// write(2, "TOKEN\n", 6);
	// while (f->token[i])
	// {
	// 	write(2, f->token[i], ft_strlen(f->token[i]));
	// 	write(2, "\n", 1);
	// 	i++;
	// }
	// write(2, "-----\n", 6);
	// write(2, "\x1B[0m", 5);
	return (f);
}

t_filler		*read_token(t_filler *str_filler)
{
	get_token_size(str_filler);
	fill_token(str_filler);
	return (str_filler);
}
