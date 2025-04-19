#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<bool> visited(N, false);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void dfs(int node) {
    cout << node << " ";
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor);
    }
}

int main(){
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    cout<<"Enter edges (u,v) form \n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove for directed graph
    }

     cout << "DFS starting from node 0:\n";
    dfs(0);
    cout << "\n";

    // Reset visited array before BFS
    fill(visited.begin(), visited.end(), false);

    cout << "BFS starting from node 0:\n";
    bfs(0);
    cout << "\n";

}