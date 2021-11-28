//샘플 코드 + 주석 제출 (선택 문제)
#include <iostream>
#include <vector>

using namespace std;
/**
 * [투 포인터]
 * 13422 도둑
 * 1. 윈도우를 첫번재집 ~ m번째 집부터 시작해 한바퀴 돌때까지 이동.
 * 2. left, right를 윈도우 양끝으로 설정.
 * 3. 훔칠 수 있으면 (구간 내 돈의 합이 k를 넘지 않음) 가짓수 증가
 * *** n개의 집이 주어졌는데 윈도우 크기가 n으로 주어진 경우는 따로 처리함.
 */

int steal(vector<int> &house, int n, int m, int k) {
    //윈도우 초기화
    int money = 0;
    for (int i = 0; i < m; i++) // 윈도우 : 첫번째 집 ~ m번째 집. 점점 오른쪽으로 이동.
        money += house[i];

    if (n == m) //훔칠 수 있는 경우 딱 1개인 경우 (n개의 집 중 n개의 집을 훔치는 가짓수는 하나)
        return money < k;

    int ans = 0;
    int left = 0, right = m - 1; // left, right 포인터를 윈도우 양끝으로 설정
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        if (money < k) //훔칠 수 있음 (방범장치가 작동X)
            ans++;//가짓수 추가

        money -= house[left]; //left 포인터가 가리키는 집 제외 (옆으로 이동)

        //윈도우의 양 끝 이동 (원형이라)
        left = (left + 1) % n;
        right = (right + 1) % n;

        money += house[right]; // right 포인터가 가리키는 집 추가 (옆으로 이동)
    } while (left);
    return ans;
}

/**
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 */

int main() {
    int t, n, m, k;

    cin >> t;
    while (t--) {
        //입력
        cin >> n >> m >> k; // n: 집의 개수, m: 훔칠 연속된 집의 개수(window 간격), k: 자동 방범 장치가 작동하는 최소 돈의 양
        vector<int> house(n, 0); // 집에서 보관중인 돈의 양
        for (int i = 0; i < n; i++)
            cin >> house[i];

        //연산 & 출력
        cout << steal(house, n, m, k) << '\n'; //연속된 m개의 집에서 돈을 훔치는 가짓수
    }
}