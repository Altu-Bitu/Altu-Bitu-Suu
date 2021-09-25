//20055 컨베이어 벨트 위의 로봇
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> belt; //내구도

int check_zero(){
    int count=0;
    for(int i = 0 ; i < belt.size() ; i++){
        if(belt[i]==0) count++;
    }
    return count;
}

void print_belt(){
    for(int i = 0 ; i < belt.size() ; i++)
        cout << belt[i] << " ";
    cout <<"\n";
}

int main() {
    int N, K;
    cin >> N >> K;
    queue<int> robot;
    vector<int> ox; //belt 위 로봇 유무 (1:존재 0:없음)
    belt.assign(2*N, 0);
    ox.assign(2*N, 0);

    for(int i = 0 ; i < 2*N ; i++){
        cin >>belt[i];
        ox[i]=0;
    }

    //초기 상태
    int up = 0; //올리는 위치
    int down = N-1; //내리는 위치
    int level = 1;
    while(1){
        //1. 다같이 회전
        if(down!=0) down--; else down=2*N-1;
        if(up!=0) up--; else up = 2*N-1;

        if(!robot.empty()) {
            if (robot.front() == down) {
                ox[down] = 0;
                robot.pop();
            }

            //2. 로봇 이동
            int qsize = robot.size();
            for(int i = 0 ; i < qsize ; i++){
                int a = robot.front();
                robot.pop();

                int next;
                if(a==2*N-1) next = 0; else next = a+1;
                if(ox[next]==0 && belt[next]!=0){
                    // 로봇이 없고 내구도가 0이 아니라면
                    if(next!=down){
                        robot.push(next); //로봇이 이동한다. 만약 이동해서 내리는 위치면 다시 안넣음.
                        ox[next]=1;
                    }
                    belt[next]--; //내구도 감소
                    ox[a]=0;
                }
                else robot.push(a);
            }
        }
        //3. 로봇올리기
        if(belt[up] != 0){
            robot.push(up);
            ox[up]=1;
            belt[up]--; //내구도 감소
        }

        //4. 내구도 0인 칸 체크
        if(check_zero()>=K) break;
        level++;
    }
    cout << level;
    return 0;
}