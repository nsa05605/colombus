//// 문제 풀이

// // 필수 문제
// // 백준 1012 - 유기농 배추

// // 문제 정의
// // 배추를 해충으로부터 보호하기 위해 배추흰지렁이를 풀어둠
// // 지렁이는 현재 있는 배추와 인접한 배추(상하좌우)로 이동이 가능함
// // 배추를 지키기 위해 필요한 지렁이의 수를 출력하는 문제

// // 입력
// // 첫 줄에는 테스트 케이스 개수 T
// // 이후 각 케이스에 대해 첫 줄은 가로 세로 길이 M, N 및 배추의 개수 K가 주어진다.
// // 이후 K 줄에는 배추의 위치(0부터 시작)

// // 문제 풀이
// // DFS로 탐색하면서 현재 탐색 가능한 그래프를 모두 탐색하고, 새로운 그래프로 이동하면 cnt++
// // 상하좌우 이동을 다루는 문제이기에 dx, dy를 사용해서 이동하면 될 듯

// // 계산 비용
// // 계산 비용은 명확히 모르겠음. 풀고 알아보자
// // 풀고나서 GPT에게 물어보니 계산 비용은 O(T×(M×N+K)) 라고 함
// // 그래프 초기화: O(M * N)
// // 방문 배열(visited) 초기화: O(M * N)
// // 입력 처리: O(K)
// // DFS 탐색: O(M * N)

// #include <bits/stdc++.h>
// using namespace std;

// #define MAX 51

// bool visited[MAX][MAX];
// int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};   // 상하좌우 이동을 계산해줄 dx, dy
// int N, M, K;

// // 테스트 케이스가 2개 이상인 경우에 graph를 전역변수로 사용하면 초기화가 어려워서 main에 넣고 참조로 불러옴
// void DFS(int cur_x, int cur_y, vector<vector<int>> &graph)
// {
//     visited[cur_x][cur_y] = true;

//     for (int k = 0; k < 4; k++) {
//         // x, y 방향으로(상하좌우로) 이동해서 아래 조건을 충족하면 DFS 재귀
//         int next_x = cur_x + dx[k], next_y = cur_y + dy[k];
//         if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && !visited[next_x][next_y] && graph[next_x][next_y] == 1) {
//             DFS(next_x, next_y, graph);
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int T, x, y;
//     cin >> T;
//     for (int i = 0; i < T; i++){
//         cin >> M >> N >> K;

//         // graph 초기화 및 visited 배열 초기화
//         vector<vector<int>> graph(M, vector<int>(N, 0));
//         memset(visited, 0, sizeof(visited));

//         for (int j = 0; j < K; j++){
//             cin >> x >> y;
//             graph[x][y] = 1;
//         }
        
//         int answer = 0;
//         // graph 전체에 대해 조건을 만족하면 탐색
//         for (int a = 0; a < M; a++){
//             for (int b = 0; b < N; b++){
//                 if (graph[a][b] == 1 && !visited[a][b]){
//                     DFS(a, b, graph);
//                     answer++;
//                 }
//             }
//         }
//         cout << answer << '\n';
//     }

//     return 0;
// }



// 도전 문제
// 백준 7576 - 토마토

// 문제 정의
// 격자 모양의 상자의 칸에 토마토가 담겨 있음
// 익은 토마토 주변(상하좌우)의 토마토들은 하루가 지나면 익게 됨
// 토마토가 익는 최소 일수를 출력하라

// 입력
// 첫 줄에는 상자의 크기를 나타내는 두 정수 M(가로), N(세로) (2 <= M, N <= 1000)
// 둘째 줄부터는 상자에 담긴 토마토의 정보
// 1은 익은 토마토, 0은 익지 않은 토마토, -1은 빈 칸

// 문제 풀이
// 일단 주변으로 한 칸씩 이동하는데 최소 일수를 찾아야 하므로, BFS로 찾는 것이 맞을 듯한데,
// 또 결국 하나씩 이동하면서 가장 멀리 있는 칸까지 가야하므로 DFS로 해도 될 것 같기도 하고
// DFS로 생각해보니 어디가 마지막인지 검사하기가 어려울 듯 싶음. 그래서 BFS로 구현
// 하나의 섬이 아닌 경우에는 그냥 -1 출력하면 될 듯 하고

// 풀이하다보니 계속 오류가 발생해서 구글 참고해서 진행함

#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int M, N;
int answer = 0;
int box[MAX][MAX];
queue<pair<int,int>> q;

void BFS()
{
    while(!q.empty()){
        int cur_x = q.front().second, cur_y = q.front().first; q.pop();
        for (int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i], next_y = cur_y + dy[i];
            if(next_x >= 0 && next_y >= 0 && next_x < M && next_y < N && box[next_y][next_x] == 0)
            {
                box[next_y][next_x] = box[cur_y][cur_x] + 1;
                q.push({next_y, next_x});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> box[i][j];
            if (box[i][j] == 1) q.push({i,j});  // 토마토가 익은 상태이면, 큐에 넣어놓음
        }
    }

    BFS();

    int max = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            //안 익은 토마토가 존재할 경우
            if(box[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            //최댓값 계산
            if(max < box[i][j]) max = box[i][j];
        }
    }

    //최댓값-1 출력
    cout << max-1 << "\n";

    return 0;
}