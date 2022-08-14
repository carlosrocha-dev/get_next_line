# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 16:04:11 by caalbert          #+#    #+#              #
#    Updated: 2022/07/10 04:54:45 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line

CC			= cc

MAX_FD		= ulimit -n

# CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=n MAX_FD
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRCS		= get_next_line.c get_next_line_utils.c

BONUS		= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS		= $(SRCS:.c=.o)

BONUS_OBJ	= $(BONUS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

git:
		@git status
		@git add .
		@git commit -m "git commit"
		@git push

bonus:		$(OBJS) $(BONUS_OBJ)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJ)

.PHONY:		all clean fclean re bonus git
