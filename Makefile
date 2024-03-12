# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 19:50:42 by caqueiro          #+#    #+#              #
#    Updated: 2024/03/12 16:17:05 by caqueiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

FDF_SRCS =	main.c\
			window.c\
			events.c\
			mlx-config.c\
			input-handler.c\
			line-helpers.c\
			line-draw.c\
			isometric.c\
			point.c\
			map.c\
			map-helper.c\
			event-key-press.c\
			write-window.c

LIBFT = utils/libft/libft.a

MINILIBX = minilibx-linux/libmlx_Linux.a

FDF = fdf

CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${FDF_SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(FDF): clean
		@make -C utils/libft
		@make -C minilibx-linux
		${CC} ${FDF_SRCS} ${LIBFT} ${MINILIBX} -o ${FDF} -Imlx_linux -lXext -lX11 -lm
		@make fclean -C utils/libft
		@printf "$(GREEN)    - Executable ready.\n$(RESET)"

all: $(FDF) clean
		@make fclean -C utils/libft
		${RM} ${OBJS}

clean:
		@make fclean -C utils/libft
		${RM} ${OBJS}
		@printf "$(YELLOW)    - Objects removed.$(RESET)\n"

fclean: clean
	${RM} ${FDF}
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re:	fclean all
	@make fclean -C utils/libft
	${RM} ${OBJS}
	@printf "$(YELLOW)    - Objects removed.$(RESET)\n"
	@printf "$(GREEN)    - Makefile recompiled.$(RESET)\n"

.PHONY:	all clean fclean re
