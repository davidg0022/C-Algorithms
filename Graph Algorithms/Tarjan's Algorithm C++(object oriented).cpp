#include<vector>
#include<iostream>
#include<stack>
using namespace std;


int n, m, id, cnt;
vector<bool> V;
vector<int> Ids, Low;
stack<int> S;
class  g{
    vector<int>*adjacency_list;
    int Nodes;
public:
    g(int n){
        Nodes = n + 1;
        adjacency_list = new vector<int>[Nodes];
    }

    void add_edge(int u,int v){
        adjacency_list[u].push_back(v);
    }
    vector<int>Adj(int x){
        return adjacency_list[x];
    }
};

void dfs(int node,g Graph){
    V[node] = true;
    S.push(node);
    Ids[node] = Low[node] = ++id;
    for(int i:Graph.Adj(node)){
        if(!Ids[i])
            dfs(i,Graph);
        if(V[i])
            Low[node] = min(Low[i], Low[node]);
    }
    if(Low[node]==Ids[node]){
        for (int j = S.top();; j = S.top()){
            S.pop();
            Low[j] = Ids[node];
            V[j] = false;
            if(j==node)
                break;
        }
        cnt++;
    }
}

void tarjan(g Graph){
    V = vector<bool>(n + 1, false);
    Ids = Low = vector<int>(n + 1, 0);
    for (int i = 1; i <= n;++i)
        if(!Ids[i])
            dfs(i, Graph);
}

int main(){
    cin >> n >> m;
    g Graph(n);
    for (int x, y, i = 1; i <= m;i++)
        cin >> x >> y,
        Graph.add_edge(x,y);
    tarjan(Graph);
    cout << cnt;
}