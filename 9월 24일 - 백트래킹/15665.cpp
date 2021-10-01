//15665 N과 M
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int SIZE = 7;

int n, m;
int num[SIZE]; //수열

vector<int> input;

//재귀함수로 구현한 백트래킹
void backtrackg(int cnt) { //cnt: 수열의 인덱스
    if (cnt == m) { //기저조건, 길이 m 수열 만든 경우
        for (int i = 0; i < cnt; i++) //바로 출력
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < input.size(); i++) {
        num[cnt] = input[i]; //수열에 값 저장
        backtrackg(cnt + 1); //다음 수열 인덱스 호출
    }
}

void printArray(){
    for(int i = 0 ; i < input.size() ; i++){
        cout << input[i] << " ";
    }
    cout <<"\n";
}

int main() {
    cin >> n >> m;

    set<int> s;
    while(n--){
        int num;
        cin >> num;
        s.insert(num);
    }
    for(auto iter=s.begin() ; iter!=s.end() ; iter++){
        input.push_back(*iter);
    }

    backtrackg(0);

    return 0;
}
