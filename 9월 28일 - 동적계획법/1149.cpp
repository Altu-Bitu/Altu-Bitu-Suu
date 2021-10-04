//1149 RGB 거리
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> input(N, vector<int>(3, 0));
    vector<vector<int>> dp(N, vector<int>(3, 1000001)); // 1000*1000+1

    for(int i = 0 ; i < N ; i++){
        for( int j = 0 ; j < 3 ; j++){
            cin >> input[i][j];
            if(i==0) dp[0][j]= input[0][j]; //첫 줄 초기화
        }
    }

    for(int i = 1 ; i < N ; i++){
        for( int j = 0 ; j < 3 ; j++){
            if(j==0){
                dp[i][j] = min(dp[i][j], min(input[i][j] + dp[i-1][1], input[i][j] + dp[i-1][2]));
            }else if(j==1){
                dp[i][j] = min(dp[i][j], min(input[i][j] + dp[i-1][0], input[i][j] + dp[i-1][2]));
            }else{
                dp[i][j] = min(dp[i][j], min(input[i][j] + dp[i-1][1], input[i][j] + dp[i-1][0]));
            }
        }
    }

    int answer = 1000001;
    for(int i = 0 ; i < 3 ; i++){
        answer = min(answer, dp[N-1][i]);
    }

    cout << answer;

    return 0;
}