//1918 후위표기식
#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main(){
    string line;
    stack<char> ans;
    map<char, int> priority = {{'+', 1}, {'-', 1}, {'*',2}, {'/',2}};
    cin >> line;
    int i = 0;
    while(1){
        char ch = line[i]; // 'A'
        if(0<= ch-65 && ch-65 <=25){ //A~Z
            cout << ch;
        }else if(ch=='('){
            ans.push(ch);
        }else if(ch==')'){
            while(ans.top()!='('){
                cout << ans.top();
                ans.pop();
            }
            ans.pop(); //남은 괄호 제거
        }else{ // +, -, *, /
            if(!ans.empty()) {
                if (ans.top() == '+' || ans.top() == '-' || ans.top() == '*' || ans.top() == '/') {
                    //ch가 pop한 것보다 우선순위가 높음
                    if(priority[ans.top()] < priority[ch]){
                        ans.push(ch);
                    }
                    //ch가 pop한 것과 우선순위가 같음
                    else if (priority[ans.top()] == priority[ch]){
                        cout << ans.top();
                        ans.pop();
                        ans.push(ch);
                    }
                    //ch가 pop한 것보다 우선순위가 낮음
                    else{
                        while(!ans.empty() &&(ans.top() == '+' || ans.top() == '-' || ans.top() == '*' || ans.top() == '/')){
                            cout << ans.top();
                            ans.pop();
                        }
                        ans.push(ch);
                    }
                }
                else ans.push(ch);
            }else{
                ans.push(ch);
            }
        }

        i++;
        if( i == line.size()) break;
    }
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    return 0;
}