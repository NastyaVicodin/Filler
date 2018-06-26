/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player_vis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:14:09 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/11 13:14:28 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static char		*extract_name(char *line, int len)
{
	int		end;
	char	*res;

	while (len != 0 && line[len] != '.')
		len--;
	end = len;
	while (len != 0 && line[len] != '/')
		len--;
	res = ft_strsub(line, len + 1, end - len - 1);
	return (res);
}

t_filler		*read_player_vis(t_filler *str_filler)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	while (1)
	{
		get_next_line(0, &line);
		if (line && line[0] != '$')
			free(line);
		else
			break ;
	}
	while (line[i] && !('0' <= line[i] && line[i] <= '9'))
		i++;
	len = ft_strlen(line);
	if (line[i] == '1')
		str_filler->pl_o = extract_name(line, len);
	else if (line[i] == '2')
		str_filler->pl_x = extract_name(line, len);
	free(line);
	return (str_filler);
}
