#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "utils.h"


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