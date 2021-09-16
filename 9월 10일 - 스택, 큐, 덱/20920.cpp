//20920 영단어 암기는 어려워
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct word {
    string name;
    int cnt;
};

bool cmpAdv(const word &i1, const word &i2) {
    if (i1.cnt != i2.cnt) //자주 나오는 단어일수록 앞에 배치한다.
        return i1.cnt > i2.cnt;
    if (i1.name.length() != i2.name.length()) //해당 단어의 길이가 길수록 앞에 배치한다.
        return i1.name.length() > i2.name.length();
    return i1.name < i2.name; //이름이 사전 순으로 증가하는 순서
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    vector<word> voca;
    map<string, int> count; //단어 이름, 횟수

    //입력
    cin >> N >> M;
    voca.assign(N, {});

    for(int i = 0 ; i < N ; i++){
        cin >> voca[i].name;
        count[voca[i].name]++;
        voca[i].cnt = count[voca[i].name];
    }

    sort(voca.begin(), voca.end(), cmpAdv);

    //출력
    for (int i = 0; i < N; i++){
        if(voca[i].name.length() >= M && count[voca[i].name]>=0){
            cout << voca[i].name << "\n";
            count[voca[i].name]=-1;
        }
    }
}