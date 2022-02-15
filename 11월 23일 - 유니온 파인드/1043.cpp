//1043 거짓말 게임
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent (int node){
    if(parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp)
        return;

    if(parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }else{
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }


}

int findAnswer(vector<vector<int>> &party, vector<int> &true_people){
    int ans = 0;
    for(int i = 0 ; i < party.size() ; i++){
        for(int j = 0 ; j < party[i].size() ; j++){
            int true_root = -2;
            if(true_people.size()!=0){
                true_root = findParent(true_people[0]);
            }
            if(true_root == findParent(party[i][j])){
                ans--;
                break;
            }
        }
        ans++;
    }

    return ans;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> true_people;
    int N, M, true_count, size, input;
    cin >> N >> M;
    parent.assign(N+1, -1);
    vector<vector<int>> party(M);

    cin >> true_count;
    while(true_count--){
        cin >> input;
        true_people.push_back(input);
    }
    for(int i = 1 ; i < true_people.size() ; i++){
        unionInput(true_people[i-1], true_people[i]);
    }

    for(int i = 0 ; i < M ; i++){
        cin >> size;
        for(int j = 0 ; j < size ; j++){
            int person;
            cin >> person;
            party[i].push_back(person);
        }
    }
    for(int i = 0 ; i < M ; i++){
        for(int j = 1 ; j <party[i].size() ; j++){
            unionInput(party[i][j-1], party[i][j]);
        }
    }


    cout << findAnswer(party, true_people);
    return 0;
}