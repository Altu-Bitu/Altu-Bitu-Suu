//9019번 DSLR
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string bfs(int a, int b, vector<pair<int, char>> & path){
    string ans = "";
    queue<int> q;
    vector<int> check(10000, 0);
    q.push(a);
    check[a] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        //종료 조건
        if(cur == b){
            while(path[cur].first!= -1){
                ans += path[cur].second;
                cur = path[cur].first;
            }
            break;
        }

        int next;
        //D
        next = (cur * 2) % 10000;
        if(!check[next]){
            check[next] = check[cur] + 1;
            path[next] = {cur, 'D'};
            q.push(next);
        }

        //S
        if(cur == 0)
            next = 9999;
        else
            next = cur - 1;

        if(!check[next]){
            check[next] = check[cur] + 1;
            path[next] = {cur, 'S'};
            q.push(next);

        }

        //L
        next = (cur * 10) % 10000 + cur / 1000;
        if(!check[next]){
            check[next] = check[cur] + 1;
            path[next] = {cur, 'L'};
            q.push(next);
        }

        //R
        next = (cur / 10)  + (cur % 10) * 1000;

        if(!check[next]) {
            check[next] = check[cur] + 1;
            path[next] = {cur, 'R'};
            q.push(next);
        }

    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int A, B;
        cin >> A >> B;
        vector<pair<int, char>> path(10000, {-1, ' '});
        string ans = bfs(A, B, path);
        for(int i = ans.length()-1 ; i >= 0 ; i--){ //역순 출력
            cout << ans[i];
        }
        cout << "\n";
    }

    return 0;
}