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

#include "../filler.h"

static t_filler	*make_struct(void)
{
	t_filler	*str_filler;

	str_filler = (t_filler *)malloc(sizeof(t_filler));
	str_filler->b_wid = 1;
	str_filler->b_height = 0;
	return (str_filler);
}
t_filler	*read_player(t_filler *str_filler)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		get_next_line(0, &line);
		if (line[0] != '$')
			free(line);
		else
			break ;
	}
	while (line[i] && !('0' <= line[i] && line[i] <= '9'))
		i++;
	if (line[i] == '1')
		str_filler->player = 'O';
	else if (line[i] == '2')
		str_filler->player = 'X';
	free(line);
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
static t_filler		*get_board_size(t_filler *str_filler)
{
	char	*line;
	int		i;
	int		start;
	char	*num;
i = 0;
	while (1)
	{
		i = get_next_line(0, &line);
		//ft_printf("%d\n", i);
		if (line[1] != 'l')
			free(line);
		else
			break ;
	}
	//i = get_next_line(0, &line);
	if (!i)
		return (str_filler);
	
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
// static t_answer	*paste_manhattan(t_filler *str_filler, t_answer *ans)
// {
// 	int			i;
// 	int			j;
// 	int			xy[2];

// 	i = -1;
// 	while (str_filler->board[++i])
// 	{
// 		j = -1;
// 		while (str_filler->board[i][++j])
// 			if (str_filler->board[i][j] == str_filler->player)
// 			{
// 				xy[0] = i;
// 				xy[1] = j;
// 				paste_fig(xy, str_filler, ans);
// 			}
// 	}
// 	return (ans);
// }

// static void		print_answer(t_filler *str_filler)
// {
// 	t_answer	*ans;
// 	t_where		*w;

// 	ans = (t_answer *)malloc(sizeof(t_answer));
// 	w = (t_where *)malloc(sizeof(t_where));
// 	w->sten_you[0] = str_filler->b_height;
// 	w->sten_you[1] = 0;
// 	w->sten_he[0] = str_filler->b_height;
// 	w->sten_he[1] = 0;
// 	ans->x_coord = -1;
// 	ans->y_coord = -1;
// 	ans->distance = -2;
// 	paste_manhattan(str_filler, ans);
// 	ft_printf("%d %d\n", ans->x_coord, ans->y_coord);
// 	free(ans);
// 	free(w);

// }

void	print_visu_dot(int size, int row, void *mlx_ptr, void *win_ptr)
{
	int i;

	i = -1;
	while (++i < size)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, row, i, 0xFFFFFF);
	}
}

void	print_visu_x(int size, int row, void *mlx_ptr, void *win_ptr)
{
	int i;

	i = -1;
	while (++i < size)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, row, i, 0xFF0000);
	}
}

void	print_visu_o(int size, int row, void *mlx_ptr, void *win_ptr)
{
	int i;

	i = -1;
	while (++i < size)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, row, i, 0x0000FF);
	}
}

int				main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int i;
	int j;
	int size;
	t_filler	*str_filler;
	int k;
	str_filler = make_struct();
	read_player(str_filler);
	ft_printf("%c\n", str_filler->player);
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Filler");
	//read_board(str_filler);
	int g;
	g = -1;
	
	
	
	while (str_filler->b_wid)
	{
		g = -1;
		str_filler->b_wid = 0;
		read_board(str_filler);
		while (str_filler->board[++g])
			ft_printf("%s\n",str_filler->board[g]);
		//ft_printf("HEEEEEY\n");
		//mlx_loop(mlx_ptr);
		i = -1;
		size = str_filler->b_wid < str_filler->b_height ? 1000 / str_filler->b_wid : 1000 / str_filler->b_height;
		while (str_filler->board[++i])
		{
			
			k = -1;
			while (++k < size)
			{
				j = -1;
				while (str_filler->board[i][++j])
				{
					//ft_printf("HEEEEEY2222\n");
					if (str_filler->board[i][j] == '.')
						print_visu_dot(size, i+k, mlx_ptr, win_ptr);
					else if (str_filler->board[i][j] == 'X' || str_filler->board[i][j] == 'x')
						print_visu_x(size, i+k, mlx_ptr, win_ptr);
					else if (str_filler->board[i][j] == 'O' || str_filler->board[i][j] == 'o')
						print_visu_o(size, i+k, mlx_ptr, win_ptr);
					//
					//ft_printf("HEEEEEY33333\n");
				}
			}
		}
			free_array(str_filler->board);
		mlx_clear_window(mlx_ptr, win_ptr);
	}
	free(str_filler);
	mlx_loop(mlx_ptr);
	return (0);
}
