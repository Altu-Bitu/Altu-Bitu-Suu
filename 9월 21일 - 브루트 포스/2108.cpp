//2108 통계학
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> input(N, 0);
    vector<int> A(8001, 0); //최빈값을 구하기위해 만듬. 0~8000 = -4000~4000
    set<int> B;
    double average = 0;
    int frequent = 0;

    for(int i = 0 ; i < N ; i++){
        cin >> input[i];
        average+=input[i];
        A[input[i]+4000]++;
    }

    cout << round(average/N) << "\n"; //1. 산술평균

    sort(input.begin(), input.end());
    cout << input[(N-1)/2] << "\n"; //2. 중앙값

    for(int i = 0 ; i < N ; i++){
        if(A[input[i]+4000]>frequent) frequent = A[input[i]+4000];
    }
    for(int i = 0 ; i < N ; i++){
        if(A[input[i]+4000]==frequent) B.insert(input[i]);
    }

    if(B.size()!=1) {
        B.erase(B.begin());
    }
    cout << *B.begin() <<"\n"; //3. 최빈값

    cout << input[N-1]-input[0]; //4. 범위

    return 0;
}