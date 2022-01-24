// 2011 암호코드
#include <iostream>
#include <vector>

#define SIZE 1000000
using namespace std;

int main (){
    string code;
    vector<int> dp(5000, 0);
    cin >> code;

    bool avail = true;
    if(code[0]=='0'){
        avail = false;
    }
    else dp[0] = 1;

    for(int i = 1 ; i < code.length() ; i++){
        int cur = code[i]-'0';
        int pre = code[i-1] - '0';

        //dp[1]
        if(i == 1) {
            if (pre*10 + cur <= 26) {
                if(code[i]=='0') dp[i] = 1; // ex) 10
                else dp[i] = 2; // ex)15
            }
            else{
                if(code[i]=='0'){ // ex) 50 => 불가능한 암호
                    avail = false;
                }
                else dp[i] = 1; // ex) 51, 52 ...
            }
            continue;
        }

        //dp[2]~
        if (pre*10 + cur <= 26){ //알파벳 두자리 가능
            dp[i] = dp[i-2] % SIZE + dp[i-1] % SIZE;
            if(cur==0 && pre==0){ //1464654341 00 44636
                avail = false;
            }
            else if (cur== 0) { // 63876746 20 6346676
                dp[i] = dp[i - 2];
            }else if (pre==0){ // 63876746 02 6346676
                dp[i] = dp[i - 1];
            }
        }else {
            dp[i] = dp[i-1] % SIZE;
            if (cur== 0) avail = false;
        }
    }

    if(!avail){
        cout << 0;
    }
    else cout << dp[code.length()-1] % SIZE;

    return 0;
}