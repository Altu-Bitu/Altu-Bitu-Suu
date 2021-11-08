//1063 킹

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &board){ //디버깅용
    for(int i = 1 ; i < board.size() ; i++){
        for(int j = 1 ; j < board[0].size() ; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}


int main() {
    string king_lo, rock_lo;
    int N;
    cin >> king_lo >> rock_lo;
    cin >> N;
    vector<vector<int>> board(9, vector<int>(9, 0)); // 체스판. 숫자 기준으로 1~8을 쓰겠음

    int king_cx = king_lo[0]-'A'+1;
    int king_cy = king_lo[1]-'0';
    int rock_cx = rock_lo[0]-'A'+1;
    int rock_cy = rock_lo[1]-'0';
    board[king_cx][king_cy] = 1; //체스판 회전, 1이 킹 위치 2가 돌 위치
    board[rock_cx][rock_cy] = 2;

   // print(board);

    while(N--){
        string direction;
        cin >> direction;

        int king_nx = king_cx, king_ny = king_cy, rock_nx = rock_cx, rock_ny = rock_cy;
        if(direction.length() == 1){
            switch (direction[0]) {
                case 'L': // 위
                    king_nx = king_cx - 1;
                    break;
                case 'R': // 아래
                    king_nx = king_cx + 1;
                    break;
                case 'B': // 왼쪽
                    king_ny = king_cy - 1;
                    break;
                case 'T': //
                    king_ny = king_cy + 1;
                    break;
            }
        }else{ //대각선
            switch (direction[0]) {
                case 'L': // 위
                    king_nx = king_cx - 1;
                    break;
                case 'R': // 아래
                    king_nx = king_cx + 1;
                    break;
                case 'B': // 왼쪽
                    king_ny = king_cy - 1;
                    break;
                case 'T': // 오른쪽
                    king_ny = king_cy + 1;
                    break;
            }
            switch (direction[1]){
                case 'L': // 위
                    king_nx = king_cx - 1;
                    break;
                case 'R': // 아래
                    king_nx = king_cx + 1;
                    break;
                case 'B': // 왼쪽
                    king_ny = king_cy - 1;
                    break;
                case 'T': // 오른쪽
                    king_ny = king_cy + 1;
                    break;
            }
        }
        //cout <<"king nx: " <<king_nx << " " << "king_ny: " << king_ny <<"\n";
        if( 0 >= king_nx || king_nx > 8 || 0 >= king_ny || king_ny > 8) //범위 벗어나면
            continue; //이동하지 않음

        board[king_cx][king_cy] = 0;
        if(board[king_nx][king_ny]==2){ //돌이 이미 있다면 돌을 이동
            rock_nx = rock_cx + (king_nx - king_cx);
            rock_ny = rock_cy + (king_ny - king_cy);
            if( 0 >= rock_nx || rock_nx > 8 || 0 >= rock_ny || rock_ny > 8) //범위 벗어나면
                continue; //이동하지 않음

            board[rock_nx][rock_ny] = 2; // 돌 이동
            rock_cx = rock_nx; rock_cy = rock_ny; // 돌 위치 갱신
        }
        board[king_nx][king_ny] = 1; //킹 이동
        king_cx = king_nx; king_cy = king_ny; // 킹 위치 갱신

        //print(board);
        //cout <<"\n";
    }

    cout << (char)(king_cx+'A'-1) << (char)(king_cy+'0') << "\n";
    cout << (char)(rock_cx+'A'-1) << (char)(rock_cy+'0') << "\n";
    return 0;
}
