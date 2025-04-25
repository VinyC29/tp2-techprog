#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "utils.h"


typedef struct {
	void** elements;
	int top;
	size_t max;
} Stack;

Stack stack_init(size_t max_size);
void stack_push(Stack* s, void* element);
void* stack_pop(Stack* s);

typedef struct QNode QNode;
typedef struct QNode {
	void* data;
	QNode* prev;
	QNode* next;
	size_t count;
}Queue;

void queue_init(Queue* q);
void queue_push(Queue* q, void* data);
void* queue_pop(Queue* q);


typedef struct Node Node;
typedef struct Node {
	void* data;
	Node* adj[UINT8_MAX];
	uint8_t len;
	uint8_t visited;
	QNode* revPath;
}Node;


Node* create_node(void* data);

void add_adjacent_node(Node* root, Node* node);