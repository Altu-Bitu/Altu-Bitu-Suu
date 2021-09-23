//9613 GCD 합
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) //b가 0이면 a가 최대공약수
        return a;
    //a%b구한 후 b와 자리 바꾸어서 호출
    return gcd(b, a % b);
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> input;
        input.assign(n, 0);
        for(int i = 0 ; i < n ; i++){
            cin >> input[i];
        }
        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                sum += gcd(input[i], input[j]);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}