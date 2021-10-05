//10844 쉬운 계단 수
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<long long>> dp(N, vector<long long>(10, 0));

    for(int i = 1 ; i < 10 ; i++)
        dp[0][i] = 1;

    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(j==0){
                dp[i][j] = dp[i-1][1] % 1000000000;
            }
            else if(j==9){
                dp[i][j] = dp[i-1][8] % 1000000000;
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
            }
        }
    }

    long long sum = 0;
    for(int i = 0 ; i < 10 ; i++){
        sum += dp[N-1][i];
    }
    cout << sum % 1000000000;

    return 0;
}
