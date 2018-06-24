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

LIB = ../libft.a
VISUALIZATION = visual

SRC_VISUAL = main.c
# SOURCE_FILLER = ../read_player.c ../read_board.c ../read_token.c ../calc_dist.c 		\
# 				../paste_fig.c

OBJS_VISUAL = $(SRC_VISUAL:.c=.o)
# OBJS_FILLER = $(SOURCE_FILLER:.c=.o)
all: $(VISUALIZATION)

%.o:%.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

$(VISUALIZATION): $(OBJS_VISUAL)
	gcc -o $(VISUALIZATION) $(OBJS_VISUAL) $(LIB) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJS_VISUAL)

fclean: clean
	rm -f $(VISUALIZATION)

re: fclean all