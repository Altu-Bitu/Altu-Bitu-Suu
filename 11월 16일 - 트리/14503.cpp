//14503 로봇 청소기
#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int N, M;
vector<vector<int>> board;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void clean(int r, int c, int d){
    if(r <= 0 || r >= N+1 || c <= 0 || c >= M+1) return; // 범위 체크
    //다음 방향
    int ny = r + dy[d];
    int nx = c + dx[d];

    //네 방향 모두 청소가 되어있음
    if(board[r+dy[0]][c+dx[0]] && board[r+dy[1]][c+dx[1]] && board[r+dy[2]][c+dx[2]] && board[r+dy[3]][c+dx[3]]){
        //d
        if(board[r+dy[(d+3) % 4]][c+dx[(d+3) % 4]] == 1){ //후진 불가
            return;
        }else{//c
            clean(r+dy[(d+3) % 4], c+dx[(d+3) % 4], d); //바라보는 방향 유지하고 후진
            return;
        }
    }

    //a
    if(!board[ny][nx]){
        board[ny][nx] = 2;
        ans++;
        clean(ny, nx, (d+3) % 4);
    }else{ //b
        clean(r, c, (d+3) % 4);
    }
}

int main() {
    int r, c, d;
    cin >> N >> M;
    board.assign(N+2, vector<int>(M+2, 0));
    cin >> r >> c >> d; // 로봇청소기 칸. d는 북동남서

    for(int i = 0 ; i < N+2 ; i++){
        board[i][0] = 1;
        board[i][M+1] = 1;
    }
    for(int i = 0 ; i < M+2 ; i++){
        board[0][i] = 1;
        board[N+1][i] = 1;
    }

    for(int i = 1 ; i <= N ; i++ ){
        for(int j = 1 ; j <= M ; j++){
            cin >> board[i][j];
        }
    }

    board[r+1][c+1] = 2;
    ans++;

    clean(r+1, c+1, d);

    cout << ans;

    return 0;
}
