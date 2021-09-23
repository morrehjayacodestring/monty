#include "monty.h"
glo_t glo;
/**
 * parse_line - tokenizes the line
 * @c: line number
 * @head: the head pointer to the list
 * Return: a token that holds the correct command
 */
char *parse_line(unsigned int c, stack_t *head)
{
  char *token = NULL, *next_token = NULL;
  int i = 0;

  token = strtok(glo.line_buff, " \n");
  if (token == NULL)
    return (NULL);
  if (strcmp(token, "push") == 0)
    {
      next_token = strtok(NULL, " \n");
      if (next_token == NULL)
	integer_error(c, head);
      while (next_token[i])
	{
	  if (i == 0 && next_token[i] == '-')
	    {
	      i++;
	      continue;
	    }
	  if (next_token[i] >= 48 && next_token[i] <= 57)
	    {
	      i++;
	      continue;
	    }
	  else
	    integer_error(c, head);
	}
      glo.node_data = atoi(next_token);
    }
  return (token);
}

/**
 * integer_error - function that prints an integer error and exits
 * @c: line count
 * @head: the head pointer to the linked list
 * Return: nothing
 */
void integer_error(unsigned int c, stack_t *head)
{
  dprintf(STDERR_FILENO, "L%u: usage: push integer\n", c);
  free_buff();
  free(glo.line_buff);
  free_stack(head);
  exit(EXIT_FAILURE);
}

/**
 * pint_error - prints a pint error and exits
 * @c: line number
 * Return: nothing
 */
void pint_error(unsigned int c)
{
  dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", c);
  exit(EXIT_FAILURE);
}

/**
 * pop_error - prints a pop error and exits
 * @c: line number
 * @stack: the linked list
 * Return: nothing
 */
void pop_error(stack_t **stack, unsigned int c)
{
  dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", c);
  free_stack(*stack);
  exit(EXIT_FAILURE);
}

/**
 * add_error - prints an add error and exits
 * @c: line number
 * Return: nothing
 */
void add_error(unsigned int c)
{
  dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", c);
  exit(EXIT_FAILURE);
}
