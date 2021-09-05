//1026 보물
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> A;
vector<int> B;
void printArr(int N) {
    for (int i = 0; i < N; i++)
        cout << A[i] << ' ';
    cout << '\n';
    for (int i = 0; i < N; i++)
        cout << B[i] << ' ';
    cout << '\n';
}
bool compare(int i, int j){
    return j < i;
}
int main(){
    int N;
    int S = 0;
    cin >> N;
    A.assign(N, 0);
    B.assign(N, 0);
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
    for(int i = 0 ; i < N ; i++){
        cin >> B[i];
    }

    sort(A.begin(), A.end(), compare);
    sort(B.begin(), B.end());

    for(int i = 0 ; i < N ; i++){
        S += A[i] * B[i];
    }
    cout << S;
    return 0;
}
