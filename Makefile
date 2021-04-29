# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 09:01:51 by cromalde          #+#    #+#              #
#    Updated: 2021/04/29 14:38:00 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		Makefile	FT_Containers

NAME	=	tester
SRCS	=	./srcs/main.cpp \
			./srcs/Vector.cpp \
			./srcs/List.cpp
#			./srcs/Queue.cpp
#			./srcs/Stack.cpp

OBJ		= $(SRCS:.cpp=.o)

CC		=	clang++
CFL		=	-Wall -Wextra -Werror -g
#-fsanitize=address
RM		=	rm -rf

.PHONY:		all clean fclean re

%.o: %.cpp
	$(CC) $(CFL) -c $^ -o $@

all : $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFL) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
