//1244 스위치 켜고 끄기
#include <iostream>
#include <vector>

using namespace std;

int N, M; // switch 개수, 학생 수
vector<int> sw;

void change(int switch_num){
    if(sw[switch_num]==1) sw[switch_num]=0;
    else sw[switch_num]=1;
}

void boy(int num){
    int mul = num;
    while(mul <= N){
        change(mul);
        mul += num;
        //cout << "num: " << num << "\n";
    }
}

void girl(int num){
    //일단 중심 바꿈
    change(num);
    int left = num;
    int right = num;
    while(2<=left && right <=N-1){
        left--;
        right++;
        if(sw[left]!=sw[right]) break; //대칭 아님
        //대칭임
        change(left);
        change(right);
    }
}
int main(){
    cin >> N;
    sw.assign(N+1, 0);
    for(int i = 1 ; i <= N ; i++){
        cin >> sw[i];
    }
    cin >> M;
    while(M--){
        int gender, num;
        cin >> gender >> num;
        if(gender==1){ //남자면 배수 바꿈
            boy(num);
        }
        else if(gender==2){
            girl(num);
        }
    }

    //정답 출력

    for(int i = 1 ; i <= N ; i++){
        cout << sw[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
    return 0;
}