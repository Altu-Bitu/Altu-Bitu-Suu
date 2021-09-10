//9375 패션왕 신해빈
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        map<string, set<string>> cloth; //(의상 종류, 의상 이름)

        for(int i = 0 ; i < n ; i++){
            string name, kinds;
            cin >> name >> kinds;
            cloth[kinds].insert(name);
        }
        
        int answer = 1;
        for (auto iter = cloth.begin() ; iter != cloth.end(); iter++) {
            answer *= cloth[iter->first].size() + 1;
        }
        cout << answer - 1 << "\n";
    }
}