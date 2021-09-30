//2529 부등호
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;

vector<int> num;
vector<int> max_num;
vector<int> min_num;
vector<char> input;
vector<bool> visited(10, false);

//재귀함수로 구현한 백트래킹
bool check(int cnt){
    if(input[cnt-1]=='<'){
        if(num[cnt-1]<num[cnt])
            return true;
        return false;
    }else if(input[cnt-1]=='>'){
        if(num[cnt-1]>num[cnt])
            return true;
        return false;
    }
}
void backtrackg(int cnt) { //cnt: 수열의 인덱스
    if (cnt == k+1) { //기저조건, 길이 m 수열 만든 경우
        //max랑 비교
        bool is_max = true;
        for(int i = 0 ; i < k+1 ; i++){
            if(max_num[i] > num[i]){
                is_max = false;
            }else if(max_num[i] == num[i]){
                continue;
            }else{
                break;
            }
        }

        bool is_min = true;
        for(int i = 0 ; i < k+1 ; i++){
            if(min_num[i] < num[i]){
                is_min = false;
            }else if(min_num[i] == num[i]){
                continue;
            }else{
                break;
            }
        }

        if(is_max) copy(num.begin(), num.end(), max_num.begin());
        if(is_min) copy(num.begin(), num.end(), min_num.begin());

        return;
    }
    else if(cnt==0){
        for(int i = 0 ; i <= 9 ; i++){
            visited[i]=true;
            num[0] = i;
            backtrackg(1);
            visited[i]=false;
        }
    }
    else{
        for (int i = 0 ; i <= 9 ; i++) {
            if (!visited[i]) { //현재 수열에 해당 수가 없어야 사용 가능
                num[cnt] = i; //수열에 값 저장
                if(check(cnt)){// 부등호 만족하면 다음단계로
                    visited[i] = true; //수 사용
                    backtrackg(cnt + 1); //다음 수열 인덱스 호출
                    visited[i] = false; //원래 상태로 돌려놓음
                }
            }
        }
    }
}

int main(){
    cin >> k;
    num.assign(k+1, 0);
    min_num.assign(k+1, 9);
    max_num.assign(k+1, 0);
    input.assign(k, ' ');
    for(int i = 0 ; i < k ; i++)
        cin >> input[i];

    backtrackg(0);

    for(int i = 0 ; i < k+1 ; i++){
        cout << max_num[i];
    }
    cout << "\n";
    for(int i = 0 ; i < k+1 ; i++){
        cout << min_num[i];
    }
    return 0;
}