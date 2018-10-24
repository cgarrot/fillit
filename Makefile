# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
<<<<<<< HEAD
#    Created: 2018/10/24 13:22:33 by thbrouss     #+#   ##    ##    #+#        #
#    Updated: 2018/10/24 13:22:48 by thbrouss    ###    #+. /#+    ###.fr      #
=======
#    Created: 2018/10/24 13:15:50 by cgarrot      #+#   ##    ##    #+#        #
#    Updated: 2018/10/24 14:04:28 by cgarrot     ###    #+. /#+    ###.fr      #
>>>>>>> 355a3b6d3c4374e227f4dfa815bc21dbcb0ae09c
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit
MAKE=make
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = ./includes

#------------------------------------FILE--------------------------------------#

FILES = parse_input\
main\
check_error\
detect_piece\
<<<<<<< HEAD
algo\
=======
>>>>>>> 355a3b6d3c4374e227f4dfa815bc21dbcb0ae09c
detect_piece2\
detect_global\
#algo

#----------------------------------SOURCE--------------------------------------#

SRC = $(addsuffix .c, $(FILES))

#----------------------------------OBJECT--------------------------------------#

OBJ= $(addsuffix .o, $(FILES))

#-----------------------------------RULE---------------------------------------#

all: $(NAME)


$(NAME): $(SRC) $(INCLUDE)
	@echo "\033[1m|---------------------------------|\033[0m"
	@echo "\033[1m|-------Compilation du prog-------|\033[0m"
	@echo "\033[1m|---------------------------------|\033[0m"
	@echo "\033[1m|---------------------------------|\033[0m"
	@echo "\033[1m|---------Creation du prog--------|\033[0m"
	@echo "\033[1m|---------------------------------|\033[0m"
	@+$(MAKE) -C libft/
	@$(CC) $(FLAGS) -g -o $(NAME) $(SRC) -I$(INCLUDE) -L libft/ -lft

clean:
	@echo "\033[1m|---------------------------------|\033[0m"
	@echo "\033[1m|-------Supprimer les OBJECT------|\033[0m"
	@echo "\033[1m|---------------------------------|\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\n"
	@echo "\033[1m|---------------------------------|\033[0m"
	@echo "\033[1m|-------Supprimer la libft.a------|\033[0m"
	@echo "\033[1m|---------------------------------|\033[0m"
	@rm -f $(NAME)

re: fclean all
