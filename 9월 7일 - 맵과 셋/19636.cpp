//19636 요요 시뮬레이션
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;
    int expectWX, expectWO, expectI;

    //첫번째 줄 출력
    int E = I0 + A;
    expectWX = W0 + (I - E) * D;
    bool isDanger1 = false;
    if(expectWX<=0 || I0 <=0) isDanger1=true;

    if(isDanger1) cout << "Danger Diet\n";
    else cout << expectWX << " " << I0 << "\n";

    //두번째 줄 출력
    expectWO = W0;
    expectI = I0;
    while(D--){
        E = expectI + A;
        expectWO += I - E;
        int absolute = I - E;
        if(absolute < 0) absolute=-absolute;
        if(absolute > T){ //역치를 넘으면 갱신
            expectI += floor((double)(I - E)/2);
        }
    }

    //요요 체크
    string isYOYO = "NO";
    if(I0 - expectI > 0) isYOYO = "YOYO";

    //위험 체크
    bool isDanger2 = false;
    if(expectWO<=0 || expectI <=0) isDanger2=true;
    if(isDanger2){
        cout << "Danger Diet";
    }
    else{
        cout << expectWO << " " << expectI << " " << isYOYO << "\n" ;
    }
    return 0;
}