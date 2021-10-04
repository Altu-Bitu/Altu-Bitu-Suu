//20923 숫자 할리갈리 게임
#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    deque<int> su, dodo, dodo_ground, su_ground;
    string result = " ";

    while(N--){
        int n, m;
        cin >> n;
        dodo.push_front(n);
        cin >> m;
        su.push_front(m);
    }

    bool dodo_turn = true;
    while(M--){
        //게임 진행
        //도도를 시작으로 가장 위(front) 카드를 내려놓음. ** 한 턴에 한명만 내려놓는 거임
        if(dodo_turn){
            dodo_ground.push_front(dodo.front()); dodo.pop_front();
            dodo_turn = false;
        }else{
            su_ground.push_front(su.front()); su.pop_front();
            dodo_turn = true;
        }

        // 덱이 비었으면 **한쪽이 비면 바로 끝나는거라 pop 뒤에 놓아야함.
        if(dodo.empty() || su.empty()){
            break;
        }

        int su_ground_front, dodo_ground_front; // ground에 암것도 없는 경우
        if(!su_ground.empty()){
            su_ground_front = su_ground.front();
        }else su_ground_front = 0;
        if(!dodo_ground.empty()){
            dodo_ground_front = dodo_ground.front();
        }else dodo_ground_front = 0;

        //수연이가 종침
        if((dodo_ground_front + su_ground_front) == 5 && !su_ground.empty() && !dodo_ground.empty()){
            //도도의 그라운드 카드더미를 뒤집어(back) 덱 아래(back)에 합침
            while(!dodo_ground.empty()){
                su.push_back(dodo_ground.back());
                dodo_ground.pop_back();
            }
            //자신의 그라운드 카드 더미를 뒤집어 합침
            while(!su_ground.empty()){
                su.push_back(su_ground.back());
                su_ground.pop_back();
            }
        }
        //도도가 종침
        else if(dodo_ground_front==5 || su_ground_front==5){
            while(!su_ground.empty()){
                dodo.push_back(su_ground.back());
                su_ground.pop_back();
            }
            while(!dodo_ground.empty()){
                dodo.push_back(dodo_ground.back());
                dodo_ground.pop_back();
            }
        }
    }
    // 게임 진행 끝

    if(dodo.size() > su.size()) result = "do";
    else if(dodo.size()==su.size()) result = "dosu";
    else result = "su";
    
    cout << result;

    return 0;
}