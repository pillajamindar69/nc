#include <stdio.h> 
#define MAX 10  
#define INF 999 


void distance_vector_routing(int cost[MAX][MAX], int n) {
    int distance[MAX][MAX], i, j, k;

  
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            distance[i][j] = cost[i][j]; 
        }
    }

    
    for (k = 0; k < n; k++) { 
        for (i = 0; i < n; i++) { 
            for (j = 0; j < n; j++) { 
               
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

  
    for (i = 0; i < n; i++) {
        printf("\nRouting Table for Node %d:\n", i + 1); 
        printf("Destination\tDistance\n");
        for (j = 0; j < n; j++) {
            printf("%d\t\t%d\n", j + 1, distance[i][j]); 
        }
    }
}


void main() {
    int cost[MAX][MAX], n, i, j;

    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

  
    printf("Enter the cost adjacency matrix (enter %d for infinity):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Cost from Node %d to Node %d: ", i + 1, j + 1);
            scanf("%d", &cost[i][j]); 
        }
    }

   
    distance_vector_routing(cost, n);
}