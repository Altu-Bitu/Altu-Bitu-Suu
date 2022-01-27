//15681 트리와 쿼리

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> dp;

int nodeCount(int R) {
    for (int i = 0; i < tree[R].size(); i++) {
        int new_node = tree[R][i];
        if (visited[new_node]) //이미 방문한 정점
            continue;
        visited[new_node] = true;

        dp[R] += nodeCount(new_node);
    }
    return dp[R];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, R, Q, a, b, U;
    cin >> N >> R >> Q ;

    tree.assign(N + 1, vector<int>(0));
    visited.assign(N + 1, false);
    dp.assign(N + 1, 1);

    N--;
    while(N--){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    visited[R] = true;
    nodeCount(R);
    while(Q--){
        cin >> U;
        cout << dp[U] << "\n";
    }

    return 0;
}