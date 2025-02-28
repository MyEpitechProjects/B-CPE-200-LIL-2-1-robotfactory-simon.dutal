##
## EPITECH PROJECT, 2025
## fozzbazz
## File description:
## Makefile
##

NAME	= asm

SRC	=	src/op.c\
		src/main.c\
		src/fwrite_int.c\
		src/open_files.c\
		src/handle_line.c\
		src/fwrite_byte.c\
		src/init_robot.c\
		src/my_list_len.c\
		src/write_output.c\
		src/robot_err.c\
		src/free_robot.c\
		src/handle_inst.c\
		src/list_push.c\
		src/args_checker.c\
		src/my_pysplit.c\
		src/list_len.c\
		src/robot_offset.c\
		src/push_arg_list.c\
		src/swrite.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS  = -Wall -Wextra -fanalyzer

LIB_BIN = -lmy_sscanf -lmy_string

LFLAGS	= -I include -L./lib/bin $(LIB_BIN)

all: mylib
	$(CC) -c $(SRC) $(CFLAGS) $(LFLAGS)
	@mv $(notdir $(OBJ)) src
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

debug:
	$(CC) -c $(SRC) $(CFLAGS) $(LFLAGS) -g
	@mv $(notdir $(OBJ)) src
	$(CC) -o $(NAME)_debug $(OBJ) $(CFLAGS) $(LFLAGS) -g

clean:
	@cd lib ; make -s clean
	@rm -f $(NAME)
	@rm -f $(NAME)_debug
	@rm -f $(OBJ)
mylib:
	@cd lib ; make -s
fclean: clean
	@rm -rf *.o
	@rm -rf *.a

re: fclean all

run: all
	./$(NAME)
