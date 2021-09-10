//4358 생태학
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> m;
    int count = 0;
    while (1) {
        string tree;
        getline(cin, tree);
        if (cin.eof() == true) {
            break;
        }

        count++;
        if (m.find(tree) == m.end()) m[tree]=1;
        else m[tree]++;
    }

    for(auto iter=m.begin() ; iter!=m.end() ; iter++){
        double answer = (double)(iter->second * 100) / count;
        cout << fixed;
        cout.precision(4);
        cout << iter->first << " " << answer << "\n";
    }
}