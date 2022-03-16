//1713 후보 추천하기
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<int, pair<int, int>> num; // 번호, {추천받은 순서, 추천수}

struct cmp{
    bool operator()(int p1, int p2){
        if(num[p1].second!=num[p2].second)
            return num[p1].second > num[p2].second;
        return num[p1].first > num[p2].first;
    }
};
int main() {
    int n, total;
    priority_queue<int, vector<int>, cmp> pq;

    cin >> n >> total;
    vector<int> recommended(total, 0);
    vector<int> candidate;

    for(int i = 0 ; i < total ; i++){
        cin >> recommended[i];
        if(num[recommended[i]].second == 0){ // 처음 추천
            num[recommended[i]] = {i, 1};

            if(pq.size()==n){
                int temp = pq.top();
                pq.pop();
                num[temp] = {0, 0};
            }
            pq.push(recommended[i]);

        } else {
            num[recommended[i]].second++;

            //전체 다시 정렬
            vector<int> temp;
            while(!pq.empty()){
                temp.push_back(pq.top());
                pq.pop();
            }
            for(int j = 0 ; j < temp.size() ; j++){
                pq.push(temp[j]);
            }
        }
    }

    while(!pq.empty()){
        candidate.push_back(pq.top());
        pq.pop();
    }
    sort(candidate.begin(), candidate.end());

    for(int i = 0 ; i < candidate.size() ; i++)
        cout << candidate[i] << " ";
    return 0;
}
