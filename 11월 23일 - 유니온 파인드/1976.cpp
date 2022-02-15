//1976 여행가자
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node){
    if(parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp)
        return;
    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

void findAnswer(vector<int> &plan, int M){
    for(int i = 0 ; i < M-1 ; i++){
        if(findParent(plan[i]) != findParent(plan[i+1])){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main () {
    int N, M;
    cin >> N >> M;
    parent.assign(N+1, -1);
    vector<vector<int>> city(N+1, vector<int>(N+1, 0));
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> city[i][j];
            if(city[i][j]){
                unionInput(i, j);
            }
        }
    }

    vector<int> plan(M, 0);
    for(int i = 0 ; i < M ; i++){
        cin >> plan[i];
    }

    findAnswer(plan, M);

    return 0;
}