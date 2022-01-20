//1로 만들기 2
#include <iostream>
#include <vector>
#include <queue>

#define SIZE 1000001
using namespace std;
int main (){
    int X, cur, ans;
    cin >> X;
    vector<int> dp(SIZE, 0);
    vector<int> path(SIZE, -1);
    queue<int> q;

    q.push(X);
    while(!q.empty()){
        cur = q.front();
        q.pop();

        //종료 조건
        if(cur==1){
            ans = dp[cur];
            break;
        }

        //연산 1
        if(cur % 3 == 0 && dp[cur/3]==0 ){
            dp[cur/3] = dp[cur] + 1;
            path[cur/3] = cur;
            q.push(cur/3);
        }

        //연산 2
        if(cur % 2 == 0 && dp[cur/2]==0 ){
            dp[cur/2] = dp[cur] + 1; // dp[5] = 1
            path[cur/2] = cur; //path[5] = 10
            q.push(cur/2);
        }

        //연산 3
        if(dp[cur-1]==0 ){
            dp[cur-1] = dp[cur] + 1; //dp[9]
            path[cur-1] = cur;
            q.push(cur-1);
        }
    }

    cur = 1;
    vector<int> result;
    while(cur!=-1){
        result.push_back(cur);
        cur = path[cur];
    }

    cout << ans << "\n";
    for(int i = result.size()-1 ; i >= 0 ; i--){
        cout << result[i] << " ";
    }
    return 0;
}