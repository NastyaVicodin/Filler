/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:00:45 by alukyane          #+#    #+#             */
/*   Updated: 2018/01/05 16:00:51 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_count_c(char const *str, char c)
{
	size_t i;

	i = 0;
	while (*str)
		if (*str++ == c)
			i++;
	return (i);
}

static char		*ft_strccpy(char *str)
{
	size_t	len;
	char	*rat;

	len = 0;
	while (str[len] != '\n')
		len++;
	if ((rat = ft_strnew(len + 1)))
		ft_strncpy(rat, str, len);
	return (rat);
}

static int		ft_nline(char **buff, char **line, char **o_o)
{
	char *liberator;
	char *sidekick;

	liberator = *o_o;
	if (ft_count_c(*buff, '\n'))
	{
		if (!(sidekick = ft_strccpy(*buff)))
			return (-1);
		if (!(*o_o = ft_strjoin(*o_o, sidekick)))
			return (-1);
		ft_strdel(&liberator);
		ft_strdel(&sidekick);
		sidekick = *buff;
		*buff = ft_strchr(*buff, '\n');
		if (!(*buff = ft_strdup(++(*buff))))
			return (-1);
		ft_strdel(&sidekick);
		*line = *o_o;
		return (1);
	}
	if (!(*o_o = ft_strjoin(*o_o, *buff)))
		return (-1);
	ft_strdel(buff);
	ft_strdel(&liberator);
	return (0);
}

static t_op		*ft_multi_desu(const int fd, t_op *file)
{
	t_op		*new;

	if (!file->buff)
	{
		file->buff = NULL;
		file->f_desu = fd;
		file->next = NULL;
	}
	while (file)
	{
		if (file->f_desu == fd)
			return (file);
		if (file->next == NULL)
		{
			if (!(new = (void *)malloc(sizeof(t_op))))
				return (NULL);
			file->next = new;
			new->buff = NULL;
			new->f_desu = fd;
			new->next = NULL;
		}
		file = file->next;
	}
	return (file);
}

int				get_next_line(const int fd, char **line)
{
	static t_op		file_mem;
	t_op			*f;
	char			*o_o;
	int				check;

	f = &file_mem;
	if (fd < 0 || !line)
		return (-1);
	if (!(f = ft_multi_desu(fd, f)))
		return (-1);
	(o_o) = ft_strnew(1);
	if (f->buff && (check = ft_nline(&f->buff, line, &(o_o))))
		return (check);
	while ((read(fd, f->buff = ft_strnew(BUFF_SIZE), BUFF_SIZE)) > 0)
		if ((check = ft_nline(&f->buff, line, &(o_o))))
			return (check);
	if (ft_strlen(o_o))
	{
		*line = (o_o);
		return (1);
	}
	ft_strdel(&(o_o));
	return (read(fd, NULL, BUFF_SIZE));
}
