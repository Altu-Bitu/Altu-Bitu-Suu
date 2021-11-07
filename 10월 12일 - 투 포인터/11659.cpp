//샘플코드 + 주석제출
#include <iostream>
#include <vector>

using namespace std;
/** [투 포인터]
 * 11659 구간 합 구하기 4
 * 1. 수 N개를 입력으로 받을 때, 누적합으로 바로 계산해서 저장한다.
 * 2. (i부터 j번째 합)은 (j번 까지의 누적합 - (i-1)까지의 누적합)과 같다.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num;

    //입력
    cin >> n >> m; // n: 수의 개수, m: 합을 구해야 하는 횟수
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) { //인덱스를 1부터 시작하면 i=0인 경우를 따로 처리할 필요 없음
        cin >> num;
        sum[i] = sum[i - 1] + num; //첫번째 수부터 i번째 수까지의 누적합
    }

    while (m--) {
        int s, e;
        cin >> s >> e; //합을 구해야 하는 구간 i=s와 j=e

        //출력
        cout << sum[e] - sum[s - 1] << '\n'; //(i부터 j번째 합)은 (j번 까지의 누적합 - (i-1)까지의 누적합)과 같다.
    }
}