//샘플코드 + 주석 제출
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings;
vector<int> order(10, 0); //타순
vector<bool> check(10, false);
int n, ans;

/**
 * [분할 정복]
 * 17281 야구
 * 1. 4번 타석을 1번 선수로 고정시킨다음 나머지 8명의 타순을 정한다. 백트래킹을 통해 모든 경우의 수를 돌림.
 * 2. 타순이 전부 정해졌으면 점수를 계산한다. 백트래킹으로 여러 경우의 수가 있으므로 최댓값만 남김.
 * 3. 각 이닝마다 3아웃이 될때까지 타순이 돌아감. 1번 타자부터 시작함.
 * 4. 타자의 결과 4가지(0: 아웃. 다음 타자로 넘어감. | 1: 안타. 전부 1루 진루하며 만약 3루에 사람이 있다면 스코어가 올라감.
 *                   2: 2루타. 2루씩 진루하여 스코어를 올리며 1루엔 사람이 없게 됨. 3: 3루타. 3루씩 진루하여 스코어를 올리며 3루빼고 전부 비게됨.
 *                   4: 홈런. 베이스에 있던 사람 수 + 1만큼 스코어가 올라감.)
 * 5. 모든 이닝이 종료되었으면 스코어 리턴. 백트래킹으로 보내진 모든 타순에 대한 경우의 수 증 최대 스코어만이 남게 된다.
 */

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) { //3아웃 될때까지
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10) // 타석을 다 돌았으면 다시 1번 타자부터
                idx = 1;
            switch (state) { //타자 결과
                case 0: //아웃
                    out++;
                    break;
                case 1: //안타, 1루씩 진루
                    score += baseman[3]; //3루에 있는 선수있다면 홈 도착
                    for (int i = 3; i > 0; i--) //나머지도 각각 1루씩 진루
                        baseman[i] = baseman[i - 1];
                    baseman[1] = 1; //새로운 선수 1루에 도착
                    break;
                case 2: //2루타, 2루씩 진루
                    score += baseman[3] + baseman[2]; //3루, 2루에 선수 있다면 홈 도착
                    baseman[3] = baseman[1]; //1루 -> 3루 이동
                    baseman[2] = 1; //새로운 선수 2루에 도착
                    baseman[1] = 0; //초기화 (1루에 있던 선수는 3루로 갔고 새로운 선수는 2루로 갈테니 1루는 비게 됨)
                    break;
                case 3: //3루타, 3루씩 진루
                    for (int i = 3; i > 0; i--) { //3루, 2루, 1루에 선수 있다면 홈 도착
                        score += baseman[i];
                        baseman[i] = 0; // 베이스 비워줌
                    }
                    baseman[3] = 1; //새로운 선수 3루에 도착
                    break;
                case 4: //홈런
                    for (int i = 3; i > 0; i--) { //3루, 2루, 1루에 선수 있다면 홈 도착
                        score += baseman[i];
                        baseman[i] = 0; // 모든 베이스가 비게 됨
                    }
                    score++; //새로운 선수도 홈 바로 도착
                    break;
            }
        }
    }

    return score;
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1);
        return;
    }
    if (cnt == 10) { //9번 타자까지 순서 다 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score); // 최댓값을 남김
        return;
    }
    // cnt = 1부터 들어옴
    for (int i = 2; i <= 9; i++) { //4번 타자로 고정된 1번 선수 빼고 나머지 선수드르이 순서를 정한다
        if (!check[i]) { //i번 선수의 순서가 정해지지 않았다면
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자
            check[i] = false; //백트래킹을 위해.. 8명 다 순서 정해져야하니깐
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    //입력
    cin >> n;
    innings.assign(n, vector<int>(10, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> innings[i][j];
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    array(1);

    //출력
    cout << ans << '\n';

    return 0;
}