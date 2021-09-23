#include "monty.h"
glo_t glo;
/**
 * main - reads a monty file and executes line by line
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char **argv)
{
  stack_t *head = NULL;
  ssize_t lines;
  int check;
  size_t buff_size = 0;
  unsigned int counter = 0;

  glo.line_buff = NULL;
  glo.bigb = NULL;

  argc_check(argc);

  glo.fp = fopen(argv[1], "r");
  open_check(argv);

  lines = getline(&glo.line_buff, &buff_size, glo.fp);
  line_check(lines);

  while (lines >= 0)
    {
      glo.bigb = NULL;
      counter++;
      glo.bigb = parse_line(counter, head);
      if (glo.bigb == NULL)
	{
	  lines = getline(&glo.line_buff, &buff_size, glo.fp);
	  continue;
	}
      check = get_opcode(&head, counter);
      op_check(check, counter, head);
      lines = getline(&glo.line_buff, &buff_size, glo.fp);
    }
  free_buff();
  free_stack(head);
  return (0);
}
