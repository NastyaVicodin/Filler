/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*read_player(t_filler *str_filler)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	while (line[i] && !('0' <= line[i] && line[i] <= '9'))
		i++;
	if (line[i] == '1')
		str_filler->player = 'O';
	else if (line[i] == '2')
		str_filler->player = 'X';
	free(line);
	return (str_filler);
}
