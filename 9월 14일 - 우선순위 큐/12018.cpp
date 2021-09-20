//12018 Yonsei TOTO
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> min_m;
    min_m.assign(n, 0);
    for(int j = 0 ; j < n ; j++){
        int p, l;
        cin >> p >> l;
        priority_queue<int, vector<int>> pq; //최대 힙
        while(p--){
            int a;
            cin >> a;
            pq.push(a);
        }
        l--;
        while(l--){
            if(pq.empty()){ //인원 수 미달
                pq.push(1);
                break;
            }
            pq.pop();
        }
        min_m[j]=pq.top(); //해당과목에 들어갈 수 있는 최소 마일리지
    }

    sort(min_m.begin(), min_m.end()); //마일리지 적게 드는 순으로 정렬

    int count = 0;
    int j = 0;
    while(1){
        m-=min_m[j];
        if(m<0) break; //마일리지를 다 썼다면
        count++;
        if(count==n) break; //갖고있는 마일리지가 많아서 전과목을 들을 수 있다면
        j++;
    }
    cout << count;

    return 0;
}