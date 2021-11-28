//19637 IF문 좀 대신 써줘
#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, string> title;
int N, M;
vector<int> arr;

//lower bound
string lowerBound(int left, int right, int target) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값
        if (arr[mid] >= target){ //중간값이 target보다 크다면 target은 왼쪽에 있음
            right = mid - 1;
        }
        if (arr[mid] < target)
            left = mid + 1;
    }
    return title[arr[right+1]];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    string name;
    int power;
    arr.push_back(0);
    while(N--){
        cin >> name >> power;
        if (!title[power].empty()) continue;
        title[power] = name;
        arr.push_back(power);
    }

    title[0] = title[arr[1]];
    while(M--){
        int target;
        cin >> target;
        cout << lowerBound(0, arr.size()-1, target) <<"\n";

    }
    return 0;
}