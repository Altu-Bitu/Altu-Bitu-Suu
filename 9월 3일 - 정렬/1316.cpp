//1316 그룹 단어 체커
#include <iostream>

using namespace std;

int main() {
    int n;
    //입력
    cin >> n;
    int count = n;
    for(int i = 0 ; i < n ; i++){
        string word;
        cin >> word;
        //happy
        bool check = true;
        for( int j = 0 ; (j < word.length() - 1) && check ; j++){
            //'h'
            while(word[j]==word[j+1])
                j++;

            for(int k = j+2; k < word.length() ; k++){
                if(word[j]==word[k]){
                    count--;
                    check = false;
                    break;
                }
            }
        }
    }
    cout << count;

    return 0;
}
