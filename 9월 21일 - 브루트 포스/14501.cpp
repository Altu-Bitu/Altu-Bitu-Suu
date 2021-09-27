//14501 퇴사
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> input(N+1, {0, 0});
    vector<int> dp(N+1, 0); //n일까지 최대 이익
    for(int i = 1 ; i <= N ; i++){
        int a, b;
        cin >> a >> b;
        input[i] = {a, b};
    }

    if(input[1].first==1) dp[1] = input[1].second;

    for(int i = 1 ; i <= N ; i++) {
        for(int j = 1 ; j <= i ; j++){
            if(input[j].first + j <= i+1){
                dp[i] = max(dp[i], dp[j-1] + input[j].second);
            }
        }
    }
    cout << dp[N];
    return 0;
}