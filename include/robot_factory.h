/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#ifndef _ROBOT_FACTORY_
    #define _ROBOT_FACTORY_
    #include "op.h"
    #include "mylib.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdbool.h>

    /* ERROR MESSAGES ID */
    #define EMPTY_FILE 0
    #define MISS_NAME 1
    #define MISS_COMM 2
    #define SYNTAX_ERR 3
    #define BAD_INST 4
    #define LAB_NAME 5
    #define LAB_DEF 6
    #define REG_NUM 7
    #define BAD_ARG 8
    #define MANY_ARG 9
    #define NAME_ONCE 10
    #define COMM_ONCE 11
    #define NAME_FIRST 12
    #define NAME_LONG 13
    #define COMM_AFTER 14
    #define COMM_LONG 15
    #define UNDEF_LABEL 16

typedef struct factory_flg {
    int header_end;
    int name_gived;
    int comment_gived;
    int file_empty;
} factflg_t;

typedef struct factory_arg {
    char type;
    int int_val;
    char char_val;
    char *label_name;
    short short_val;
} factarg_t;

typedef struct factory_inst {
    char opcode;
    char encoding_byte;
} factinst_t;

typedef struct factory {
    char input_name[256];
    char **split;
    int idx;
    int offset;
    char **input;
    struct factory_flg flg;
    struct header_s header;
    struct factory_inst *inst;
} factory_t;


extern const char *messages_err[];

int handle_line(factory_t *robot);
unsigned int my_list_len(char **value);
int init_robot(int arg_idx, char **argv, factory_t *robot);
int help(char **argv, int silent, int ret_value);
int open_files(factory_t *robot);
int change_int_order(unsigned int num);
int write_output(factory_t *robot);
int robot_warn(factory_t *robot, int message_id, int line);
int robot_err(factory_t *robot, int message_id, int line);
int write_warnings(factory_t *robot);
int free_robot(factory_t *robot, int ret_value);
int free_list(char **lst, int ret_value);
int check_err(factory_t *robot);
int my_put_nbr_err(int nb);
int push_inst(factory_t *robot, int opcode, int encoding_byte);
int handle_inst(factory_t *robot, int fix);
char get_encoding_byte(op_t inst, factory_t *robot, int fix);
int check_arg(factory_t *robot, op_t inst, int fix);
bool is_arg_possible(char arg, char possible_arg);
void *secure_realloc(void *pointer, size_t size);
bool is_label_valid(char *label);
char **my_pysplit(char *str, char delimiter);
#endif
