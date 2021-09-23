//2503 숫자 야구
#include <iostream>
#include <vector>
using namespace std;

struct input{
    int one;
    int two;
    int three;
    int strike;
    int ball;
};

int main(){
    int count = 0 ;
    int N;
    cin >> N;
    vector<input> v(N, {0, 0, 0, 0, 0});
    while(N--){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a/100, (a % 100) / 10, a % 10, b, c});
    }

    for(int i = 1 ; i <=9 ; i++ ){
        for(int j = 1 ; j <= 9 ; j++){
            for(int k = 1 ; k <= 9 ; k++){
                // 숫자 ijk

                if(k == i || k ==j || j==i) continue; // 서로다른 숫자

                bool check = true; //모든 조건에 맞는지 체크하기 위함
                for(int m = 0 ; m < v.size() ; m++){
                    int m_strike = 0;
                    int m_ball = 0;

                    //첫번째 숫자 체크
                    if(i == v[m].one){
                        m_strike++;
                    }
                    else if(i==v[m].two || i==v[m].three){
                        m_ball++;
                    }

                    //두번째 숫자 체크
                    if(j == v[m].two){
                        m_strike++;
                    }
                    else if(j==v[m].one || j==v[m].three){
                        m_ball++;
                    }

                    //세번째 숫자 체크
                    if(k == v[m].three){
                        m_strike++;
                    }
                    else if(k==v[m].two || k==v[m].one){
                        m_ball++;
                    }

                    //m_strike vs strike, m_ball vs ball
                    if(m_strike != v[m].strike || m_ball != v[m].ball){
                        check = false;
                        break;
                    }
                }

                if(check) count++;
            }
        }
    }

    cout << count;

    return 0;
}