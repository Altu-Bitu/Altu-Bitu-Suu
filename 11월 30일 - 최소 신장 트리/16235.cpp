//16235 나무 재테크
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> board; // 양분
    deque<pair<pair<int, int>, int>> tree; // {r, c}, 나무의 나이
    vector<vector<int>> A; // 추가되는 양분

    int n, m, k;

    cin >> n >> m >> k;
    board.assign(n+1, vector<int>(n+1, 5)); // 양분
    A.assign(n+1, vector<int>(n+1, 0)); // 추가되는 양분
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> A[i][j];
        }
    }

    //나무의 위치
    for(int i = 0 ; i < m ; i++){
        int r, c, age;\
        cin >> r >> c >> age;
        tree.push_back(make_pair(make_pair(r, c), age));
    }

    while(k--){
        vector<pair<pair<int, int>, int>> dead;

        //spring
        queue<pair<int, int>> new_tree;

        int size = tree.size();
        while(size--){
            int r = tree.front().first.first;
            int c = tree.front().first.second;
            int age = tree.front().second;
            tree.pop_front();

            //충분한 양분이 X
            if(board[r][c] < age){  // 죽는다
                dead.push_back(make_pair(make_pair(r, c), age));
                continue;
            }

            //양분이 있으면
            board[r][c] -= age; // 양분을 먹고
            tree.push_back({{r, c}, age+1});

            if( (age+1) % 5 == 0){
                new_tree.push({r, c});
            }
        }

        //summer
        for(int i = 0 ; i < dead.size() ; i++){
            int r = dead[i].first.first;
            int c = dead[i].first.second;
            int age = dead[i].second;
            //각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
            board[r][c] += (age/2);
        }


        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!new_tree.empty()){
            int r = new_tree.front().first;
            int c = new_tree.front().second;
            new_tree.pop();

            for(int j = 0 ; j < 8 ; j++){
                //새로운 좌표
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(nr > n || nr < 1 || nc > n || nc < 1) //범위 벗어남
                    continue;

                tree.push_front({{nr, nc}, 1});
            }
        }

        //winter
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                board[i][j] += A[i][j];
            }
        }
    }

    //살아남은 나무의 수 출력
    cout << tree.size();
    return 0;
}