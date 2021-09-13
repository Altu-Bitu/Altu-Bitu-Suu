//2015 수들의 합 4
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A; //입력값 저장 배열
    map<long long, long long> P; // 부분합, 부분합 개수
    A.assign(N, 0);

    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
    long long count = 0;
    long long partial_sum = 0;
    for(int i = 0 ; i < N ; i++){
        partial_sum += A[i];
        if(partial_sum==K) count++;
        long long target = partial_sum - K;
        count += P[target];
        P[partial_sum]++;
        /* ㅠㅠㅠ 부분합 = K 인 경우랑 부분합 - K = 부분합 인 경우를 구분하지 못해서
         * P[partial_sum]++를 count 앞으로 보내는 바람에 고생했습니다...
         */
    }
    cout << count;
    return 0;
}
