//11723 집합
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> S;
    int N;
    cin >> N;
    while(N--){
        string cal;
        cin >> cal;
        int x;
        if(cal!="all"&&cal!="empty") cin >> x;
        if(cal=="add"){
            S.insert(x);
        }else if(cal=="remove"){
            S.erase(x);
        }else if(cal=="check"){
            if(S.find(x)!=S.end()){
                cout << 1 << "\n";
            }else cout << 0 << "\n";
        }else if(cal=="toggle"){
            if(S.find(x)!=S.end()){
                S.erase(x);
            }else S.insert(x);
        }else if(cal=="all"){
            S={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        }else if(cal=="empty"){
            S={};
        }
    }

    return 0;
}