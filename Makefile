# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/24 17:57:21 by thbrouss     #+#   ##    ##    #+#        #
#    Updated: 2018/10/29 16:18:29 by thbrouss    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit
OBJ = fillit
MAKE=make
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = ./includes

#------------------------------------FILE--------------------------------------#

FILES = parse_input\
main\
check_error\
detect_piece\
algo\
detect_global\
utils\
letter

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
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) -I$(INCLUDE) -L libft/ -lft

clean:
	@echo "\033[1m|---------------------------------|\033[0m"
	@echo "\033[1m|-------Supprimer les OBJECT------|\033[0m"
	@echo "\033[1m|---------------------------------|\033[0m"
	@rm -f $(OBJ)
	@$(MAKE) -C libft/ clean

fclean: clean
	@echo "\n"
	@echo "\033[1m|---------------------------------|\033[0m"
	@echo "\033[1m|-------Supprimer la libft.a------|\033[0m"
	@echo "\033[1m|---------------------------------|\033[0m"
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all
