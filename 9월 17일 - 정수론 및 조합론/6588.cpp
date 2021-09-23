// 6588 골드바흐의 추측
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<bool> is_prime(1000001, true);

int isPrime(int n) {
    for (int i = 3; i <= n; i+=2) {
        if(is_prime[i] && is_prime[n - i]){
            return i; //두 수 전부 소수
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //에라토스테네스의 체
    for (int i = 2; i < sqrt(1000000); i++) {
        if (is_prime[i]) { //i가 소수라면
            for (int j = i * 2 ; j <= 1000000; j += i) {
                if (!is_prime[j]) //이미 지워진 수라면 넘어감
                    continue;
                is_prime[j] = false; //i의 배수를 제거
            }
        }
    }

    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        int a, b;
        a = isPrime(n); //홀수 소수 중 최소
        b = n - a;
        if(a!=-1)
            cout << n << " = " << a << " + " << b << "\n";
        else
            cout << "Goldbach's conjecture is wrong.";

    }
    return 0;
}