//1946 신입사원
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
    int document;
    int interview;
};
vector<person> emp;

bool compare(person A, person B){
    return A.document < B.document;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        int N;
        cin >> N;
        int total = 1;
        emp.assign(N, {0, 0});
        for(int j = 0 ; j < N ; j++){
            cin >> emp[j].document >> emp[j].interview;
        }
        sort(emp.begin(), emp.end(), compare);
        int standard = emp[0].interview;
        for(int j = 1 ; j < N ; j++){
            if(emp[j].interview <= standard){
                total++;
                standard = emp[j].interview;
            }
        }
        cout << total << "\n"; // 줄바꿈 안써줬다고 계속 틀려서 넘 힘들었음..
    }
    return 0;
}
