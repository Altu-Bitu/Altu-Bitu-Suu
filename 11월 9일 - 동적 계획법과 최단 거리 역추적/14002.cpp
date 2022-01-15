#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

/**
 * 백준 14002 : 가장 긴 증가하는 부분 수열 4
 * 1. arr를 돌면서 현재 원소의 앞부분까지 증가하는 부분을 체크한다.
 * 2. 증가관계(앞 원소가 현재 원소보다 값이 작고)이고, 앞 원소들 중 가장 큰 원소라면
 * 수열의 순서를 저장해주는 배열인 dp를 갱신해주고 그 경로 index를 path 배열에 저장해준다.
 * 3. dp 최댓값부터 path를 역추적한다. 수열을 역으로 따라가면서 정답 배열은 만든다.
 *
 * dp 배열은 값의 증가 순서가 담기지만 경로가 담기지 않는다. path에 경로를 저장해줘야한다.
 * */
vector<int> back(int x, vector<int> &path) { // 역추적
    vector<int> result(0); //Lis의 마지막 원소 인덱스부터 들어감
    while (x != -1) { //-1이 수열의 제일 처음.
        result.push_back(x);
        x = path[x]; //다음 경로
    }
    return result;
}

//시간 복잡도 O(n^2) Lis
ci lis(int n, vector<int> &arr, vector<int> &path) {
    vector<int> dp(n, 1); // LIS의 순서가 저장됨 (10: 1, 20: 2, 30: 3, 50: 4)
    ci ans = {1, 0}; //최장 길이, 마지막 원소 인덱스

    for (int i = 1; i < n; i++) { //arr 전체를 돈다.
        int index = -1; //경로 저장할 변수. index가 0부터 시작되기 때문에, 수열이 dp[0] 에서 이어지지 않을 경우를 위해 path[0] = -1부터 시작되어야함
        for (int j = 0; j < i; j++) { // 현재 위치한 arr 원소 앞을 전부 검사.
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { //증가하는 관계, && 가장 큰 dp[j] + 1.
                // dp[i] < dp[j] + 1 : 현재 원소랑 비교했을 때 증가하는 관계여도, 그 앞에서 증가->감소->증가 양상이면 갱신 안되게 pass 시켜줌. (dp[i]가 제일 큰 값이 아니므로.)
                dp[i] = dp[j] + 1;
                index = j;
            }
        }
        path[i] = index;
        if (ans.first < dp[i]) //최장 길이 + 마지막 원소 인덱스 갱신
            ans = {dp[i], i};
    }
    return ans;
}

/**
 * 동적계획법 역추적
 * - 기본 문제: 가장 긴 증가하는 부분 수열
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n); //수열
    vector<int> path(n, -1); //경로 저장 배열
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    ci ans = lis(n, arr, path); //first: 최장 길이, second: 최장 길이의 마지막 원소 인덱스
    vector<int> result = back(ans.second, path); //역추적

    //출력
    cout << ans.first << '\n'; // lis 길이
    for (int i = result.size() - 1; i >= 0; i--)
        cout << arr[result[i]] << ' ';
    return 0;
}