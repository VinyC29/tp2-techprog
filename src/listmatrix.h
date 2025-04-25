#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "utils.h"
#include "qnode.h"

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