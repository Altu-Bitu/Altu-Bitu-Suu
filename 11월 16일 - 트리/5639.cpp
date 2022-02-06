//5639 이진 검색 트리

#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;

void postorder(int idx, int left, int right) {
    if(left > right){
        return;
    }

    int node = preorder[idx];
    int right_node = right + 1;
    for(int j = left ; j <= right ; j++){
        if(preorder[j] > node){
            right_node = j;
            break;
        }
    }

    postorder(idx+1, idx+1, right_node - 1);
    postorder(right_node, right_node, right);
    cout << node << "\n";

}

int main () {
    int num;
    while(cin >> num){
        //if(num==-1) break; // 제출시 주석처리 (디버깅용)
        preorder.push_back(num);
    }

    postorder(0, 0, preorder.size()-1);


    return 0;
}