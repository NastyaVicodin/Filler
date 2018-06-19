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

LIB = libft.a
FILLER = alukyane.filler

SOURCE_LIB = ./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_memcpy.c 		\
			./libft/ft_memccpy.c ./libft/ft_memmove.c ./libft/ft_strcpy.c		\
         	./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_strlen.c 		\
         	./libft/ft_strdup.c ./libft/ft_strlcat.c ./libft/ft_strchr.c 		\
            ./libft/ft_strncpy.c ./libft/ft_strcat.c ./libft/ft_strncat.c  		\
            ./libft/ft_strrchr.c ./libft/ft_strstr.c ./libft/ft_strnstr.c 		\
            ./libft/ft_strcmp.c ./libft/ft_strncmp.c ./libft/ft_isalnum.c		\
            ./libft/ft_atoi.c ./libft/ft_isalpha.c ./libft/ft_isdigit.c 		\
            ./libft/ft_isascii.c ./libft/ft_memalloc.c ./libft/ft_memdel.c		\
            ./libft/ft_isprint.c ./libft/ft_toupper.c ./libft/ft_tolower.c  	\
            ./libft/ft_strnew.c ./libft/ft_strdel.c ./libft/ft_strclr.c 		\
            ./libft/ft_striter.c ./libft/ft_striteri.c ./libft/ft_strnequ.c		\
            ./libft/ft_strmap.c ./libft/ft_strmapi.c ./libft/ft_strequ.c 		\
            ./libft/ft_strsub.c ./libft/ft_itoa.c ./libft/ft_putchar.c			\
            ./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_strsplit.c  	\
            ./libft/ft_putstr.c ./libft/ft_putendl.c ./libft/ft_putnbr.c 		\
            ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_lstnew.c 	\
            ./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c 						\
            ./libft/ft_lstdelone.c ./libft/ft_sqrt.c ./libft/ft_lstiter.c 		\
            ./libft/ft_lstdel.c ./libft/ft_lstadd.c  ./libft/ft_lstmap.c 		\
            ./libft/ft_strrev.c	./libft/ft_rot42.c ./libft/ft_derot42.c			\
            ./libft/ft_positive_power.c ./libft/ft_is_prime.c  					\
            ./libft/ft_itoa_base.c ./libft/ft_printf.c ./libft/ft_get_data.c 	\
            ./libft/process.c ./libft/ft_output_d.c ./libft/ft_print_o.c		\
            ./libft/ft_print_d.c ./libft/ft_print_u.c ./libft/ft_align_o.c 		\
            ./libft/ft_print_b.c ./libft/ft_print_s_w.c ./libft/ft_itoa_u.c		\
            ./libft/ft_print_x.c ./libft/ft_print_c_w.c ./libft/ft_print_c.c  	\
            ./libft/ft_putnbr_u.c ./libft/ft_print_nbr.c ./libft/ft_print_str.c \
            ./libft/ft_allupper.c ./libft/ft_print_s.c ./libft/get_next_line.c

SOURCE_FILLER = main.c read_player.c read_board.c read_token.c calc_dist.c 		\
				paste_fig.c check_where_square.c paste_high_low.c

OBJS_LIB = $(SOURCE_LIB:.c=.o)
OBJS_FILLER = $(SOURCE_FILLER:.c=.o)

all: $(LIB) $(FILLER)

%.o:%.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

$(LIB): $(OBJS_LIB)

	@ar rc $(LIB) $(OBJS_LIB)
	@ranlib $(LIB)

$(FILLER): $(OBJS_FILLER)
	gcc -o $(FILLER) $(OBJS_FILLER) $(LIB)

clean:
	rm -f $(OBJS_LIB) $(OBJS_FILLER)

fclean: clean
	rm -f $(FILLER) $(LIB)

re: fclean all
