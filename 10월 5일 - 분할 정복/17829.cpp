//17829 222-풀링
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<vector<int>> pooling;

int divide(int r_start, int c_start, int size) { // 시작점이랑 size
    if(size==1)
        return pooling[r_start][c_start];

    vector<int> second_max;

    for(int i = r_start ; i < r_start + size ; i+=size/2){
        for(int j = c_start ; j < c_start + size ; j+=size/2){
            //cout << "i: " << i  << " j : " << j << " size: "<< size/2 << "\n";
            second_max.push_back(divide(i, j, size/2));
        }
    }

    sort(second_max.begin(), second_max.end());
    //cout << " size: " << size << " cout: " << second_max[second_max.size()-2] << "\n";
    return second_max[second_max.size()-2];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    pooling.assign(N, vector<int>(N, 0));
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j++){
            cin >> pooling[i][j];
        }
    }
    cout << divide(0, 0, N);
    return 0;
}