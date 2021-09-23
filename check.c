#include "monty.h"
glo_t glo;

/**
 * argc_check - Check to see if argc == 2
 * @argc: argument counter
 * Return: nothing
 */
void argc_check(int argc)
{
  if (argc != 2)
    {
      dprintf(STDERR_FILENO, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }
}

/**
 * open_check - Check to see if .m file was opened successfully
 * @argv: argument vector
 * Return: nothing
 */
void open_check(char **argv)
{
  if (glo.fp == NULL)
    {
      dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
}

/**
 * line_check - Check to see if the file was read correctly
 * @lines: the number of lines in the file. Failure if == -1
 * Return: nothing
 */
void line_check(ssize_t lines)
{
  if (lines == -1)
    {
      free(glo.line_buff);
      fclose(glo.fp);
      exit(0);
    }
}

/**
 * op_check - Check to see if the correct op code was found
 * @check: Integer that tells us if the op code was found or not
 * @c: line number
 * @head: pointer to the head of the linked list
 * Return: nothing
 */
void op_check(int check, unsigned int c, stack_t *head)
{
  if (check == 0)
    {
      op_check_print_error(c);
      free_buff();
      free_stack(head);
      exit(EXIT_FAILURE);
    }
}

/**
 * op_check_print_error - prints the error for function op_check()
 * @c: line number
 * Return: nothing
 */
void op_check_print_error(unsigned int c)
{
  dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", c, glo.bigb);
}
