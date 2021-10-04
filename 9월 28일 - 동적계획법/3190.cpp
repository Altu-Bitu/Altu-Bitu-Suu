//3190 뱀
#include <iostream>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
int N, K;

deque<pair<int, int>> snake; // front가 머리쪽, back가 꼬리쪽

void printArray(){ //디버깅용
    for(int i = 1 ; i < N+1 ; i++){
        for(int j = 1 ; j < N+1 ; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    cin >> N >> K;
    board.assign(N + 1, vector<int>(N+1, 0));
    for(int i = 0 ; i < K ; i++){
        int a, b;
        cin >> a >> b; // 사과의 위치
        board[a][b] = 1;
    }
    int L;
    cin >> L;
    queue<pair<int, char>> turn;
    for(int i = 0 ; i < L ; i++){
        int X;
        char direction;
        cin >> X >> direction; // 방향 전환
        turn.push({X, direction});
    }

    //입력 끝
    int time = 0;
    snake.push_back({1, 1});
    board[1][1] = 2;

    vector<char> LRUD = {'L', 'U', 'R', 'D'};
    int current = 2; //현재 방향 = LRUD[current]

    while(1){
        time++;

        int hx = snake.front().first;
        int hy = snake.front().second;

        //오른쪽일 때
        if(LRUD[current]=='R'){
            snake.push_front({hx, hy + 1}); //오른쪽으로 몸길이를 늘림
            if(hy + 1 > N) break; //늘렸더니 부딪힘
            if(board[hx][hy+1] == 2) break; //늘린 자리에 이미 몸통이 있음
            else if(board[hx][hy+1]==1){ //사과가 있음
                board[hx][hy+1] = 2; //사과를 없앰
            }
            else if(board[hx][hy+1]==0){ // 사과가 없음
                board[hx][hy+1] = 2;
                board[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
        }
        //아래 방향
        else if(LRUD[current]=='U'){
            snake.push_front({hx - 1, hy}); //오른쪽으로 몸길이를 늘림

            if(hx - 1 < 1) break; //늘렸더니 부딪힘
            if(board[hx-1][hy]==2) break; //늘린 자리에 이미 몸통이 있음
            else if(board[hx-1][hy]==1){ //사과가 있음
                board[hx-1][hy] = 2; //사과를 없앰
            }
            else if(board[hx-1][hy]==0){ // 사과가 없음
                board[hx-1][hy] = 2;
                board[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
        }
        // 위방향
        else if(LRUD[current]=='D'){
            snake.push_front({hx+1, hy}); //오른쪽으로 몸길이를 늘림

            if(hx + 1 > N) break; //늘렸더니 부딪힘
            if(board[hx+1][hy]==2) break; //늘린 자리에 이미 몸통이 있음
            else if(board[hx+1][hy]==1){ //사과가 있음
                board[hx+1][hy] = 2; //사과를 없앰
            }
            else if(board[hx+1][hy]==0){ // 사과가 없음
                board[hx+1][hy] = 2;
                board[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
        }
        // 왼쪽방향
        else if(LRUD[current]=='L'){
            snake.push_front({hx, hy-1}); //오른쪽으로 몸길이를 늘림

            if(hy - 1 < 1) break; //늘렸더니 부딪힘
            if(board[hx][hy-1]==2) break; //늘린 자리에 이미 몸통이 있음
            else if(board[hx][hy-1]==1){ //사과가 있음
                board[hx][hy-1] = 2; //사과를 없앰
            }
            else if(board[hx][hy-1]==0){ // 사과가 없음
                board[hx][hy-1] = 2;
                board[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
        }

        //방향 전환
        if(!turn.empty()){
            if(turn.front().first==time){
                char LD = turn.front().second;
                turn.pop();
                if(LD == 'L'){
                    if(current == 0) current = 3;
                    else current--;
                }
                else if(LD =='D'){
                    if(current == 3) current = 0;
                    else current++;
                }
            }
        }
    }
    cout << time;
    return 0;
}