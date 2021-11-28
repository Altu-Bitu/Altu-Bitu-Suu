//4963 섬의 개수
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<bool>> visited;

//연결된 애들 다 방문해서 false로 만들어버림
void dfs(stack<pair<int, int>> s, vector<vector<int>> island, int w, int h){ //필요한거: stack, 섬, 방문벡터, 너비, 높이
    int dr[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    while(!s.empty()){
        int cr = s.top().first; // i = 행 = h
        int cc = s.top().second; // j = 열 = w
        s.pop();
        //하나 꺼냄
        visited[cr][cc] = true; //방문처리

        for (int i = 0; i < 8; i++) { //상하좌우대각선... 방향 탐색(인접한 노드 탐색)
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && island[nr][nc] == 1 && !visited[nr][nc]) { //범위 안이고 1이고 방문 안함
                s.push({nr, nc});
            }
        }
    }
}

int main(){
    vector<vector<int>> island;
    while(true){
        int w, h;
        cin >> w >> h;
        if(w==0 && h==0) break; //입력 종료

        island.assign(h, vector<int>(w, 0));
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin >> island[i][j];
            }
        }
        visited.assign(h, vector<bool>(w, false));

        int count = 0;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++) {
                if (!visited[i][j] && island[i][j]==1) {
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    dfs(s, island, w, h); //이어져있으면 다 방문해버림
                    count++;
                }
            }
        }
        cout << count << "\n";

    }
    return 0;
}
