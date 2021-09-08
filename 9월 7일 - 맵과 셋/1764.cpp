//1764 듣보잡
#include <iostream>
#include <set>

using namespace std;

/* 시간 초과
bool find(string name, set<string> s){
    for (auto iter = s.begin(); iter != s.end(); iter++){
        if(*iter==name) return true;
    }
    return false;
}
*/

int main() {
    int N, M;
    set<string> not_hear;
    set<string> not_hear_see;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        string name;
        cin >> name;
        not_hear.insert(name);
    }
    for(int i = 0 ; i < M ; i++){
        string name;
        cin >> name;
        const bool is_in = not_hear.find(name) != not_hear.end();
        if(is_in) not_hear_see.insert(name);
    }

    /*
    for (auto iter = not_see.begin(); iter != not_see.end(); iter++){
        if(find(*iter, not_hear)) not_hear_see.insert(*iter);
    }
    */
    cout << not_hear_see.size() << "\n";
    for (auto iter = not_hear_see.begin(); iter != not_hear_see.end(); iter++){
        cout << *iter <<"\n";
    }
}