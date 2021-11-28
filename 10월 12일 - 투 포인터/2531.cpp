//샘플 코드 + 주석 제출 (선택 문제)
#include <iostream>
#include <vector>

using namespace std;

/**
 * [투 포인터]
 * 2531 회전 초밥
 * 1. 쿠폰으로 먹은 초밥 초기화
 * 2. 윈도우를 첫번째 초밥부터 k번째 초밥까지로 설정하여 양 끝 윈도우를 left, right 포인터가 가리키게 설정한다.
 *    초밥 가짓수와 먹은 초밥의 개수를 초기화한다.
 * 3. 윈도우를 오른쪽으로 옮겨가면서(left에서 하나 제외하고, right에서 하나 추가) 가짓수를 체크하고 갱신한다.
 */
int chooseSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0); // sushi[초밥 종류] = 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1; //section_sushi: 먹을 수 있는 초밥의 가짓수
    sushi[c]++; // 쿠폰으로 먹은 초밥 개수 증가

    //윈도우 초기화
    for (int i = 0; i < k; i++) { // 1부터 k까지 윈도우를 맨 처음으로 설정
        sushi[belt[i]]++; // 윈도우 안에 들어온 초밥 개수 증가
        if (sushi[belt[i]] == 1)
            section_sushi++; // 초밥 가짓수 증가
    }

    int ans = section_sushi;
    int left = 0, right = k - 1; //left와 right를 맨 처음부터 k번째 초밥까지로 설정. 점점 오른쪽으로 윈도우를 옮김.
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        sushi[belt[left]]--; // left 포인터가 가리키는 초밥을 하나 감소
        if (!sushi[belt[left]]) // 먹은 초밥개수 0으로 바뀌면 초밥 가짓수 감소시켜야함
            section_sushi--;

        //윈도우의 양 끝 이동
        left = (left + 1) % n;
        right = (right + 1) % n;

        sushi[belt[right]]++; // right가 가리키는 초밥을 하나 증가 (구역 크기는 유지)
        if (sushi[belt[right]] == 1) // 새로운 초밥을 먹었으면
            section_sushi++; // 초밥 가짓수 증가

        ans = max(ans, section_sushi); // 최대 초밥 가짓수 갱신.
    } while (left);
    return ans;
}

/**
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 보석 쇼핑 문제처럼 각 종류별 먹은 초밥의 개수를 세어주기
 */
int main() {
    int n, d, k, c; //n: 접시의 수, d: 가짓 수, k:연속해서 먹는 접시의 수, c: 쿠폰 번호

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0);
    for (int i = 0; i < n; i++) // 초밥 벨트
        cin >> belt[i];

    //연산 & 출력
    cout << chooseSushi(belt, n, d, k, c); //주어진 회전 초밥 벨트에서 먹을 수 있는 초밥의 가짓수의 최댓값
}