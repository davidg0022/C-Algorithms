#include <iostream>
#include <vector>
using namespace std;


#define NLIM 10005
int n, m, cnt;
bool ctc[NLIM];
vector<int> G[NLIM];
vector<int> GT[NLIM];
vector<bool> V;
vector<int> S;

void dfs(int nod){
    V[nod] = true;
    for(int i:G[nod])
        if(!V[i])
            dfs(i);
    S.push_back(nod);
}

void dfsGT(int nod){
    V[nod] = true;
    for(int i:GT[nod])
        if(!V[i])
            dfsGT(i);
}


void citire(){
    cin >> n >> m;
    for (int x, y, i = 1; i <= m;++i)
        cin >> x >> y,
        G[x].push_back(y),
        GT[y].push_back(x);
    
    V = vector<bool>(n + 1, false);
    
    for (int i = 1; i <= n;i++)
        if(!V[i])
            dfs(i);
    
    V = vector<bool>(n + 1, false);

    for (vector<int>::reverse_iterator it = S.rbegin(); it != S.rend(); it++)
        if(!V[*it])
            cnt++,
            dfsGT(*it);
    cout << cnt;
}

int main()
{
    citire();
    return 0;
}