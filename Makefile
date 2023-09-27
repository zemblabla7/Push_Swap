# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 17:08:17 by carolina          #+#    #+#              #
#    Updated: 2023/04/21 13:00:02 by casomarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PATH_LIBFT = "libft"
LIBFT = $(PATH_LIBFT)/libft.a

PATH_FT_PRINTF = "ft_printf"
FT_PRINTF = $(PATH_FT_PRINTF)/libftprintf.a

PATH_SRC = src

SRC = $(PATH_SRC)/main.c \
	$(PATH_SRC)/init.c \
	$(PATH_SRC)/del_add_last.c \
	$(PATH_SRC)/swap_rules.c \
	$(PATH_SRC)/rotate_rules.c \
	$(PATH_SRC)/push_rules.c \
	$(PATH_SRC)/check_valid_list.c \
	$(PATH_SRC)/maths.c \
	$(PATH_SRC)/maths2.c \
	$(PATH_SRC)/algorithms.c \

OBJS = $(SRC:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

all: $(LIBFT) $(FT_PRINTF) $(NAME)
	@toilet COMPILED -F border -f wideterm
	@echo "          ,---."
	@echo "         ( @ @ )"
	@echo "          ).-.("
	@echo "         '/|||\\\`"
	@echo "           '|\`"
	@echo "   PUSH SWAP COMPILÉ!"

$(NAME): $(OBJS)
	@toilet LIBFT -F border -f wideterm
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)
	clear

$(LIBFT):
	@toilet FT_PRINTF -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_LIBFT)
	clear

$(FT_PRINTF):
	@$(MAKE) --no-print-directory -C $(PATH_FT_PRINTF)
	clear

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(PATH_LIBFT) -I $(PATH_FT_PRINTF) -I $(PATH_SRC)

clean:
	@toilet CLEAN -F border -f wideterm
	$(RM) $(OBJS)
	make -C ${PATH_LIBFT} clean
	make -C ${PATH_FT_PRINTF} clean
	clear

fclean: clean
	@toilet FCLEAN -F border -f wideterm
	$(RM) $(NAME)
	make -C ${PATH_LIBFT} fclean
	make -C ${PATH_FT_PRINTF} fclean
	clear

re: fclean all

.PHONY: all clean fclean re