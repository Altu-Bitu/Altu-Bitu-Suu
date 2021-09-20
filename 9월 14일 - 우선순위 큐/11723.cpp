//11723 집합
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> S;
    S.assign(21, 0);
    int N;
    cin >> N;
    while(N--){
        string cal;
        cin >> cal;
        int x;
        if(cal!="all"&&cal!="empty") cin >> x;
        if(cal=="add"){
            S[x]++;
        }else if(cal=="remove"){
            S[x]--;
        }else if(cal=="check"){
            if(S[x]>0){
                cout << 1 << "\n";
            }else cout << 0 << "\n";
        }else if(cal=="toggle"){
            if(S[x]>0){
                S[x]--;
            }else S[x]++;
        }else if(cal=="all"){
            for(int i = 1 ; i < 21 ; i++){
                S[i]=1;
            }
        }else if(cal=="empty"){
            for(int i = 1 ; i < 21 ; i++){
                S[i]=0;
            }
        }
    }

    return 0;
}