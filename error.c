#include "monty.h"

/**
 * sub_error - Error functionality for op_sub()
 * @c: line count
 * Return: nothing
 */
void sub_error(unsigned int c)
{
  dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", c);
  exit(EXIT_FAILURE);
}

/**
 * div_error - Error functionality for op_div()
 * @c: line count
 * Return: nothing
 */
void div_error(unsigned int c)
{
  dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", c);
  exit(EXIT_FAILURE);
}

/**
 * mul_error - Error functionality for op_mul()
 * @c: line count
 * Return: nothing
 */
void mul_error(unsigned int c)
{
  dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", c);
  exit(EXIT_FAILURE);
}

/**
 * mod_error - Error functionality for op_div()
 * @c: line count
 * Return: nothing
 */
void mod_error(unsigned int c)
{
  dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", c);
  exit(EXIT_FAILURE);
}
