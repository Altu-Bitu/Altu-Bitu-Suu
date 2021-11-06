//2343 기타 레슨
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int N, M;

int upperBound(int left, int right) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값

        int sum = 0, count = 1;
        for(int i = 0 ; i < arr.size() ; i++){
            sum += arr[i];
            if(sum > mid) {
                sum = arr[i];
                count++;
            }
        }
        if (count > M) // 블루레이 크기를 늘린다
            left = mid + 1;
        if (count <= M) // 블루레이 크기를 줄인다
            right = mid - 1;
    }
    return right + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int max = 0;
    int min = 0;
    while(N--){
        int lecture;
        cin >> lecture;
        max += lecture;
        if(min < lecture)
            min = lecture;
        arr.push_back(lecture);
    }
    //강의 순서가 바뀌면 안되므로 sort하면 안됨

    cout << upperBound(min, max);
    return 0;
}
