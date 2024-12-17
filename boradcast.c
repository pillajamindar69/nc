#include <stdio.h>
#define INF 9999
#define V 4
void broadcastTree(int graph[V][V]) {
 int selected[V] = {0};
 selected[0] = 1; // Start from node 0
 printf("Broadcast Tree Edges:\n");
 for (int edges = 0; edges < V - 1; edges++) {
 int min = INF, x = 0, y = 0;
 for (int i = 0; i < V; i++) {
 if (selected[i]) {
 for (int j = 0; j < V; j++) {
 if (!selected[j] && graph[i][j] && graph[i][j] < min) {
 min = graph[i][j];
 x = i;
 y = j;
 }
 }
 }
 }
 printf("%d -> %d (Cost: %d)\n", x, y, graph[x][y]);
 selected[y] = 1;
 }
}
int main() {
 int graph[V][V] = {
 {0, 2, INF, 6},
 {2, 0, 3, 8},
 {INF, 3, 0, 5},
 {6, 8, 5, 0},
 };
 broadcastTree(graph);
 return 0;
}
