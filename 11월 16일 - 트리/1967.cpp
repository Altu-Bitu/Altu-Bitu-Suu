//1967 트리의 지름
#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int,int>>> tree;
vector<bool> visited;
int leaf_node = 0;
int radius = 0;

void dfs(int root, int parent, int weight){
    if(tree[root].size()==1 && root!=1){ //부모 노드 하나 들어가있음
        if(radius < weight){
            radius = weight;
            leaf_node = root;
        }
        return;
    }
    for(int i = 0 ; i < tree[root].size() ; i++){
        if(tree[root][i].first != parent)
            dfs(tree[root][i].first, root, weight + tree[root][i].second);
    }
}

void dfs2(int root, int weight){
    if(tree[root].size()==1){ //부모 노드 하나 들어가있음
        if(radius < weight){
            radius = weight;
            leaf_node = root;
        }
        return;
    }
    visited[root] = true;
    for(int i = 0 ; i < tree[root].size() ; i++){
        if(!visited[tree[root][i].first]) // 방문 X
            dfs2(tree[root][i].first, weight + tree[root][i].second);
    }
}

int main () {
    int n, parent, child, weight;
    cin >> n;
    visited.assign(n+1, false);
    tree.assign(n+1, {});

    if(n==1){
        cout << 0;
        return 0;
    }
    n--;
    while(n--){
        cin >> parent >> child >> weight;
        tree[parent].push_back(make_pair(child, weight));
        tree[child].push_back(make_pair(parent, weight));
    }

    dfs(1, -1, 0);

    visited[leaf_node] = true;
    dfs2(tree[leaf_node][0].first, tree[leaf_node][0].second);
    cout << radius;

    return 0;
}