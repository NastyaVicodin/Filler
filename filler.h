/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:59:45 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 16:59:47 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct		s_filler
{
	char	player;
	int		b_wid;
	int		b_height;
	char	**board;
	size_t	t_wid;
	size_t	t_height;
	char	**token;
	char	*coords;

}					t_filler;
typedef struct		s_answer
{
	char	**new_board;
	int		error;
	int		x_coord;
	int		y_coord;
	int		distance;
	int		cur_distance;
}					t_answer;
typedef	struct		s_where_fig
{
	int		sten_you[2];
	int		sten_he[2];
	char	you;
	char	he;
	char	res;
}					t_where;
t_filler			*read_player(t_filler *str_filler);
t_filler			*read_board(t_filler *str_filler);
t_filler			*read_token(t_filler *str_filler);
t_answer			*make_new_board(t_answer *ans, t_filler *f);
t_where				*check_where_square(t_filler *str_filler, t_where *w);
t_answer			*insert_fig(int *xy, int *ij, t_filler *f, t_answer *a);
t_answer			*paste_fig(int *xy, t_filler *str_filler, t_answer *ans);
t_answer			*calc_dist(t_answer *ans, t_filler *f);
t_answer			*paste_high_low(t_filler *f, t_answer *ans, t_where *w);
void				free_array(char **arr);
#endif
