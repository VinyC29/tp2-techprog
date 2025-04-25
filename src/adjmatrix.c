#include "adjmatrix.h"

AdjMatrix* create_graph(size_t max_nodes) {
    AdjMatrix* newMatrix = allocate(sizeof(AdjMatrix));

    newMatrix->len = 0;
    newMatrix->max_size = max_nodes;
    newMatrix->nodes = allocate(max_nodes * sizeof(Node));

    for (int i = 0; i < max_nodes; i++) {
        newMatrix->nodes[i].cost = UINT8_MAX;
        newMatrix->nodes[i].path_from = UINT8_MAX;
        newMatrix->nodes[i].visited = 0;
    }

    newMatrix->adjGraph = allocate(max_nodes * sizeof(int*));
    for (int i = 0; i < max_nodes; i++) {
        newMatrix->adjGraph[i] = allocate(max_nodes * sizeof(int));
        for (int j = 0; j < max_nodes; j++) {
            newMatrix->adjGraph[i][j] = 0;
        }
    }

    return newMatrix;
}

void add_node(AdjMatrix* graph, void* data) {
    graph->nodes[graph->len].data = data;
    graph->nodes[graph->len].cost = UINT8_MAX;
    graph->nodes[graph->len].visited = 0;
    graph->nodes[graph->len].path_from = UINT8_MAX;
    graph->len++;
}

void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost) {
    graph->adjGraph[fromNode][toNode] = cost;
}