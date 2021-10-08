//16206 롤케이크
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(const int &i1, const int &i2) { // 10으로 나누어 떨어지는거 먼저, 작은 숫자 먼저 나오게
    if(i1 % 10 == 0 && i2 % 10 != 0)
        return true;
    else if (i1 % 10 != 0 && i2 % 10 == 0){
        return false;
    }
    else {
        return i1 < i2;
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0);
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end(), compare);
    int count = 0;
    for(int i = 0; i < N ; i++){
        if(A[i] > 10){
            while(A[i] > 10){
                A[i] -= 10;
                M--;
                count++;
                if(A[i]==10) count++;
                if(M==0) break;
            }
        }else if(A[i]==10) count++;

        if(M==0) break;
    }
    cout << count;
    return 0;
}