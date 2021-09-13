//10757 큰 수 A+B
#include <iostream>
#include <vector>

using namespace std;

vector<char> answer;

int main() {
    string min;
    string max;
    answer.assign(10001, ' ');
    cin >> min >> max;
    if(min.length() > max.length()) swap(min, max);

    int i = 0; // i는 answer의 index
    int repeat = max.length();
    int j = min.length() - 1, k = max.length() - 1; // j는 min의 index, k는 max의 index.
    int rest = 0;
    while(repeat--){ //일의 자리부터 시작해 각 자릿수끼리 더하고, 자릿수 넘어가면 rest에 담아 다음 자릿수에에 보낸다.
        int total = 0;
        if(j >= 0 ) total += min[j--] - '0';
        total += max[k--] - '0';
        total += rest;
        answer[i++]= char(total % 10 + 48);
        rest = total / 10;
    }
    if(rest!=0) answer[i] = (char)(rest + 48); //마지막으로 하나 남았으면 처리.
    else i--;

    for(int j = i ; j >= 0 ; j--){
        cout << answer[j];
    }
    return 0;
}