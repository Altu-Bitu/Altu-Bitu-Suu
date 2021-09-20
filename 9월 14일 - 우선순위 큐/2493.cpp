//2493 탑
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> tower;
    tower.assign(N, 0);
    stack<int> larger;

    for(int i = 0 ; i < N ; i ++){
        int height;
        cin >> height;
        tower[i] = height;
        //스택이 비어있음
        if(larger.empty()){
            cout << 0 << " ";
            larger.push(i);
        }else{
            //스택에 뭐가 들어있음
            while(!larger.empty() && tower[larger.top()] < height){ // 스택에서 입력값보다 큰 값만 남을때까지 다 뺌
                larger.pop();
            }
            //다 뺐더니 비었음
            if(larger.empty()) cout << 0 << " ";
            else{//다 빼니까 뭐가 남아있음
                cout << larger.top() + 1 << " ";
            }
            larger.push(i);
        }
    }
    return 0;
}