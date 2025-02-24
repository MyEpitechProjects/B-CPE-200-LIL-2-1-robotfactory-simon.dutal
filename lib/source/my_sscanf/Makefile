##
## EPITECH PROJECT, 2025
## fozzbazz
## File description:
## Makefile
##

NAME	= libmy_sscanf.so

SRC	=	src/extractor_chooser.c\
		src/flg_modifier_extractor.c\
		src/float_extractor.c\
		src/hex_extractor.c\
		src/int_extractor.c\
		src/my_sscanf.c\
		src/number_get.c\
		src/special_extractor.c\
		src/string_extractor.c\
		src/uint_extractor.c\
		src/my_sscanf_flg.c

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
