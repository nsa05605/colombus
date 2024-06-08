//// 문제 풀이

// // 필수 문제
// // 백준 14940 - 쉬운 최단거리

// // 문제 정의
// // 지도가 주어지면 모든 지점에 대해서 목표지점까지의 최단 거리를 구하라

// // 입력 및 출력
// // 지도의 크기 n과 m이 주어진다. (2 <= n, m <= 1000)
// // 다음 n개의 줄에 m개의 숫자가 주어진다. (0은 갈 수 없는 땅, 1은 갈 수 있는 땅, 2는 목표 지점)
// // 각 지점에서 목표지점까지의 거리를 출력. 갈 수 없으면 -1

// // 문제 풀이
// // 목표 지점(2)에서 나머지 위치까지의 거리를 BFS로 구하면 될 듯

// #include <bits/stdc++.h>
// using namespace std;

// #define MAX 1001

// vector<vector<int>> graph(MAX, vector<int>(MAX, 0));
// bool visited[MAX][MAX];
// int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

// int n, m;
// vector<vector<int>> answer(MAX, vector<int>(MAX, -1));  // 최단 경로를 담을 벡터. 기본적으로 -1로 초기화

// void BFS(int x, int y)
// {
//     visited[x][y] = true;
//     queue<pair<int,int>> q; // (x,y) 좌표를 담을 것이기 때문에 pair<int,int> 형식으로 초기화
//     q.push({x,y});
//     answer[x][y] = 0;   // 시작 지점 == 목표 지점이므로 0으로 초기화

//     while(!q.empty())
//     {   
//         // 현재 탐색할 노드를 큐에서 꺼내옴
//         int cur_x = q.front().first, cur_y = q.front().second;
//         for(int i = 0; i < 4; i++){
//             int nx = cur_x + dx[i], ny = cur_y + dy[i];

//             // graph[nx][ny]==1 이라는 조건을 넣지 않은 이유는 0인 경우에는 0으로 설정해주기 위함
//             if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && graph[nx][ny]==1) 
//             {
//                 // // 원래 0이면 answer에도 0을 넣어주고 넘김
//                 // if (graph[nx][ny] == 0){answer[nx][ny] = 0; continue;}
//                 // 기존 BFS 구조. 큐에 다음 노드 담고, 방문 처리. 여기에 answer만 이전꺼보다 하나 더해줌
//                 q.push({nx,ny}); visited[nx][ny]=true; answer[nx][ny]=answer[cur_x][cur_y]+1;
//             }
//         }
//         q.pop();
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> m;
//     pair<int, int> target;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cin >> graph[i][j];
//             // 처음에 target을 따로 설정하지 않고 BFS 시작 지점을 그냥 (0,0)으로 제출했더니 오답 발생하여 target으로 시작 지점 생성
//             if(graph[i][j]==2){target = {i,j};}
//             // 노드의 값이 0인 순간에 대해 여기에서 바로 answer를 업데이트 해줌
//             if(graph[i][j]==0){answer[i][j] = 0;}
//         }
//     }

//     BFS(target.first, target.second);

//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cout << answer[i][j] << ' ';
//         }
//         cout << '\n';
//     }

//     return 0;
// }



// 도전 문제
// 백준 12851 - 숨바꼭질 2

// 문제 정의
// 수빈이의 위치(N)와 동생의 위치(K)가 주어진다. (0 <= N, K <= 100,000)
// 수빈이가 움직일 수 있는 방법은 총 2개
//   1. 걷기 : x-1 혹은 x+1
//   2. 순간이동 : 2*x
// 수빈이와 동생의 위치가 주어졌을 때, 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고, 가장 빠른 시간으로 찾는 방법이 몇 가지인지 구하는 프로그램을 작성하라

// 입력
// 첫 줄에 수빈이의 위치 N과 동생의 위치 K가 주어진다.
// 출력
// 첫째 줄에는 수빈이가 동생을 찾는 가장 빠른 시간
// 둘째 줄에는 가장 빠른 시간으로 찾는 방법의 수를 출력

// 문제 풀이
// 최단 경로를 찾는 문제이므로 BFS 방법이 필요하지 않을까 싶고
// 이동하는 방법을 x-1, x+1, x*2 로 설정해서 움직여봐야 할 것 같음

#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

vector<int> graph(MAX, 0);
int N, K;
bool first = true;  // 처음으로 위치가 같은지
int visited[MAX] = {0};
int answer = MAX;
int num_of_answer = 0;

void BFS(int start, int time)
{
    queue<pair<int,int>> q;
    q.push({start, time});
    visited[start] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        visited[x] = true;
        // 첫 방식과 다른 방식으로 도달한 방법에 대해 위치가 같고, 걸린 시간도 같으면 정답 개수++
        if (!first && answer == cnt && x == K) {num_of_answer++;}
        
        // 처음으로 정답에 도달한 경우
        if (first && x == K){
            answer = cnt;       // 최소 시간 저장하고
            first = false;      // 처음 방문 여부는 false로 바꿔주고
            num_of_answer++;    // 정답 개수++
        }

        if (x+1 < MAX && !visited[x+1]){    // 걷기 +1
            q.push({x+1, cnt+1});
        }
        if (x-1 >= 0 && !visited[x-1]){     // 걷기 -1
            q.push({x-1, cnt+1});
        }
        if (2*x < MAX && !visited[2*x]){
            q.push({2*x, cnt+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    BFS(N, 0);
    cout << answer << '\n';
    cout << num_of_answer << '\n';

    return 0;
}