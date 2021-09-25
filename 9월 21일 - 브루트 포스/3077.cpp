//3077 임진왜란
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<string, int>> answer(N, {"", 0}); // <해전 이름, 확인한 input 체크>
    vector<string> input(N, "");

    for (int i = 0 ; i < N ; i++){
        string hg;
        cin >> hg;
        answer[i] = {hg, 0};
    }
    int a = 0;

    // 틀린 개수를 세고 총합에서 뺀다.
    // input을 받는 즉시, 정답 배열에서 input이 나올 때까지 input 앞에 있는 해전 개수를 센다. (= 틀린 개수)
    // 해전 개수를 셀 때, 이전에 입력받았던 해전이 정답 배열에서 input 앞에 나온다면 순서가 맞는 것이므로 개수를 세면 안된다. 이는 정답배열에서 1(이미 체크한 input), 0(체크X input)으로 구분한다.
    for (int i = 0 ; i < N ; i++){
        cin >> input[i];
        int temp = 0;
        for (int j = 0 ; j < N ; j++){
            if(answer[j].first==input[i]){
                answer[j].second = 1;
                break;
            }
            if(answer[j].second==1) continue;
            temp++;
        }
        a += temp;
    }

    int b = N*(N-1)/2;
    cout << b-a << "/" << b;
    return 0;
}
