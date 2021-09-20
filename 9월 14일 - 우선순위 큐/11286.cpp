//11286 절댓값 힙
#include <iostream>
#include <queue>

using namespace std;

class cmp{
public:
    int operator()(const int &i1, const int &i2){
        if(abs(i1)!=abs(i2))
            return abs(i1) > abs(i2);
        return i1 > i2;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, cmp> pq;

    while(N--){
        int x;
        cin >> x;
        if(x==0){ // 절댓값이 가장 작은 값 출력, 그 값 제거
            if(pq.empty()){
                cout << 0 << "\n";
            }else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }else{ // 배열에 추가
            pq.push(x);
        }
    }

    return 0;
}