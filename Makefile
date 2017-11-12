#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpochuka <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 21:09:12 by mpochuka          #+#    #+#              #
#    Updated: 2017/10/30 21:09:15 by mpochuka         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang++

FAST = -Ofast

FLAGS = -Wall -Wextra -Werror

NAME = ft_gkrellm

SRC = nekit_main.cpp\
		IMonitorDisplay.cpp\
		CPU.cpp\
		DateTime.cpp\
		Hostname.cpp\
		IMonitorModule.cpp\
		Network.cpp\
		OSinfo.cpp\
		RAM.cpp\
		TextDisplay.cpp

OBJ = $(SRC:.cpp=.o)

INC = -I ./

NCURSES = -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(INC) $(LIB) $(OBJ) $(NCURSES) -o $(NAME)
	@echo  "\033[32mCompiled and created" $(NAME) "binary\033[0m"

%.o: %.cpp
	@$(CC) $(INC) $(FAST) $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@echo "\033[01;31m"$(NAME)" object files deleted\033[0m"

fclean: clean
	@rm -f $(NAME) a.out
	@echo "\033[01;31m"$(NAME)" binary file deleted\033[0m"

re: fclean all
