//11000 강의실 배정
#include <iostream>
#include <queue>

using namespace std;

struct cl {
    int S; //시작 시간
    int T; //끝나는 시간
};
class cmp{
public:
    int operator()(const cl &i1, const cl &i2){
        if(i1.S != i2.S) //시작시간이 다르면 빠른 순대로
            return i1.S > i2.S;
        else{ //시작 시간이 같으면 끝나는 시간이 빠른 대로
            return i1.T > i2.T;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<cl, vector<cl>, cmp> pq;
    priority_queue<int, vector<int>, greater<>> answer; // 끝나는 시간들을 넣고, 강의가 이어질수 있으면 바꿔치기
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cl input;
        cin >> input.S >> input.T;
        pq.push(input);
    }

    answer.push(pq.top().T);
    pq.pop(); //젤 앞에 있는거 먼저 넣어줌

    while(!pq.empty()){
        cl a = pq.top();
        pq.pop(); // 하나 꺼냄
        if(answer.top() > a.S){
            answer.push(a.T);
        }else{
            answer.pop();
            answer.push(a.T);
        }
    }
    cout << answer.size();

    return 0;
}