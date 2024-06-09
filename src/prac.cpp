#include <bits/stdc++.h>
using namespace std;
#define MAX 101

// // 1주차 재귀 & 브루트포스

// int fibo(int n)
// {
//     if (n < 2) {return n;}
//     else {
//         return fibo(n-2) + fibo(n-1);
//     }
// }

// int main()
// {
//     cout << fibo(10) << '\n';
// }


// 2/3주차(그래프 탐색)

// 기존 그래프
// num of vertex(nodes)
int N = 6;
// Edges = {u, v}
vector<pair<int,int>> g = {{1,2},{2,6},{2,4},{4,3},{3,2},{3,5}};

// 인접 행렬
vector<vector<int>> matrix(N, vector<int>(N, 0));   // 행렬을 2차원 벡터로 초기화

// 인접 리스트
vector<vector<int>> graph(N+1);

int main()
{    
    // 인접 리스트

    for (int i = 0; i < g.size(); i++){
        matrix[g[i].first-1][g[i].second-1] = 1;
        matrix[g[i].second-1][g[i].first-1] = 1;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }


    // 인접 리스트

    for (int i = 0; i < g.size(); i++){
        graph[g[i].first].push_back(g[i].second);
        graph[g[i].second].push_back(g[i].first);
    }

    for (int i = 1; i <= N; i++){
        cout << i << " : ";
        for (int j = 0; j < graph[i].size(); j++){
        cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}