//20302 민트초코
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 100000;

//소수 경로 저장해서 리턴하는 함수
vector<int> isPrime() {
    vector<int> prime(SIZE + 1, 0);

    //먼저 모든 수를 소수라 가정하고, i번째 인덱스에 i값 저장
    for (int i = 2; i <= SIZE; i++)
        prime[i] = i;

    //소수 판별
    for (int i = 2; i <= sqrt(SIZE); i++) {
        if (prime[i] == i) { //소수라면
            for (int j = i * i; j <= SIZE; j += i) { //배수에 소수(i) 저장
                if (prime[j] == j) { //저장된 소수가 없을 경우만
                    prime[j] = i; //소수 저장
                }
            }
        }
    }
    return prime;
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    bool zero = false; // 0 곱했는지 판별
    cin >> n;

    vector<int> prime = isPrime();  //미리 최대 크기까지의 소수 경로 저장
    vector<int> cnt(100001,0);  //소인수 개수 저장
    vector<int> input;  //나누는 수만 모아놓는다.

    //첫번째 수는 따로 뺀다.
    int first;
    cin >> first;
    if (first==0) { //0을 곱했을 경우
        zero = true; n = 1;
    }
    first = abs(first);
    while (first > 1) {
        cnt[prime[first]]++;
        first = first / prime[first];
    }
    n--;

    //연산자 + 숫자
    while (n--) {
        char op;
        cin >> op; // 연산자
        cin >> k; //소인수분해할 수 입력

        //0을 곱했을 경우 따로 체크.
        if(k==0) {
            zero = true;
            break;
        }

        k = abs(k);

        switch (op){
            case '*': //곱하기는 소인수 개수 증가
                while (k > 1) {
                    cnt[prime[k]]++;
                    k = k / prime[k];
                }
                break;
            case '/': //나누기는 소인수 개수 감소시키고 마지막 체크를 위해 input에 추가.
                while (k > 1) {
                    cnt[prime[k]]--;
                    input.push_back(prime[k]);
                    k = k / prime[k];
                }
                break;
        }
    }

    bool mint = true; //민트초코인지 체크
    for(int i = 0 ; i < input.size() ; i++){ //나누는 데 쓰인 소인수들만 체크한다.
        if(cnt[input[i]] < 0){
            mint = false;
            break;
        }
    }

    if(mint || zero) cout << "mint chocolate"; // 0을 곱했거나, 남는 제수가 있을 때
    else cout <<"toothpaste";
    return 0;
}