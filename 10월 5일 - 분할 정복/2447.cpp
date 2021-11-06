//2447 별 찍기 - 10
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char>> arr;

void star(int x1, int y1, int x2, int y2) { // 시작좌표(x1, y1), 끝좌표(x2,y2)
    int n = y2-y1+1;

    //행
    int startX1 = x1;
    int endX1 = x1+n/3-1;
    int startX2 = x1+n/3;
    int endX2 = x1+n/3*2-1;
    int startX3 = x1+n/3*2;
    int endX3 = x1+n-1;

    //열
    int startY1 = y1;
    int endY1 = y1+n/3-1;
    int startY2 = y1+n/3;
    int endY2 = y1+n/3*2-1;
    int startY3 = y1+n/3*2;
    int endY3 = y1+n-1;

    if(n==1) {
        arr[x1][y1]='*'; //종료조건
        return;
    }

    star(startX1, startY1, endX1, endY1);
    star(startX1, startY2, endX1, endY2);
    star(startX1, startY3, endX1, endY3);

    star(startX2, startY1, endX2, endY1);

    star(startX2, startY3, endX2, endY3);

    star(startX3, startY1, endX3, endY1);
    star(startX3, startY2, endX3, endY2);
    star(startX3, startY3, endX3, endY3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr.assign(N+1, vector<char>(N+1, ' '));
    star(1, 1, N, N);

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++)
            cout << arr[i][j];
        cout << "\n";
    }
    return 0;
}
