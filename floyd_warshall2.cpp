// floyd_warshall algorithm - 11780

#include <iostream>
#include <vector>

using namespace std;

const int inf = 999999999;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int node_num, edge_num; cin >> node_num >> edge_num;
    vector<vector<int>> adjArr(node_num, vector<int>(node_num, inf));
    vector<vector<string>> ansArr(node_num, vector<string>(node_num));

    for (int i = 0; i < ansArr.size(); i++){
        for (int j = 0; j < ansArr[i].size(); j++){
            if(i==j) ansArr[i][j] = "0";
            else ansArr[i][j] += to_string(i+1);
        }
    }

    for (int i = 0; i < edge_num; i++){
        int start_node, end_node, cost; cin >> start_node >> end_node >> cost;
        if (adjArr[start_node-1][end_node-1] >= cost){
            adjArr[start_node-1][end_node-1] = cost;
            ansArr[start_node-1][end_node-1] += " " + to_string(end_node);
        }
    }

    for (int i = 0; i < node_num; i++){
        for (int j = 0; j < node_num; j++){
            if (i == j) adjArr[i][j] = 0;
            else{
                for (int k = 0; k < node_num; k++){ 
                    if (((adjArr[j][i] + adjArr[i][k]) < adjArr[j][k]) && (j != k)){
                        adjArr[j][k] = adjArr[j][i] + adjArr[i][k];
                        ansArr[j][k] = ansArr[j][i].substr(0, ansArr[j][i].size()-to_string(i+1).size()) + ansArr[i][k];
                    }
                }
            }
        }
    }

    for (vector<int> v : adjArr){
        for (int i : v){
            if (i == inf) i = 0;
            cout << i << " ";
        }
        cout << "\n";
    }

    for (vector<string> v : ansArr){
        for (string s : v){
            if (s == "0") cout << "0";
            else{
                int count = 1;
                for (char c : s){
                    if (c == ' ') count++;
                }
                
                if (count == 1) cout << "0";
                else cout << to_string(count) << " " << s;
            }
            cout << "\n";
        }
    }

    return 0;
}


/*

0
2 1 2
2 1 3
2 1 4
3 1 3 5
4 2 4 5 1

0
5 2 4 5 1 3
2 2 4
3 2 4 5
2 3 1
3 3 5 2
0
2 3 4
2 3 5
3 4 5 1
3 4 5 2
4 4 5 1 3
0
2 4 5
2 5 1
2 5 2
3 5 1 3
3 5 2 4
0

*/