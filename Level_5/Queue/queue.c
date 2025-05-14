// -----------------------------------------------------------------------------
// File: queue.c
// Author: John Pascoal
// Created on: 2025-05-14 at 20:39:34
// Updated on: 2025-05-14 at 22:31:03
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "include/queue.h"

void	init(Queue *queue)
{
	queue->first = NULL;
	queue->last = NULL;
	queue->size = 0;
}

int	is_empty(const Queue *queue)
{
	return queue->first == NULL;
}

void	add(Queue *queue, int value)
{
	Node *new_node;
	new_node = malloc(sizeof(Node));
	if (!new_node)
	{
		printf("Error allocating memory");
		free(new_node);
		return;
	}
	new_node->value = value;
	new_node->next = NULL;
	if (!queue->first)
	{
		queue->first = new_node;
		queue->last = new_node;
	}
	else
	{
		queue->last->next = new_node;
		queue->last = new_node;
	}
	queue->size++;
}

Node	*remove_node(Queue *queue)
{
	Node *del_node;
	
	if (!queue->first)
	{
		printf("Empty list");
		return (NULL);
	}
	del_node = queue->first;
	queue->first = del_node->next;
	queue->size--;

	return (del_node);
}

Node	*peek(const Queue *queue)
{
	return queue->first != NULL? queue->first : NULL;
}

void	print(const Queue *queue)
{
	Node *current;
	current = queue->first;
	while (current)
	{
		printf("%d ",current->value);
		current = current->next;
	}
}

void	destroy_queue(Queue *queue)
{
	while (queue->first != NULL)
	{
		Node *temp = queue->first;
		queue->first = temp->next;
		free(temp);
	}
}
