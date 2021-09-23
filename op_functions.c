#include "monty.h"
glo_t glo;

/**
 * op_push - function that push an element to the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_push(stack_t **stack, unsigned int line_number)
{
  stack_t *new_node;
  (void)line_number;

  new_node = malloc(sizeof(stack_t));
  if (!new_node)
    {
      dprintf(STDERR_FILENO, "Error: malloc failed\n");
      free_buff();
      free_stack(*stack);
      exit(EXIT_FAILURE);
    }
  new_node->n = glo.node_data;
  new_node->next = NULL;
  new_node->prev = NULL;

  if (*stack)
    {
      new_node->next = *stack;

      (*stack)->prev = new_node;
    }
  *stack = new_node;

}

/**
 * op_pall - function that prints out all the elements of a linked list
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
  stack_t *current = *stack;
  (void)line_number;

  while (current)
    {
      printf("%d\n", current->n);
      current = current->next;
    }
}

/**
 * op_pint - function that prints the value at the top of the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
  stack_t *current = *stack;

  if (current)
    {
      printf("%d\n", current->n);
    }
  else
    {
      pint_error(line_number);
    }
}

/**
 * op_pop - function that removes the top element of the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
  stack_t *current = *stack;
  stack_t *tmp;

  if (!current)
    pop_error(stack, line_number);

  tmp = current->next;
  free(current);
  *stack = tmp;
  current = *stack;
  if (current)
    {
      current->prev = NULL;
    }
}

/**
 * op_add - adds the first two nodes together
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 * Return: nothing
 */

void op_add(stack_t **stack, unsigned int line_number)
{
  stack_t *current = *stack;
  stack_t *second_node;

  if (!current || !current->next)
    add_error(line_number);
second_node = current->next;
second_node->n = second_node->n + current->n;
op_pop(stack, line_number);
}
