//샘플 코드 + 주석 제출 (라이브 코딩)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * [투 포인터]
 * 2470 두 용액
 * 1. 용액의 특성값들을 배열에 저장하여 오름차순으로 정렬한다. left쪽에는 알칼리성 용액이, right 쪽에는 산성 용액이 있게 된다.
 * 2. 양 끝단부터 시작해 두 포인터를 점점 좁힌다. 좁히면서 최소차이값(min_diff)를 갱신하고(절댓값으로 넣어야한다.), 그 값을 만드는 두 용액의 특성값을 정답으로 리턴할 pair에 저장한다.
 *    혼합한 값이 0보다 크다면 산성용액이 큰 것이므로 right를 좁히고, 혼합한 값이 0보다 작다면 알칼리성 용액이 작은 것이므로 left를 좁힌다.
 *
 */
//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<int, int> liquid(vector<int> &arr, int left, int right) { // arr: 용액의 특성값을 정렬한 배열, left: 배열 시작점, right: 배열 끝점
    pair<int, int> ans;
    int min_diff = 2 * 1e9 + 1; //최소 차이값. 우선 가장 큰값으로 초기화.

    //left는 항상 right의 왼쪽에 있어야 함
    while (left < right) {
        int mix = arr[left] + arr[right]; //두 용액을 혼합 (정렬했기 때문에 left 쪽에는 알칼리성 용액이, right 쪽에는 산성 용액이 있을 것임)
        if (mix == 0) //혼합한 값이 0이라면 이보다 더 0에 가까워질 수 없기 때문에 바로 리턴
            return make_pair(arr[left], arr[right]);
        if (abs(mix) < min_diff) { //0에 가까운 값을 갱신할 수 있는지 확인
            min_diff = abs(mix); // 최소 차이값 갱신
            ans = make_pair(arr[left], arr[right]); //최소 차이값을 만드는 두 용액의 특성값 저장.
        }
        if (mix > 0) //0보다 크면 더 작은 값을 만들어야 함. 산성 용액쪽 값을 줄여야하므로 right를 감소
            right--;
        else if (mix < 0) //0보다 작으면 더 큰 값을 만들어야 함. 알칼리성 용액쪽 값을 키워야하므로 left를 증가.
            left++;
    }
    return ans;
}

int main() {
    int n;

    //입력
    cin >> n; // 전체 용액의 수
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i]; //용액의 특성 값 (양의 정수면 산성 용액, 음의 정수면 알칼리성 용액)

    //연산
    sort(arr.begin(), arr.end()); // 오름차순 정렬
    pair<int, int> ans = liquid(arr, 0, n - 1); //특성값을 가장 0에 가깝게 만드는 두 용액의 특성값을 저장

    //출력
    cout << ans.first << ' ' << ans.second;
}