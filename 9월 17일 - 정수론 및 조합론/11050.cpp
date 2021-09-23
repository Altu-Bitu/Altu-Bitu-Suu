//11050 이항 계수1
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int factorial(int n){
    int a = 1;
    for(int i = 1 ; i <= n ; i++)
        a *= i;
    return a;
}
int main(){
    int N, K;
    dp.assign(11, 1);
    cin >> N >> K;
    //nCk = n! / ((n-k)! * k!)
    cout << factorial(N) / factorial(N-K) / factorial(K);
    return 0;
}