//11399 ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> person;
int main(){
    int N;
    cin >> N;
    person.assign(N, 0);
    for(int i = 0 ; i < N ; i++){
        cin >> person[i];
    }
    sort(person.begin(), person.end());

    int sum = 0;
    int temp = 0;
    for(int i = 0 ; i < N ; i++){
        temp += person[i];
        sum += temp;
    }
    cout << sum;
    return 0;
}
