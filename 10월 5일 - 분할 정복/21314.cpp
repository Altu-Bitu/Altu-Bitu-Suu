//21314 민겸 수
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string mk;
    cin >> mk;

    string min = "";
    string max = "";

    int i = 0; //min
    while(i<mk.length()){
        if(mk[i]=='M'){
            int m_count = 1;
            while(true){
                if(i==mk.length()-1) break;
                if(mk[i+1]=='K') break;
                m_count++;
                i++;
            }
            //min += to_string((long long)pow(10,(m_count-1))); : 반례 MMMMMMMMMMMMMMMMMMMMMMK
            min += "1";
            m_count--;
            while(m_count--) min += "0";
        }
        else if(mk[i]=='K'){
            min+= to_string(5);
        }
        i++;
    }

    //max
    i = 0;
    while(i<mk.length()){
        if(mk[i]=='M'){
            int m_count = 1;
            while(true){
                if(i!=mk.length()-1){
                    i++;
                }else break;

                if(mk[i]=='K'){
                    break;
                }
                else m_count++;
            }
            if(i==mk.length()-1 && mk[i]=='M'){
                while(m_count--) max += to_string(1);
                break;
            }
            else{
                max += "5";
                while(m_count--) max += "0";
            }
        }
        else if(mk[i]=='K') {
            max += to_string(5);
        }
        i++;

    }
    cout << max << "\n";
    cout << min;
    return 0;
}