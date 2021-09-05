//10994 별찍기 - 19
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> A;

void star (int N, int center){
    if(N==1){
        A[center][center]='*';
        return;
    }

    int start = center - 2 * (N-1); //시작점
    int end = center + 2 * (N-1); //끝점
    for(int i = start ; i <= end ; i++){
        A[start][i] = '*';
        A[end][i] = '*';
        A[i][start] = '*';
        A[i][end] = '*';
    }
    star(N-1, center);
}

void printArr(int N){
    for(int i = 0 ; i < N ; i++){
        for( int j = 0 ; j < N ; j++){
            cout << A[i][j];
        }
        cout << '\n';
    }
}
int main (){
    int N;
    cin >> N;
    A.assign(4*(N-1) + 1, vector<char>(4*(N-1) + 1, ' ')); // 2차원 배열
    int size = 4*(N-1) + 1;
    int center = size / 2; // 기준점
    star(N, center);

    printArr(4 * (N-1) + 1);
    return 0;
}