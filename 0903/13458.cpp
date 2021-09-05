//13458 시험 감독
#include <iostream>
#include <vector>

using namespace std;
vector<long> A;

int main(){
    long N, B, C;
    cin >> N;
    long count = N;
    A.assign(N, 0);
    for( int i = 0 ; i < N ; i++){
        cin >> A[i]; //응시자 수
    }
    cin >> B >> C;

    for( int i = 0 ; i < N ; i++){
        int temp;
        temp = A[i] - B;
        if ( temp <= 0)
            continue;
        count += (temp / C);
        if((temp % C)!=0){
            count++;
        }
    }
    cout << count;
}