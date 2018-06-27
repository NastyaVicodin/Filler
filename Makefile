#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alukyane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 22:31:54 by alukyane          #+#    #+#              #
#    Updated: 2017/10/25 22:31:56 by alukyane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIB = ./libft/libft.a
FILLER = alukyane.filler

SOURCE_FILLER = main.c read_player.c read_board.c read_token.c calc_dist.c 		\
				paste_fig.c

OBJS_FILLER = $(SOURCE_FILLER:.c=.o)

all: $(FILLER) vis

vis:
	make -C ./visualization

%.o:%.c
	@gcc -Wall -Wextra -Werror -o $@ -c $<

$(LIB):
	make -C ./libft

$(FILLER): $(OBJS_FILLER) $(LIB)
	gcc -o $(FILLER) $(OBJS_FILLER) $(LIB)

clean:
	rm -f $(OBJS_FILLER)
	make -C ./visualization clean
	make -C ./libft clean

fclean: clean
	rm -f $(FILLER)
	make -C ./visualization fclean
	make -C ./libft fclean

re: fclean all
