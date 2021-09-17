//2493 탑
#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    map<int, int> tower; // 타워 높이, 인덱스
    stack<int> larger;

    for(int i = 0 ; i < N ; i ++){
        int height;
        cin >> height;
        tower[height] = i + 1;
        //스택이 비어있음
        if(larger.empty()){
            cout << 0 << " ";
            larger.push(height);
        }else{
        //스택에 뭐가 들어있음
            if(larger.top() < height){ // 스택 맨 위보다 입력값이 큼
                while(!larger.empty() && larger.top() < height){ // 스택에서 입력값보다 큰 값만 남을때까지 다 뺌
                    larger.pop();
                }
                //다 뺐더니 비었음
                if(larger.empty()) cout << 0 << " ";
                else{//다 빼니까 뭐가 남아있음
                    cout << tower[larger.top()] << " ";
                }
                larger.push(height);
            }else{ // 스택 맨 위보다 입력값이 작음
                cout << tower[larger.top()] << " ";
                larger.push(height);
            }
        }

    }
    return 0;
}