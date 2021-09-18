#include<vector>
#include<iostream>
#include<stack>
using namespace std;

int n, m, id, cnt;
vector<bool> V;
vector<int> Ids, Low;
stack<int> S;
class  g{
    vector<int>*G;
    vector<int> *GR;
    int Nodes;
public:
    g(int n){
        Nodes = n + 1;
        G = new vector<int>[Nodes];
        GR = new vector<int>[Nodes];
    }

    void add_edge(int u,int v){
        G[u].push_back(v);
        GR[v].push_back(u);
    }
    vector<int>Adj(int x){
        return G[x];
    }
    vector<int>AdjR(int x){
        return GR[x];
    }
};


void dfs(int Node,g Graph){
    V[Node] = true;
    for(int i:Graph.Adj(Node))
        if(!V[i])
            dfs(i, Graph);
    S.push(Node);
}

void dfsT(int Node,g Graph){
    V[Node] = true;
    for(int i:Graph.AdjR(Node))
        if(!V[i])
            dfsT(i, Graph);
}

void solve(g Graph){
    V = vector<bool>(n + 1, false);
    for (int i = 1; i <= n;++i)
        if(!V[i])
            dfs(i,Graph);
    
    V = vector<bool>(n + 1, false);
    while(!S.empty()){
        if(!V[S.top()])
            dfsT(S.top(), Graph),
            cnt++;
        S.pop();
    }
    cout << cnt;
}

void read(){
    cin >> n >> m;
    g Graph(n);
    for (int x, y, i = 1; i <= m;i++)
        cin >> x >> y,
        Graph.add_edge(x, y);
    solve(Graph);
}

int main(){
    read();
}