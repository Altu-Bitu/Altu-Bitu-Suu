//3085 사탕게임
#include <iostream>
#include <vector>

using namespace std;

int max_count = 0;
int n;

void count(vector<vector<char>> candy){
    //행
    for(int i = 0 ; i < n ; i++){
        int temp = 1;
        int temp_max = 0;
        for(int j = 0 ; j < n-1 ; j++){
            if(candy[i][j]==candy[i][j+1]){
                temp++;
            }else{
                temp_max = max(temp_max, temp);
                temp = 1;
            }
        }
        //count
        temp_max = max(temp_max, temp);
        max_count = max(temp_max, max_count);
    }

    //열
    for(int i = 0 ; i < n ; i++){
        int temp = 1;
        int temp_max = 0;
        for(int j = 0 ; j < n-1 ; j++){
            if(candy[j][i]==candy[j+1][i]){
                temp++;
            }else{
                temp_max = max(temp_max, temp);
                temp = 1;
            }
        }
        //count
        temp_max = max(temp_max, temp);
        max_count = max(temp_max, max_count);
    }

}

//디버깅용
void print_array(vector<vector<char>> candy){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << candy[i][j] << " ";
        }
        cout << "\n" ;
    }
    cout << "\n";
}

void solution(vector<vector<char>> candy){
    count(candy); //시작시 카운트
    //행 바꿈
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            if(candy[i][j]!=candy[i][j+1]){
                char temp = candy[i][j+1];
                candy[i][j+1] = candy[i][j];
                candy[i][j] = temp;
                count(candy); //바꾸고 카운트

                //원상 복구
                temp = candy[i][j+1];
                candy[i][j+1] = candy[i][j];
                candy[i][j] = temp;
            }
        }
    }

    //열 바꿈
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            if(candy[j][i]!=candy[j+1][i]){
                char temp = candy[j+1][i];
                candy[j+1][i] = candy[j][i];
                candy[j][i] = temp;
                //print_array(candy);
                count(candy); //바꾸고 카운트

                //원상 복구
                temp = candy[j+1][i];
                candy[j+1][i] = candy[j][i];
                candy[j][i] = temp;
            }
        }
    }
}

int main() {
    cin >> n;
    vector<vector<char>> candy(n, vector<char>(n, ' '));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> candy[i][j];
        }
    }

    solution(candy);
    cout << max_count;

    return 0;
}