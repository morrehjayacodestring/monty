#ifndef __MONTY__H__
#define __MONTY__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* global variable */
/**
 * struct glo_s - global variable
 * @fp: The file we open and read
 * @line_buff: the buffer that holds the command for each line
 * @bigb: the array of strings that holds the command
 * @node_data: The integer to use for data in a given node if necessary
 * Description: Allows us to pass variables across our code
 */
typedef struct glo_s
{
  FILE *fp;
  char *line_buff;
  char *bigb;
  int node_data;
} glo_t;
extern glo_t glo;

/* Parse line and error functions */
char *parse_line(unsigned int c, stack_t *head);
void integer_error(unsigned int c, stack_t *head);
void pint_error(unsigned int c);
void pop_error(stack_t **stack, unsigned int c);
void add_error(unsigned int c);

/* More error functions */
void sub_error(unsigned int c);
void div_error(unsigned int c);
void mul_error(unsigned int c);
void mod_error(unsigned int c);

/* Checks and executes given commands */
int get_opcode(stack_t **stack, unsigned int line_number);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);
void stack_handler(stack_t **stack, unsigned int line_number);
void queue_handler(stack_t **stack, unsigned int line_number);

/* Conditional statements to check for failure */
void argc_check(int argc);
void open_check(char **argv);
void line_check(ssize_t lines);
void op_check(int check, unsigned int c, stack_t *head);
void op_check_print_error(unsigned int c);

/* Freeing functions */
void free_buff(void);
void free_stack(stack_t *head);
#endif
