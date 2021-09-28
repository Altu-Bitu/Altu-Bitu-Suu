//10448 유레카 이론
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    //삼각수 배열 만들기
    vector<int> T(1001, 0);
    T[1] = 1;
    int j = 2;
    for(int i = 2 ; i < 1001 ; i++){
        T[i]= T[i-1] + j;
        j++;
    }

    //3개 삼각수 합으로 표현할 수 있는지 체크
    while(t--){
        int n;
        bool check = false;
        cin >> n;
        for(int k = 1; T[k] < n ; k++){
            for(int m = 1; T[m] < n-T[k] ; m++) {
                for (int p = 1; T[p] <= n-T[k]-T[m]; p++) {
                    if(T[k]+T[m]+T[p]==n) check = true;
                }
            }
        }
        if(check) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}