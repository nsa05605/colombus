//// 문제 풀이

// 필수 문제
// 백준 1012 - 유기농 배추

// 문제 정의
// 배추를 해충으로부터 보호하기 위해 배추흰지렁이를 풀어둠
// 지렁이는 현재 있는 배추와 인접한 배추(상하좌우)로 이동이 가능함
// 배추를 지키기 위해 필요한 지렁이의 수를 출력하는 문제

// 입력
// 첫 줄에는 테스트 케이스 개수 T
// 이후 각 케이스에 대해 첫 줄은 가로 세로 길이 M, N 및 배추의 개수 K가 주어진다.
// 이후 K 줄에는 배추의 위치(0부터 시작)

// 문제 풀이
// DFS로 탐색하면서 현재 탐색 가능한 그래프를 모두 탐색하고, 새로운 그래프로 이동하면 cnt++
// 상하좌우 이동을 다루는 문제이기에 dx, dy를 사용해서 이동하면 될 듯

// 계산 비용
// 계산 비용은 명확히 모르겠음. 풀고 알아보자
// 풀고나서 GPT에게 물어보니 계산 비용은 O(T×(M×N+K)) 라고 함
// 그래프 초기화: O(M * N)
// 방문 배열(visited) 초기화: O(M * N)
// 입력 처리: O(K)
// DFS 탐색: O(M * N)

#include <bits/stdc++.h>
using namespace std;

#define MAX 51

bool visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};   // 상하좌우 이동을 계산해줄 dx, dy
int N, M, K;

// 테스트 케이스가 2개 이상인 경우에 graph를 전역변수로 사용하면 초기화가 어려워서 main에 넣고 참조로 불러옴
void DFS(int cur_x, int cur_y, vector<vector<int>> &graph)
{
    visited[cur_x][cur_y] = true;

    for (int k = 0; k < 4; k++) {
        // x, y 방향으로(상하좌우로) 이동해서 아래 조건을 충족하면 DFS 재귀
        int next_x = cur_x + dx[k], next_y = cur_y + dy[k];
        if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && !visited[next_x][next_y] && graph[next_x][next_y] == 1) {
            DFS(next_x, next_y, graph);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, x, y;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> M >> N >> K;

        // graph 초기화 및 visited 배열 초기화
        vector<vector<int>> graph(M, vector<int>(N, 0));
        memset(visited, 0, sizeof(visited));

        for (int j = 0; j < K; j++){
            cin >> x >> y;
            graph[x][y] = 1;
        }
        
        int answer = 0;
        // graph 전체에 대해 조건을 만족하면 탐색
        for (int a = 0; a < M; a++){
            for (int b = 0; b < N; b++){
                if (graph[a][b] == 1 && !visited[a][b]){
                    DFS(a, b, graph);
                    answer++;
                }
            }
        }
        cout << answer << '\n';
    }

    return 0;
}