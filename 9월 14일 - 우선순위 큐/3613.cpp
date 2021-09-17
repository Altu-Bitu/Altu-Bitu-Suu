//3613 Java vs C++
#include <iostream>

using namespace std;

char change(char ch){ //대문자 <-> 소문자
    if(isupper(ch)) return tolower(ch);
    else return toupper(ch);
}

int main(){
    string answer = "";
    string input;
    cin >> input;
    bool error = false;
    bool isC = false, isJava = false;

    if(isupper(input[0]) || input[0]=='_') error = true; //첫글자가 대문자거나 _면 에러.

    answer+= input[0];
    for(int i = 1 ; i < input.size() ; i++){
        // java인데 언더바가 나오거나 c++인데 대문자가 나오면 에러.
        if(input[i]=='_') isC=true;
        if(isupper(input[i])) isJava=true;

        //c++ 형식
        if(input[i]=='_' && i!=input.size()-1){
            if(isupper(input[i+1])) isJava=true; //c++인데 대문자가 나오면 에러.
            if(input[i+1]=='_') error= true; // _가 연속으로 나오면 에러.
            answer+=change(input[i+1]);
            i++;
        }//java 형식
        else if(isupper(input[i])){
            answer+='_';
            answer+=change(input[i]);
        }else{ //소문자는 그냥 들어감
            answer+=input[i];
        }
    }
    if(input[input.size()-1]=='_') error = true; //마지막이 _ 면 에러.
    if(isC && isJava) error=true; //c++이자 java이면 에러.

    if(error){
        cout << "Error!";
    }else cout << answer;
    return 0;
}
