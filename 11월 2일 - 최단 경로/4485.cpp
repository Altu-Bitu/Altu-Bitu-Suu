//샘플 코드 + 주석 제출 (선택 문제)
#include <iostream>
#include <queue>
#include <vector>

/**
 * [최단 경로]
 * 4485 녹색 옷을 입은 애가 젤다지?
 * 루피를 최소한으로 잃는 경로로 동굴을 탈출하는 문제.
 * 전체 동굴(NXN)의 시작점(0, 0)부터 시작하여 맨 끝점(n-1, n-1)에 도달할때까지 큐를 사용해서 weight 갱신을 반복한다.
 * 1. 현재 위치의 좌표와 현재까지의 weight를 큐에서 꺼낸다.
 * 2. 끝점에 도달했다면 루프를 종료하고 정답을 반환. 이미 확인했던 좌표라면 다음 좌표로 넘어간다.
 * 3. 꺼낸 좌표에서 상하좌우 좌표를 검사한다. 상하좌우 좌표가 범위 안이라면, 그 좌표까지의 weight와 dist 벡터(그 좌표 위치까지의 최소 weight를 기록하는 벡터.)에 기록해 둔 weight를 비교한다.
 *    더 최소한의 weight로 갈 수 있는 경로라면 dist 벡터의 값을 갱신하고, 위치를 큐에 넣는다.
 */

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 2; //최대 N*N 칸을 지나게 됨

int dijkstra(int n, vector<vector<int>> &board) {
    //상하좌우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int ans = 0;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<>> pq;

    //시작 위치 초기화
    dist[0][0] = board[0][0];
    pq.push(make_pair(dist[0][0], make_pair(0, 0))); // 동굴 첫칸에서 시작

    while (!pq.empty()) {
        int weight = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (row == n - 1 && col == n - 1) { //제일 오른쪽 아래 칸 도착
            ans = weight; // 잃게되는 최소 금액
            break;
        }

        if(weight > dist[row][col]) //이미 확인했던 좌표
            continue;

        for (int i = 0; i < 4; i++) { // 상하좌우 반복
            int nr = row + dr[i];
            int nc = col + dc[i];

            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) //범위를 벗어난다면
                continue;

            int next_weight = weight + board[nr][nc]; //시작점으로부터 연결된 좌표까지의 거리
            if (dist[nr][nc] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[nr][nc] = next_weight; // dist의 weight 갱신
                pq.push({next_weight, {nr, nc}}); // 다음 좌표와 그 좌표까지의 weight를 함께 넣어줌
            }
        }
    }
    return ans;
}

/**
 * 상하좌우로 이동 가능 -> 연결됐다는 것
 * 시작 지점이 (0, 0)인 다익스트라
 */
int main() {
    int n, num = 1;

    while (true) {
        //입력
        cin >> n;
        if (n == 0)
            break;

        vector<vector<int>> board(n, vector<int>(n, 0)); // 동굴 전체
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        }

        //연산 & 출력
        cout << "Problem " << num++ << ": " << dijkstra(n, board) << '\n';
    }
}