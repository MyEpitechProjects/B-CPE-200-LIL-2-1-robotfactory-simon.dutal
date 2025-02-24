##
## EPITECH PROJECT, 2025
## fozzbazz
## File description:
## Makefile
##

NAME	= libmy_string.so

SRC	=	src/my_puterr.c\
		src/my_putstr.c\
		src/my_split.c\
		src/my_strcmp.c\
		src/my_strlen.c\
		src/my_strcat.c\
		src/my_strcpy.c\
		src/my_memset.c\
		src/my_put_nbr_err.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS  = -shared -fPIC -Wall -Wextra -fanalyzer

LFLAGS	= -I include


all:
	$(CC) -c $(SRC) $(CFLAGS) $(LFLAGS)
	@mv $(notdir $(OBJ)) src
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)
	mv $(NAME) ../../bin

clean:
	@rm -f ../../bin/$(NAME)
	@rm -f $(OBJ)

re: fclean all
