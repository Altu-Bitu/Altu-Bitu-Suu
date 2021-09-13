//14425 문자열 집합
#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M;
    set<string> s;
    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
        string name;
        cin >> name;
        s.insert(name);
    }

    int count = 0;
    for(int i = 0 ; i < M ; i++){
        string name;
        cin >> name;
        const bool is_in = s.find(name) != s.end();
        if(is_in) count++;
    }

    cout << count;
}