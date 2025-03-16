// floyd_warshall algorithm - 11404
// O(N^3)

#include <iostream>
#include <vector>

using namespace std;

const int cost_inf = 10000000; // cost_inf를 100001로 잡았었는데, 이는 cost_max값이 100000이기에 만약 두 노드를 지나 갈 경우 100001을 그냥 넘어버릴 수 있다.
                            // 확실하게 큰 수로 설정. 100000*99 = 9900000 보다 커야 함. (간선의 최대 개수 99개, 1노드에서 100노드로 직선에 cost 최대일 경우)
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int node_num, edge_num; cin >> node_num >> edge_num;
    vector<vector<int>> adjVec(node_num, vector<int>(node_num, cost_inf));

    for (int i = 0; i < edge_num; i++){
        int start_node, end_node, cost;
        cin >> start_node >> end_node >> cost;

        if (adjVec[start_node-1][end_node-1] != 0) adjVec[start_node-1][end_node-1] = adjVec[start_node-1][end_node-1] > cost ? cost : adjVec[start_node-1][end_node-1];
        else adjVec[start_node-1][end_node-1] = cost;
    }
    
    for (int i = 0; i < node_num; i++){ // i+1번째 node를 거쳐가는 경우
        for (int j = 0; j < node_num; j++){
            if (i == j) adjVec[i][j] = 0;
            else{
                for (int k = 0; k < node_num; k++){ // j에서 i를 거쳐 k로 가는 경우
                    if ((adjVec[j][i] + adjVec[i][k]) < adjVec[j][k]) adjVec[j][k] = adjVec[j][i] + adjVec[i][k];
                }
            }
        }
    }

    for (vector<int> v : adjVec){
        for (int i : v){
            if (i == cost_inf) i = 0;
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*

5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4

*/