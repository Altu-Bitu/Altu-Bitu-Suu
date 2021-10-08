//1448 삼각형 만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> tri(N, 0);
    for(int i = 0 ; i < N ; i++){
        cin >> tri[i];
    }

    sort(tri.begin(), tri.end(), greater<>());
    int max_sum = -1;
    for(int i = 0 ; i < N-2 ; i++){
        int a = tri[i];
        int b = tri[i+1];
        int c = tri[i+2];
        if(a < b + c){
            max_sum = max(a+b+c, max_sum);
        }
    }
    cout << max_sum;
    return 0;
}
