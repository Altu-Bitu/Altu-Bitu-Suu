//11651 좌표 정렬하기 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct location {
    int x;
    int y;
};
vector<location> coordinate;

void printLocation(int N){
    for(int i = 0 ; i < N ; i++){
        cout << coordinate[i].x << ' ' << coordinate[i].y << "\n";
    }
}
bool compare(location A, location B){
    if(A.y != B.y)
        return A.y < B.y;
    return A.x < B.x;
}
int main(){
    int N;
    cin >> N;
    coordinate.assign(N, {0, 0});
    for(int i = 0 ; i < N ; i++){
        cin >> coordinate[i].x >> coordinate[i].y;
    }
    sort(coordinate.begin(), coordinate.end(), compare);
    printLocation(N);

    return 0;
}