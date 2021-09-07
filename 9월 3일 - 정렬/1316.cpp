//1316 그룹 단어 체커
#include <iostream>
#include <vector>

using namespace std;

vector<bool> alpha;

int main() {
    int n;
    //입력
    cin >> n;
    int count = n;
    for(int i = 0 ; i < n ; i++){
        string word;
        cin >> word;
        alpha.assign(26, false);
        //happy
        for( int j = 0 ; j < word.length() ; j++){
            //'h'
            if(word[j]==word[j+1] && j < word.length()-1)
                continue;

            if(alpha[word[j]-'a']==true){
                count--;
                break;
            }
            alpha[word[j]-'a']=true;
        }
    }
    cout << count;

    return 0;
}
