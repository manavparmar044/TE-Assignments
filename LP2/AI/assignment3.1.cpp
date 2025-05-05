#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution
{
    typedef pair<int, int> P;
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if (inMST[node])
                continue;

            inMST[node] = true;
            sum += wt;

            for (auto &tmp : adj[node]) {
                int neighbor = tmp[0];
                int neighbor_wt = tmp[1];

                if (!inMST[neighbor]) {
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }

        return sum;
    }
};

int main() {
    int V = 4;

    // Create adjacency list for an undirected weighted graph
    vector<vector<int>> adj[V];

    // Adding edges: (u, v, weight)
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});

    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});

    adj[1].push_back({3, 6});
    adj[3].push_back({1, 6});

    adj[2].push_back({3, 3});
    adj[3].push_back({2, 3});

    Solution obj;
    int result = obj.spanningTree(V, adj);
    cout << "Sum of weights of MST: " << result << endl;

    return 0;
}
