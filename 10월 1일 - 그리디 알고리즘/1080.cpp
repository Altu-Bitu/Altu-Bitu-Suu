//1080 행렬
#include <iostream>
#include <vector>

using namespace std;
int N, M ;

vector<string> A;
vector<string> B;

int x[] = {0, 1, 2, 0, 0, 1, 1, 2, 2};
int y[] = {0, 0, 0, 1, 2, 1, 2, 1, 2};

void change(int start_x, int start_y){ // 0->1, 1->0
    for(int i= 0 ;  i < 9 ; i++){
        if(A[start_x+x[i]][start_y+y[i]]=='1')
            A[start_x+x[i]][start_y+y[i]]='0';
        else A[start_x+x[i]][start_y+y[i]]='1';
    }
}

int main() {
    int count = 0;
    cin >> N >> M;
    A.assign(N, "");
    B.assign(N, "");
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }

    for(int i = 0 ; i < N ; i ++){
        cin >> B[i];
    }

    for(int i = 0 ; i < N-2 ; i ++){
        for(int j= 0 ; j < A[0].length()-2 ; j++){
            if(A[i][j]!=B[i][j]){
                change(i, j);
                count++;
            }
        }
    }

    if(A!=B) cout << -1;
    else cout << count;
    return 0;
}
