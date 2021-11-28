//샘플코드 + 주석제출
//메모리 초과 문제를 해결하지 못해서 샘플코드에 주석 제출. 나중에 스스로 해결해본다..

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [DFS & BFS]
 * 19538 루머
 * 1. 최초 유포자들의 시간을 0으로 하여 큐에 넣음
 * 2. 큐에서 유포자를 한명 꺼냄
 * 3. 유포자의 주변인들을 탐색하며 만약 방문하지 않은 유포자라면 시간을 갱신하고 큐에 넣음
 * 4. 2~3을 반복
 * 5. 큐가 비었을 때 시간 출력
 */

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {
    vector<int> believer(n + 1, 0); //주변인들이 몇 명 믿는지
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q;

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0; //최초 유포자 시간 0
        q.push(init[i]); //최초 유포자들을 큐에 넣음
    }

    while (!q.empty()) { //더이상 유포자가 없을 때까지
        int v = q.front(); //현재 사람
        int t = ans[v]; //루머 믿은 시간
        q.pop(); // 큐에서 루머 유포자 한명(v) 꺼냄

        for (int i = 0; i < people[v].size(); i++) { // 꺼낸 사람(v)의 주변인 전부 탐색
            int next = people[v][i]; //next는 v의 주변인
            believer[next]++; //next의 주변에서 루머를 믿는 사람 증가(v를 꺼냈으니까)
            if (ans[next] != -1) //next가 이미 루머를 믿는 다면 : 방문체크
                continue; //다음 유포자로 넘어감
            if ((people[next].size() + 1) / 2 <= believer[next]) { //next의 주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1; //next의 루머 믿은 시간 갱신
                q.push(next); //next도 루머 유포자가 되어 큐에 들어감
            }
        }
    }
    return ans;
}

/**
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크를 탐색할 때 바로 하는 게 아니라, 루머를 믿게 될 경우 하는 게 중요 (루머를 몇 분 후에 믿는지를 저장하는 배열로 관리)
 */

int main() {
    int n, m, input;

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    vector<vector<int>> people(n + 1, vector<int>()); // 주변인인지 저장하는 벡터
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> input;
            if (!input) // 0이 들어오면 입력 멈춤
                break;
            people[i].push_back(input); // i번째 사람의 주변인 추가
        }
    }

    //최초 유포자 입력
    cin >> m;
    vector<int> init(m, 0);
    for (int i = 0; i < m; i++)
        cin >> init[i];

    //연산
    vector<int> ans = bfs(people, init, n);

    //출력
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}
