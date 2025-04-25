#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "qnode.h"
#include "utils.h"

typedef struct Node Node;
typedef struct Node {
	void* data;
	uint8_t cost;
	uint8_t visited;
	uint8_t path_from;
}Node;


typedef struct AdjMatrix AdjMatrix;
struct AdjMatrix {
	int** adjGraph;// Essentiellement: int[][]
	Node* nodes;
	size_t len;
	size_t max_size;
};


AdjMatrix* create_graph(size_t max_nodes);

void add_node(AdjMatrix* graph, void* data);

void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost);