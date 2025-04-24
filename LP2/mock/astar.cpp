#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int check(vector<vector<int>> src,vector<vector<int>> dest){
    int cnt = 0;
    for(int i = 0;i<src.size();i++){
        for(int j = 0;j<src[0].size();j++){
            if(src[i][j]!=dest[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

struct Node{
    vector<vector<int>> state;
    int g;
    int f;
    int h;
    int x;
    int y;
    Node(vector<vector<int>> state, int g, int h, int x, int y) {
        this->state = state;
        this->g = g;
        this->h = h;
        this->f = g + h;
        this->x = x;
        this->y = y;
    }
};

bool operator>(const Node &a, const Node &b){
    return a.f > b.f;
}

void printState(vector<vector<int>> &state, int f){
    for(int i = 0;i<state.size();i++){
        for(int j = 0;j<state[0].size();j++){
            cout<<state[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"f(n) = "<<f<<endl;
}

void astar(vector<vector<int>> src,vector<vector<int>> dest){
    int n = src.size();
    int m = src[0].size();
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<vector<vector<int>>> visited;
    int startX,startY;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(src[i][j] == 0){
                startX = i;
                startY = j;
                break;
            }
        }
    }
    int h = check(src,dest);
    Node start(src,0,h,startX,startY);
    pq.push(start);
    visited.insert(src);

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!pq.empty()){
        Node current = pq.top();
        pq.pop();
        if(current.state == dest){
            cout<<"Goal state reached"<<endl;
            return;
        }
        for(int i = 0;i<4;i++){
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                swap(current.state[current.x][current.y],current.state[newX][newY]);
                if(visited.find(current.state) == visited.end()){
                    int newH = check(current.state,dest);
                    Node nextState(current.state,current.g + 1,newH,newX,newY);
                     pq.push(nextState);
                    visited.insert(current.state);
                                        cout << "Current state after move (f(n) = " << nextState.f << "):" << endl;
                    printState(current.state, nextState.f);
                }
                swap(current.state[current.x][current.y], current.state[newX][newY]);
            }
        }
    }
    cout << "No solution found!" << endl;
}

int main() {
    vector<vector<int>> src = {
        {0, 2, 3},
        {1, 4, 5},
        {7, 8, 6}
    };
    vector<vector<int>> dest = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    astar(src, dest);
    return 0;
}