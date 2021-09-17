//1935 후위표기식2
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int N;
    stack<double> p;
    vector<int> num;
    num.assign(26, 0);
    cin >> N;
    string line;
    cin >> line;
    int i = 0;
    while(N--){
        cin >> num[i];
        i++;
    }

    i = 0;
    p.push(num[line[i]-65]);
    while(1) {
        i++;
        char ch = line[i];
        if (0 <= (ch - 65) && (ch - 65) <= 25) {
            p.push(num[ch - 65]);
        }else {
            double b = p.top();
            p.pop();
            double a = p.top();
            p.pop();
            switch (ch){
                case '*':
                    p.push(a * b);
                    break;
                case '/':
                    p.push(a / b);
                    break;
                case '+':
                    p.push(a + b);
                    break;
                case '-':
                    p.push(a - b);
                    break;
            }
        }
        if (i == line.size() - 1)
            break;

    }
    cout << fixed;
    cout.precision(2);
    cout << p.top();

    return 0;
}