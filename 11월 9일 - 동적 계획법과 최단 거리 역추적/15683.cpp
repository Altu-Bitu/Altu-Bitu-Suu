//주석 제출
#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 65;
vector<vector<int>> board;

/**
 * 15683 감시
 * 각 경우의 수에 따른 최솟값을 구해야하기때문에 백트래킹.
 *  1. 전체 칸을 한칸씩 이동하며 백트래킹을 수행한다.
 *  2. 백트래킹 수행 전 ray가 뻗어나갈 수 있는 모든 경우의 수에 맞게 cctv를 설치한다.
 *  3. 백트래킹을 보내고 보드 상태 복구
 *  4. 마지막 칸에 도달하면 최솟값 갱신 후 재귀를 끝냄.
 */

//cctv 범위 표시
void ray(int row, int col, int dir) {
    int dr[4] = {-1, 0, 1, 0}; //상, 하, 좌, 우
    int dc[4] = {0, 1, 0, -1};

    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //dir 방향으로 뻗어나가며 cctv 표시
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시
            board[row][col] = 7;
        row += dr[dir];
        col += dc[dir];
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir) { // cctv 설치, dir==동서남북 사방, 0(상), 1(하), 2(좌), 3(우)
    if (cctv >= 1) //1, 2, 3, 4, 5번 cctv
        ray(row, col, dir); // dir: 0, 1, 2, 3
    if (cctv >= 2 && cctv != 3) //2, 4, 5번 cctv
        ray(row, col, (dir + 2) % 4); // dir: 2, 3, 0, 1
    if (cctv >= 3) //3, 4, 5번 cctv
        ray(row, col, (dir + 1) % 4); // dir: 1, 2, 3, 0
    if (cctv == 5) //5번 cctv
        ray(row, col, (dir + 3) % 4); // dir: 3, 0, 1, 2
}
/**
 * dir 전달
 * 1. CCTV1
 * dir 0 -> 1 -> 2 -> 3
 *
 * 2. CCTV2
 * dir 0 2 -> 1 3 -> 2 0 -> 3 1
 *
 * 3. CCTV3
 * dir 0 2 1 -> 1 3 2 -> 2 0 3 -> 3 1 0
 *
 * 4. CCTV4
 * dir 0 2 1 3 -> 1 3 2 0 -> 2 0 3 1 -> 3 1 0 2
 */

//사각지대 계산
int blindSpot() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) // 0인 애들 센다
                cnt++;
        }
    }
    return cnt;
}

void backtracking(int idx) {
    if (idx == n * m) { //기저 조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return;
    }

    int row = idx / m;
    int col = idx % m;
    int cur = board[row][col];
    if (cur == 0 || cur == 6 || cur == 7) //cctv가 없는 곳 (0: 빈 공간, 6: 벽, 7: ray 닿음)
        return backtracking(idx + 1); //다음 칸으로

    vector<vector<int>> save = board; //unvisited 처리용 board 상태 저장
    for (int i = 0; i < 4; i++) { //4개의 방향에 대해 cctv 설치 후 백트래킹으로 보냄~
        install(cur, row, col, i);
        backtracking(idx + 1);
        board = save; // 보드 상태 복구

        //2번 cctv의 방향 종류는 2개, 5번 cctv의 방향 종류는 1개
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0))
            break;
    }
}

/**
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *    1, 3, 4번 cctv : 4방향
 *    2번 cctv : 2방향
 *    5번 cctv : 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 *
 * 풀이 : https://myunji.tistory.com/411
 * 해당 코드는 위 링크의 코드를 리팩토링한 코드입니다.
 * 말로는 풀이를 설명하기 어려우니 링크를 꼭 확인해주세요!
 */
int main() {
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    //연산
    backtracking(0);

    //출력
    cout << ans;