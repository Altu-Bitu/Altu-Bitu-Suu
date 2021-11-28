//샘플 코드 + 주석 제출 (선택 문제)
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100000;

/**
 * [투 포인터]
 * 20922 겹치는건 싫어
 * 1. left와 right가 수열 맨 처음부터 시작해서 오른쪽으로 움직임.
 * 2. right가 가리키는 원소를 포함해도 등장횟수가 k 이하이면, 먼저 답으로 리턴할 수열의 최장 길이를 갱신한 다음, 수열의 범위를 넓히기 위해 right 포인터를 움직인다.
 * 2-1. right가 가리키는 원소를 포함했을 때 등장횟수가 k를 초과하면, 수열의 범위를 좁히기 위해 left 포인터를 움직인다.
 *
 */
int findLen(vector<int> &arr, int n, int k) {
    vector<int> cnt(MAX + 1, 0); //각 원소 등장 횟수

    int ans = 0, left = 0, right = 0; // left랑 right가 같은 위치에서 시작해서 오른쪽으로 움직임.

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    //right는 항상 n보다 작아야함
    while (left <= right && right < n) {
        if (cnt[arr[right]] + 1 <= k) { //현재 right가 가리키는 원소를 포함해도 등장 횟수가 k번 이하
            cnt[arr[right]]++; // right가 가리키는 원소 등장횟수 증가시킴
            ans = max(ans, (right - left) + 1); // 수열의 길이 최장 길이로 갱신
            right++; // 등장횟수 k번 이하니까 수열 길이를 늘리기 위해 right를 넓힘. (먼저 포인터를 옮김)
        } else { //현재 right가 가리키는 원소를 포함하면 등장 횟수가 k번을 초과
            cnt[arr[left]]--; // left가 가리키는 원소 등장 횟수 감소
            left++; // left를 좁힌다.
        }
    }
    return ans;
}

/**
 * 1. 최장 연속 부분 수열의 '길이'를 구해야 함 -> 구간 내의 모든 원소를 고려하기 때문에 한쪽에서 시작하는 투 포인터
 * 2. 각 원소의 최댓값이 100,000이기 때문에 배열로 등장 횟수 체크할 수 있음
 * 3. right를 옮기고 바로 원소를 추가했던 기존 방법과 달리, 일단 포인터만 옮겨놓고 원소를 추가해도 되는지 확인
 */
int main() {
    int n, k;

    //입력
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) // 수열
        cin >> arr[i];

    //연산 & 출력
    cout << findLen(arr, n, k); // 같은 정수를 k개 이하로 포함한 최장 연속 부분 수열의 길이
}