//1107 리모컨
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> button(10, 0);

bool check(int ud){ //고장난 버튼을 포함하고 있는지 점검
    string a = to_string(ud);
    for(int i = 0 ; i < a.length() ; i++){
        if(button[a[i]-'0']==1) return false;
    }
    return true;
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        int num;
        cin >> num;
        button[num] = 1;
    }

    int up = N;
    int down = N;
    int count = 0;
    int sub = 0;
    if(M!=10) {
        while (1) {
            if (check(up) && !check(down)) {
                sub = up;
                break;
            } else if (!check(up) && check(down)) {
                sub = down;
                break;
            } else if (check(up) && check(down)) { //둘다 됨
                sub = min(up, down);
                break;
            }

            up++;
            if (down > 0) down--;
        }
        count = abs(N - sub) + to_string(sub).length();
        int count2 = abs(N - 100);
        if (count2 < count) cout << count2; else cout << count;
    }
    else{
        cout << abs(N-100);
    }
    return 0;
}