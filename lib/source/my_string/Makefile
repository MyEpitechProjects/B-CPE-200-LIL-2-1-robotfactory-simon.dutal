##
## EPITECH PROJECT, 2025
## fozzbazz
## File description:
## Makefile
##

NAME	= libmy_string.a

SRC	=	src/my_puterr.c\
		src/my_putstr.c\
		src/my_split.c\
		src/my_strcmp.c\
		src/my_strlen.c\
		src/my_strcat.c\
		src/my_strcpy.c\
		src/my_memset.c\
		src/my_put_nbr_err.c\
		src/my_string_is_int.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS  = -Wall -Wextra -fanalyzer

LFLAGS	= -I include

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	mv $(NAME) ../../bin

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LFLAGS)

clean:
	@rm -f ../../bin/$(NAME)
	@rm -f $(OBJ)

re: clean all
