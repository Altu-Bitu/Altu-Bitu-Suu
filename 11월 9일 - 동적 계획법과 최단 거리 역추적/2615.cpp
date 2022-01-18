//2615번 오목
#include <iostream>
#include <vector>

using namespace std;

int row = 0;
int column = 0;

bool check(int k, int l){
    if(k >=1 && k<=19 && l>=1 && l<= 19)
        return true;
    return false;
}

int judge(vector<vector<int>> &board){

    // ㅡ(왼->오), ㅣ(위->아래),  \(왼위->오아래) , /(왼아래->오위)
    vector<pair<int,int>> x = {{0, 0}, {-1, 1}, {-1, 1}, {1, -1}}; //i
    vector<pair<int,int>> y = {{-1, 1}, {0, 0}, {-1, 1}, {-1, 1}}; //j

    //보드 탐색
    for(int i = 1 ; i <= 19 ; i++){
        for(int j = 1 ; j <= 19 ; j++){
            //돌이 놓이지 않았음
            if(board[i][j]==0){
                continue;
            }

            //돌이 놓였음
            int current = board[i][j]; //1 또는 2
            int count, k, l;
            for(int m = 0 ; m < 4 ; m++){
                count = 0;
                k = i;
                l = j;
                while(board[k][l] == current && (k >=1 && k<=19 && l>=1 && l<= 19)){
                    row = k;
                    column = l;
                    k = k + x[m].first;
                    l = l + y[m].first;
                    count++;
                }
                k = i;
                l = j;
                count--;
                while(board[k][l] == current && (k >=1 && k<=19 && l>=1 && l<= 19)){
                    k = k + x[m].second;
                    l = l + y[m].second;
                    count++;
                }

                if(count == 5){
                    return current;
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> board;
    board.assign(21, vector<int>(21, 0));

    //입력
    for(int i = 1 ; i <= 19 ; i++){
        for(int j = 1 ; j <= 19 ; j++){
            cin >> board[i][j];
        }
    }

    int ans = judge(board);
    cout << ans;
    if(ans!=0)
        cout << "\n" << row << " " << column;

    return 0;
}
