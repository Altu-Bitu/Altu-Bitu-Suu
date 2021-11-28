//샘플 코드 + 주석 제출 (필수 문제)
#include <iostream>
#include <vector>

using namespace std;

int ans, n, m;
vector<vector<int>> board;
//상하좌우 체크용
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

/**
 * [투 포인터]
 * 14500 테트로미노
 * 1. 보드 전체를 브루트 포스 알고리즘으로 순회하면서 최댓값 갱신
 * 2. 한붓그리기 가능한 네개의 블록은 백트래킹으로 해결
 * 2-1. 방문한 블록은 0으로 바꿔서 방문체크하고 다음 단계로 넘김. 넘긴 다음에 다시 값 복구. 상하좌우로 백트래킹을 하면서 총 4개의 블록을 지나왔으면 ans를 최댓값으로 갱신.
 * 3. 한붓그리기 불가능한 보라색 블록은 따로 처리
 * 3-1. 보라색 블록은 상하좌우를 for문으로 조사하면서 최솟값을 찾음. 다섯개의 블록 합 중 최솟값을 뺀 값을 ans와 비교하여 최댓값으로 갱신.
 */

//board[row][col]을 가운데로 하는 +모양 만들기 (얘는 한붓그리기가 안돼서 따로 처리해야함. 백트래킹은 근접 블록으로 옮겨다니니까 한붓그리기 되면 가능한데 얘는 안 됨)
int horn(int row, int col) {
    int cnt = 0, min_block = 1001, sum = board[row][col];

    for (int i = 0; i < 4; i++) { // 상하좌우
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue;
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc];
        cnt++;
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0;
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum;
    //+
    return sum - min_block; // 5개 블록에서 가장 작은 값을 빼면 결국 네개의 블록이 최댓값이 되니까
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum); //기존 값과 백트래킹 끝나고 나온 값 중 가장 큰값으로 갱신
        return;
    }

    for (int i = 0; i < 4; i++) { //상하좌우
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면 통과
            continue;
        int save = board[nr][nc]; //임시 저장
        board[nr][nc] = 0; // 방문처리
        backtracking(nr, nc, cnt + 1, sum + save); //백트래킹. 블록 하나 증가. 블록 값들 sum 한거 다음 단계로 넘김.
        board[nr][nc] = save; // 값 복구
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */
int main() {
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) { // 종이
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // 보드 전체를 브루트포스로 탐색함
            ans = max(ans, horn(i, j)); //보라색 블럭 처리
            int save = board[i][j]; //임시 저장

            board[i][j] = 0; // 방문처리
            backtracking(i, j, 1, save); //나머지 모양 처리. row, column, 깊이, 그 위치의 값
            board[i][j] = save; //값 복구
        }
    }

    //출력
    cout << ans;
}