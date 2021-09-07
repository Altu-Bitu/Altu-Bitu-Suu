//1431 시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> word;

void printArr(int N){
    for(int i = 0 ; i < N ; i++)
        cout << word[i] << "\n";
}

bool compare(string A, string B){
    //1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    if(A.length() != B.length())
        return A.length() < B.length();
    //2. 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)

    int sumA = 0;
    int sumB = 0;
    for(int i = 0 ; i < A.length() ; i++){
        if(A[i]-'0' < 10)
            sumA += A[i]-'0';
        if(B[i]-'0' < 10)
            sumB += B[i]-'0';
    }
    if(sumA != sumB)
        return sumA < sumB;
    //3. 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
    for(int i = 0 ; i < A.length() ; i++){
        if(A[i]!=B[i]){
            return (A[i]-'0') < (B[i]-'0');
        }
    }
}

int main(){
    int N;
    cin >> N;
    word.assign(N, "");
    for(int i = 0 ; i < N ; i++){
        cin >> word[i];
    }

    sort(word.begin(), word.end(), compare);
    printArr(N);
    return 0;
}
