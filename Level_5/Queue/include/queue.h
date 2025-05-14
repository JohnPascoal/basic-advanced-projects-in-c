// -----------------------------------------------------------------------------
// File: queue.h
// Author: John Pascoal
// Created on: 2025-05-14 at 20:39:34
// Updated on: 2025-05-14 at 22:29:01
// -----------------------------------------------------------------------------

#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct node {
	int	value;
	struct node *next;
}Node;

typedef struct {
	Node	*first;
	Node	*last;
	int	size;
}Queue;

void	init(Queue *queue);

int	is_empty(const Queue *queue);

void	add(Queue *queue, int value);

Node	*peek(const Queue *queue);

Node	*remove_node(Queue *queue);

void	print(const Queue *queue);

void	destroy_queue(Queue *queue);

#endif
