// -----------------------------------------------------------------------------
// File: stack.h
// Author: John Pascoal
// Created on: 2025-05-14 at 00:04:54
// Updated on: 2025-05-14 at 00:10:57
// -----------------------------------------------------------------------------

#ifndef _STACK_H
#define _STACK_H

typedef struct node {
	int	value;
	struct node *next;
} Node;

typedef struct {
	Node	*top;
	int	size;
} Stack;

void	create_stack(Stack *stack);

void	push(int value, Stack *stack);

Node	*pop(Stack *stack);

void	print(const Stack *stack);

#endif
