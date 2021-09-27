//2858 기숙사 바닥
#include <iostream>

using namespace std;

int main(){
    int R, B;
    cin >> R >> B;
    int W;
    //1. L + L + W + W - 4 = R
    //2. L * W = R + B
    for(int i = 1 ; i <= R + B ; i++){
        if((R + 4 - 2 * i) % 2 ==0){
            W = (R + 4 - 2 * i) / 2; // 식 1번
            if(W * i == R+B){ // 식 2번
                cout << max(i, W) << " " << min(W, i);
                break;
            }
        }
    }

    return 0;
}