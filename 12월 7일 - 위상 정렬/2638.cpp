//2638 치즈
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

queue<pair<int, int>> ch;
vector<vector<int>> paper;

bool is_nest(int row, int col, int n, int m){
    queue<pair<int, int>> q;
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    q.push({row, col});
    visit[row][col] = true;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(paper[r][c]==1){ //1만나면 막힌것.
            continue;
        }

        if(r==0 || c==0 || r == n-1 || c == m-1){
            return false;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= n || nr < 0 || nc >= m || nc < 0)
                continue;

            if(!visit[nr][nc]){ //방문 X
                q.push({nr, nc});
                visit[nr][nc] = true;
            }
        }
    }
    return true;
}

bool side(int row, int col, int n, int m){
    int count = 0;
    for(int i = 0 ; i < 4 ; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr >= n || nr < 0 || nc >= m || nc < 0)
            continue;

        if(paper[nr][nc] == 0 && !is_nest(nr, nc, n, m)) { //공기접촉
            count++;
        }
    }
    if(count >= 2)
        return true;
    return false;
}

void solution(int n, int m){
    //큐 초기화
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(paper[i][j]==1){
                bool check = side(i, j, n, m);
                if(check){
                    ch.push({i, j});
                }
            }
        }
    }

    int hour = 0;
    while(!ch.empty()){
        hour++;
        while(!ch.empty()){
            int row = get<0>(ch.front());
            int col = get<1>(ch.front());
            ch.pop();

            paper[row][col] = 0; //녹았다.
        }

        //다시 넣고
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(paper[i][j]==1){
                    bool check = side(i, j, n, m);
                    if(check){
                        ch.push({i, j});
                    }
                }
            }
        }
    }

    cout << hour;
}
int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    paper.assign(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> paper[i][j];
        }
    }
    solution(n, m);
    return 0;
}