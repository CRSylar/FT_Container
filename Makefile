# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 09:01:51 by cromalde          #+#    #+#              #
#    Updated: 2021/05/06 17:47:50 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		Makefile	FT_Containers

NAME	=	tester
SRCS	=	./srcs/main.cpp \
			./srcs/Vector.cpp \
			./srcs/List.cpp \
			./srcs/Stack.cpp \
			./srcs/Queue.cpp \
			./srcs/Map.cpp \
			./srcs/MultiMap.cpp \
			./srcs/Set.cpp \
			./srcs/Multiset.cpp \
			./srcs/Deque.cpp

OBJ		= $(SRCS:.cpp=.o)

CC		=	clang++
CFL		=	-Wall -Wextra -Werror -g -fsanitize=address
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
