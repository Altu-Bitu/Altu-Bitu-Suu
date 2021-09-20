//15903 카드 합체 놀이
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    priority_queue<long long, vector<long long>, greater<>> card; //점수 저장
    cin >> n >> m;
    while(n--){
        int input;
        cin >> input;
        card.push(input);
    }

    while(m--){
        long long a = card.top();
        card.pop();
        long long b = card.top();
        card.pop();
        card.push(a + b);
        card.push(a + b);
    }

    long long score = 0;
    while(!card.empty()){
        score += card.top();
        card.pop();
    }
    cout << score;
    return 0;
}
