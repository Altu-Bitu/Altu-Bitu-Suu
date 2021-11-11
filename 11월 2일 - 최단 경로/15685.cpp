//샘플 코드 + 주석 제출 (필수 문제)
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 100 + 1; //격자 사이즈

/**
 * [최단 경로]
 * 15685 드래곤 커브
 * 1.방향 저장 벡터, 끝점을 0세대로 초기화하고, 보드에 0세대를 표시한다.
 * 2. 세대를 거듭하면서 드래곤 커브를 만든다. 세대마다 끝 점을 매번 갱신한다.
 * 2-1. 한 세대마다 방향을 90도로 돌리고, 새로운 끝 점을 격자에 표시하고, 방향 벡터에 새로운 방향을 삽입하는 것을 반복한다.
 * 3. 모든 드래곤 커브 표시가 끝났으면 격자 전체를 돌면서 네 칸이 전부 true로 표시된 정사각형이 있는지 검사한다. 있다면 정답 개수를 증가시킨다.
 */


//우, 상, 좌, 하 (시계방향 순서)
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

//크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것이 개수 구하기
int cntSquare(vector<vector<bool>> &board) {
    int ans = 0;
    for (int i = 0; i < SIZE - 1; i++) { // 격자전체를 돌면서
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) // 네 꼭지점이 전부 true로 되어있음 개수 증가
                ans++;
        }
    }
    return ans;
}

ci makeDragonCurve(vector<vector<bool>> &board, vector<int> &direc, ci point) { //board: 격자, direc: 시작 방향, point: 그 전 세대 끝점
    int size = direc.size(); //그 전 세대까지의 방향 정보
    for (int i = size - 1; i >= 0; i--) { // 0세대: 1번, 1세대: 2번, 2세대: 4번.. 이런식으로 반복하게 될거임
        int new_direc = (direc[i] + 1) % 4; //현재 시작 점의 방향. 90도 시계방향 회전한거임.
        point = {point.first + dy[new_direc], point.second + dx[new_direc]}; //현재 끝 점
        board[point.first][point.second] = true; //격자에 표시
        direc.push_back(new_direc); // 새로운 방향 삽입
    }
    return point; // 이번 세대 끝점 반환
}

/**
 * x: 열, y: 행
 *
 * 드래곤 커브 = 선분들로 이루어짐
 * => 각 선분들의 방향을 저장해서 드래곤 커브의 좌푯값을 구해나가자
 *
 * 드래곤 커브는 각 세대마다 끝 점을 기준으로 시계 방향으로 90도 회전
 * -> 드래곤 커브 세대의 각 선분 방향 = 전 세대 방향들에서 차례로 끝 점을 기준으로 시계방향으로 이동한 것과 같음
 * -> (우(0) -> 상(1), 상(1) -> 좌(2), 좌(2) -> 하(3), 하(3) -> 우(0)) 로 이동
 * ex) 0세대: 우
 *     1세대: 상
 *     2세대: 좌 상 (1세대 + 0세대의 상, 우에서 각각 시계방향 이동)
 *     3세대: 좌 하 좌 상 (2세대 + 1세대 + 0세대에서 각각 시계방향 이동)
 *
 * 0세대는 이미 방향이 주어지므로 먼저 처리
 * 드래곤 커브는 격자 밖으로 나가지 않음 -> 범위 검사 필요 x
 */

int main() {
    int n, x, y, d, g;

    //입력 & 연산
    cin >> n; // 드래곤 커브의 개수
    vector<vector<bool>> board(SIZE, vector<bool>(SIZE, false)); //100x100 격자
    while (n--) {
        // 드래곤 커브의 정보
        // x, y: 드래곤 커브의 시작 점, d: 시작 방향, g: 세대
        cin >> x >> y >> d >> g;
        vector<int> direc; //세대의 방향 정보 저장 및 보존하는 벡터
        ci end_point = {y + dy[d], x + dx[d]}; //0세대 끝점
        board[y][x] = board[end_point.first][end_point.second] = true; //0세대 시작점, 끝점 초기화
        direc.push_back(d); //0세대 방향 삽입
        while (g--) { //각 세대마다 드래곤 커브 만들기
            end_point = makeDragonCurve(board, direc, end_point); //보드, 시작 방향, 세대 끝점 정보를 보냄 (끝점 세대 거듭할수록 계속 갱신)
        }
    }

    //출력
    cout << cntSquare(board) << '\n';
    return 0;
}