// -----------------------------------------------------------------------------
// File: main.c
// Author: John Pascoal
// Created on: 2025-05-13 at 20:01:01
// Updated on: 2025-05-14 at 11:34:21
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"

int	main(void)
{
	Stack stack;
	Node *removed_node;
	create_stack(&stack);

	printf("Empty: %d\n", is_empty(&stack));
	push(0, &stack);
	push(5, &stack);
	push(8, &stack);
	push(1, &stack);
	push(9, &stack);
	push(2, &stack);
	printf("Size before delete: %d\n", size(&stack));
	removed_node = peek(&stack);
	printf("The top is: %d\n", removed_node->value);
//	free(removed_node);
	printf("Size after delete: %d\n", size(&stack));
	print(&stack);

	printf("\nEmpty after: %d\n", is_empty(&stack));
	destroy_stack(&stack);

	return (0);
}
