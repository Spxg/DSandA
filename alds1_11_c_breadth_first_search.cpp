#include <cstdio>
#include <queue>
#define LEN 100

int matrix[LEN][LEN] = { 0 };
int dist[LEN];
int n = 0;

using namespace std;

void bfs(int node) {
    queue<int> queue;
    queue.push(node);
    dist[node] = 0;
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int i = 0; i < n; i++) {
            if (matrix[u][i] == 0) { continue; }
            if (dist[i] == 1) { continue; }
            dist[i] = dist[u] + 1;
            queue.push(i);
        }
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int node, degree;
        scanf("%d %d", &node, &degree);
        for (int i = 0; i < degree; i++) {
            int v;
            scanf("%d", &v);
            matrix[node - 1][v - 1] = 1; 
        }
    }

    for (int i = 0; i < n; i++) { dist[i] = -1; }

    bfs(0);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i + 1, dist[i]);
    }
    return 0;
}
