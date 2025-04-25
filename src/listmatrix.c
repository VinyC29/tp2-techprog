#include "listmatrix.h"

Node* create_node(void* data) {
	Node* newNode = allocate(sizeof(Node));
	memset(newNode->adj, 0, sizeof(Node*) * UINT8_MAX);
	newNode->visited = 0;
	newNode->len = 0;
	newNode->revPath = allocate(sizeof(QNode));
	newNode->revPath->prev = NULL;
	newNode->data = data;
	return newNode;
}

void add_adjacent_node(Node* root, Node* node) {
	root->adj[root->len] = node;
	root->len++;

}
