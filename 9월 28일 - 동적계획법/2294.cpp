//2294 동전2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> coin(n, 0);
    vector<bool> visit(k+1, false); //메모리 초과 방지
    queue<int> index;
    vector<int> dp(k + 1, 10001); // index : 동전의 가치, 값 : 사용한 동전 개수 , 10000으로 초기화하면 안됨 주의

    for(int i = 0 ; i < n ; i++){
        cin >> coin[i];
    }

    for(int i = 0 ; i < n ; i++){
        if(coin[i]<= k){
            dp[coin[i]] = 1;
            index.push(coin[i]);
        }
    }

    while(!index.empty()){
        int a = index.front();
        index.pop();

        if(visit[a]) continue;
        visit[a] = true;

        for(int i = 0 ; i < n ; i++){
            if(a + coin[i] <= k){
                dp[a + coin[i]] = min(dp[a] + 1, dp[a + coin[i]]);
                index.push(a + coin[i]);
            }
        }
    }

    if(dp[k] == 10001) cout << -1;
    else cout << dp[k];
    return 0;
}