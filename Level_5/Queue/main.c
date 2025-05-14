// -----------------------------------------------------------------------------
// File: main.c
// Author: John Pascoal
// Created on: 2025-05-14 at 21:46:35
// Updated on: 2025-05-14 at 22:32:31
// -----------------------------------------------------------------------------

#include <stdio.h>
#include "include/queue.h"

int	main(void)
{
	Queue queue;
	init(&queue);

	add(&queue, 5);
	add(&queue, 4);
	add(&queue, 1);
	add(&queue, 9);
	add(&queue, 0);

	print(&queue);
	printf("\n%d", peek(&queue)->value);

	destroy_queue(&queue);

	return (0);
}
