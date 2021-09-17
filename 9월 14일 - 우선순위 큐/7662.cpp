// 7662 이중 우선순위 큐
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int k;
        cin >> k;
        set<long long> S;
        map<long long, int> m; // 값, 개수

        while(k--){
            char DT;
            long long n;
            cin >> DT;
            cin >> n;
            if(DT=='I'){
                S.insert(n);
                m[n]++;
            }else{ //DT='D'
                if(S.empty())//컨테이너가 비었으면 연산 무시
                    continue;
                if(n == -1){ //최솟값 삭제 연산
                    long long min = *S.begin();
                    if(m[min]>1){ // 최솟값이 여러개 있으면 그냥 하나 줄이고 끝
                        m[min]--;
                    }else{// 최솟값이 하나 있으면 삭제
                        S.erase(min);
                        m[min]--;
                    }
                }else{ // n==1
                    long long max = *(--S.end());
                    if(m[max]>1){ // 최댓값이 여러개 있으면 그냥 하나 줄이고 끝
                        m[max]--;
                    }else{// 최댓값이 하나 있으면 삭제
                        S.erase(max);
                        m[max]--;
                    }
                }
            }
        }
        //남아있는 값 중 최댓값 최솟값 출력
        if(S.empty()){
            cout << "EMPTY" <<"\n";
        }else{
            cout << *(--S.end()) << " " << *S.begin() << "\n";
        }
    }


    return 0;
}