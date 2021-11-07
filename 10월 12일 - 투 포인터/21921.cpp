//샘플 코드 + 주석 제출 (라이브 코딩)
#include <iostream>
#include <vector>

using namespace std;
/**
 * [투 포인터]
 * 21921 블로그
 * 1. 1일부터 X일 까지의 방문자 수로 최대 방문자 수를 초기화한다. 또한, 1로 기간의 수를 초기화한다.
 * 2. 슬라이딩 윈도우를 한칸씩 오른쪽으로 이동해가며 최대 방문자 수를 갱신한다. 최대 방문자 수가 같다면 기간의 수를 늘리고, 갱신된다면 1로 초기화한다.
 * 3. 끝까지 이동했으면 답 출력.
 */

//슬라이딩 윈도우로 최대 방문자 수를 구하고, 그 기간의 수를 리턴
pair<int, int> maxVisitor(int n, int x, vector<int> &visitor) {
    //윈도우 초기화
    int section_visitor = 0;
    for (int i = 0; i < x; i++) //첫날부터 x일 동안의 방문자 수
        section_visitor += visitor[i]; //1일 ~ x일

    int ans = section_visitor; //답으로 리턴할 최대 방문자 수. 1일 ~ x일 동안의 방문자 수로 초기화.
    int cnt = 1; //최대 방문자 수인 기간의 수. 1로 초기화

    //오른쪽으로 슬라이딩 윈도우 한칸씩 이동
    for (int i = x; i < n; i++) {
        section_visitor -= visitor[i - x]; //이번 윈도우에 제외되는 값 : 1일~ n-x일
        section_visitor += visitor[i]; //이번 윈도우에 추가되는 값 : x+1일 ~ n일
        if (section_visitor > ans) { //슬라이딩 했더니 최대 방문자 수가 기존보다 더 크면 갱신
            cnt = 1; //갱신했을 때, 기간의 수는 다시 1로 초기화
            ans = section_visitor;
        } else if (section_visitor == ans) //최대 방문자 수가 기존과 같다면 기간의 수를 늘림.
            cnt++;
    }
    return make_pair(ans, cnt);
}

int main() {
    int n, x;

    //입력
    cin >> n >> x; //n: 블로그를 시작하고 지난 일수, x: x일 동안의 구간을 잡아야함
    vector<int> visitor(n, 0); //방문자 배열
    for (int i = 0; i < n; i++)
        cin >> visitor[i];

    //연산
    pair<int, int> ans = maxVisitor(n, x, visitor);

    //출력
    if (ans.first == 0) { //최대 방문자 수가 0명이라면 SAD 출력하고 끝.
        cout << "SAD\n";
        return 0;
    }
    cout << ans.first << '\n' << ans.second; // 최대 방문자 수가 0이 아닌 경우 최대 방문자 수(ans.first)랑 최대 방문자 수를 갖는 기간(ans.second)이 몇개 있는지 출력한다.
}