#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

class Graph{
    public:
    unordered_map<int,vector<int>> adj;

    void addNode(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void bfs(int src,int n){
        queue<int> q;
        vector<int> vis(n+1,0);
        vector<int> ans;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it: adj[node]){
                if(vis[it] == 0){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        cout<<"BFS is: "<<endl;
        for(int i = 0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    void dfs(int src,vector<int> &visited,vector<int> &res){
        visited[src] = true;
        res.push_back(src);
        for(auto &it: adj[src]){
            if(visited[it] == 0){
                dfs(it,visited,res);
            }
        }
    }
};

int main(){
    Graph g;
    int n = 5;
    g.addNode(0,1);
    g.addNode(1,2);
    g.addNode(1,3);
    g.addNode(2,3);
    g.addNode(2,4);

    g.bfs(0,n);
    vector<int> visited(n+1,0);
    vector<int> res;
    g.dfs(0,visited,res);

    cout<<"DFS is: "<<endl;
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}