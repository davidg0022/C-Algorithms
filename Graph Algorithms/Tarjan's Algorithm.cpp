#include<vector>
#include<iostream>
#include<stack>

using namespace std;
#define NLIM 100005

int n, m, id, cnt;
vector<bool> V;
vector<int> G[NLIM];
vector<int> Ids, Low;
stack<int> S;


void dfs(int nod){
    S.push(nod);
    V[nod] = true;
    Ids[nod] = Low[nod] = ++id;
    for(int i:G[nod]){
        if(!Ids[i])
            dfs(i);
        if(V[i])
            Low[nod] = min(Low[nod], Low[i]);
        }
    if(Ids[nod]==Low[nod]){
        for (int j = S.top();;j=S.top()){
            V[j] = false;
            Low[j] = Ids[nod];
            S.pop();
            if(j==nod)
                break;
            
        }
        cnt++;
    }
}


void tarjan(){
    V = vector<bool>(n + 1, false);
    Ids = vector<int>(n + 1, 0);
    Low = vector<int>(n + 1, 0);
    for (int i = 1; i <= n;i++)
        if(!Ids[i])
            dfs(i);
}


void read(){
    cin >> n >> m;
    for (int x, y, i = 1; i <= m;i++)
        cin >> x >> y,
        G[x].push_back(y);
       
}
int main(){
    read();
    tarjan();
    cout << cnt;
}