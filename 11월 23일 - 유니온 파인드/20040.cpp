//20040 사이클 게임
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
#define INF 1000001
int cycle = INF;

int findParent (int node){
    if(parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionInput(int count, int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp){ // 같은 집합
        if(cycle > count)
            cycle = count;
        return;
    }

    if(parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else{
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}



int main () {
    int n, m, x, y;
    cin >> n >> m;
    parent.assign(n+1, -1);
    int count = 0;
    while(m--){
        cin >> x >> y;
        unionInput(++count, x, y);
    }

    if(cycle == INF)
        cout << 0;
    else
        cout << cycle;
    return 0;
}