// -----------------------------------------------------------------------------
// File: main.c
// Author: John Pascoal
// Created on: 2025-05-13 at 20:01:01
// Updated on: 2025-05-14 at 00:49:20
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"

int	main(void)
{
	Stack stack;
	Node *removed_node;
	create_stack(&stack);

	push(3, &stack);
	push(5, &stack);
	push(8, &stack);
	push(1, &stack);
	push(9, &stack);
	push(2, &stack);
	printf("Size before delete: %d\n", stack.size);
	removed_node = pop(&stack);
	free(removed_node);
	printf("Size after delete: %d\n", stack.size);
	print(&stack);

	while (stack.top)
	{
		Node *temp = stack.top;
		stack.top = stack.top->next;
		free(temp);
	}

	return (0);
}
