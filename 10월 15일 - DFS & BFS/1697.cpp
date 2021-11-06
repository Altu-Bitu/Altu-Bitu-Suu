//1697 숨바꼭질
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited(100001, false) ; //메모리초과가 뜬다면 방문처리를..

int bfs(int N, int K, queue<pair<int, int>> q) {
    while (!q.empty()) {
        int cur = q.front().first;
        int t = q.front().second;
        q.pop();
        //하나 꺼냄
        visited[cur] = true;
        if(cur==K) return t;

        if(2*cur<=100000 && !visited[2*cur]) q.push({2*cur, t+1});
        if(0<=cur-1 && !visited[cur-1]) q.push({cur-1, t+1});
        if(cur+1<=100000 && !visited[cur+1]) q.push({cur+1, t+1});
    }
    return -1;
}
int main(){
    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> q; //위치 저장 큐
    q.push({N, 0});
    cout << bfs(N, K, q);

    return 0;
}