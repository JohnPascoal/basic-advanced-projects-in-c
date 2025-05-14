// -----------------------------------------------------------------------------
// File: stack.c
// Author: John Pascoal
// Created on: 2025-05-14 at 00:09:02
// Updated on: 2025-05-14 at 11:31:12
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"

void	create_stack(Stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	push(int value, Stack *stack)
{
	Node *new_node;
	new_node = malloc(sizeof(Node));

	if (!new_node)
	{
		printf("Error allocating memory");
		return;
	}
	else
	{
		new_node->next = stack->top;
		new_node->value = value;
		stack->top = new_node;
		stack->size++;
	}
}

Node	*pop(Stack *stack)
{
	Node *old_top;

	if (!stack->top)
	{
		printf("Top is null");
		return NULL;
	}
	
	old_top = stack->top;
	stack->top = old_top->next;
	stack->size--;

	return (old_top);
}

void	destroy_stack(Stack *stack)
{
	while (stack->top)
	{
		Node	*temp;
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
}

int	is_empty(const Stack *stack)
{
	return stack->top == NULL;
}

int	size(const Stack *stack)
{
	return stack->top != NULL? stack->size : 0;
}

Node	*peek(const Stack *stack)
{
	return stack->top != NULL? stack->top : NULL;
}

void	print(const Stack *stack)
{
	const Node *aux = stack->top;
	while(aux)
	{
		printf("%d\n", aux->value);
		aux = aux->next;
	}
}
