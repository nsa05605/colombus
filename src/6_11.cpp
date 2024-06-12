//// 문제 풀이

// // 필수 문제
// // 백준 7569 - 토마토

// // 문제 정의
// // 3차원 큐브 형태로 구성된 창고에 토마토가 보관되어 있다.
// // 여기에 익은 토마토와 익지 않은 토마토가 있는데, 익은 토마토 옆에 있는 익지 않은 토마토는 하루가 지나면 익는다.
// // 토마토가 익는 최소 일수를 출력하는 프로그램을 작성하라

// // 입력 및 출력
// // 첫 줄에는 상자의 크기를 나타내는 가로 M, 세로 N, 높이 H가 주어진다. (2 <= M, N <= 100, 1 <= H <= 100)
// // 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다.
// // 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸
// // 처음부터 모든 토마토가 익어있으면 0, 토마토가 모두 익지 못하는 상황이면 -1을 출력하라

// // 문제 풀이
// // 우선 최단 거리를 계산하는 문제이므로 BFS로 구성하면 될 것 같고, 기존 2차원을 다루던 것을 3차원으로 생각해주면 되는 문제로 보임


// #include <bits/stdc++.h>
// using namespace std;

// #define MAX 101

// int M, N, H;
// bool visited[MAX][MAX][MAX] = {false};
// int box[MAX][MAX][MAX];

// // 이동 가능한 방향이 6개이므로 총 6개의 경우의 수에 대해 작성
// int dx[6] = {1, 0, 0, -1, 0, 0};
// int dy[6] = {0, 1, 0, 0, -1, 0};
// int dz[6] = {0, 0, 1, 0, 0, -1};

// int answer = 0;
// queue<tuple<int,int,int>> q;    // 높이, 행, 열 총 3개를 넣을 튜플이 필요함

// void BFS()
// {
//     while(!q.empty())
//     {
//         tuple<int,int,int> cur = q.front();
//         int cur_x = get<2>(cur), cur_y = get<1>(cur), cur_z = get<0>(cur);
//         q.pop();
//         for (int i = 0; i < 6; i++){
//             int nx = get<2>(cur) + dx[i];
//             int ny = get<1>(cur) + dy[i];
//             int nz = get<0>(cur) + dz[i];
//             if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H && !visited[nz][ny][nx] && box[nz][ny][nx] == 0)
//             {
//                 q.push({nz,ny,nx}); visited[nz][ny][nx] = true; box[nz][ny][nx] = box[cur_z][cur_y][cur_x]+1;   // 이전 방문한 곳보다 숫자를 ++
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0); cin.tie(0);

//     cin >> M >> N >> H;
    
//     // 이때 for문을 밖에서부터 height, row, col 로 구성하는 것이 중요함
//     for (int height = 0; height < H; height++){
//         for (int row = 0; row < N; row++){
//             for (int col = 0; col < M; col++){
//                 cin >> box[height][row][col];
//                 if (box[height][row][col] == 1){q.push({height,row,col});}  // 토마토가 익은 상태이면 큐에 넣음
//             }
//         }
//     }

//     BFS();

//     int max = 0;
//     for (int height = 0; height < H; height++){
//         for (int row = 0; row < N; row++){
//             for (int col = 0; col < M; col++){
//                 if (box[height][row][col] == 0){    // BFS 탐색을 다 했는데, 여전히 익지 않은 토마토가 있으면 -1 출력
//                     cout << -1 << '\n'; return 0;
//                 }
//                 if (max < box[height][row][col]) max = box[height][row][col];   // 하나씩 탐색하면서 최대값을 갱신
//             }
//         }
//     }

//     //최댓값-1 출력
//     cout << max-1 << "\n";

//     return 0;
// }




// 추천 문제
// 백준 13023 - ABCDE

// 문제 정의
// 총 N명이 있고, 각각 0~N-1까지 번호가 매겨짐
// 아래와 같은 친구 관계를 가진 사람 A,B,C,D,E가 존재하는지 구하는 문제
// A<->B / B<->C / C<->D / D<->E

// 입력 및 출력
// 첫째 줄에 사람의 수 N (5 <= N <= 2000)과 친구 관계의 수 M (1 <= M <= 2000)이 주어진다.
// 둘째 줄부터 정수 a와 b가 주어지며, 이는 a와 b가 친구라는 의미
// 문제의 조건에 맞는 A,B,C,D,E가 존재하면 1, 아니면 0을 출력

// 문제 풀이
// DFS 알고리즘으로 풀면 될 것 같음
// 어느 한 노드에서 시작해서 연속으로 4개의 관계가 나오면 되는건가?


#include <bits/stdc++.h>
using namespace std;

#define MAX 2001

int N, M;

bool visited[MAX];
vector<vector<int>> Person(MAX);

bool answer;

bool DFS(int cur, int cnt)
{
    if (cnt >= 4){return true;}

    visited[cur] = true;
    for (int next : Person[cur]){
        if (!visited[next]){
            if (DFS(next, cnt+1)){return true;}
        }
    }
    visited[cur] = false;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        Person[a].push_back(b);
        Person[b].push_back(a);
    }

    for (int i = 0; i < N; i++){
        fill(visited, visited + N, false);
        if (DFS(i, 0)) {
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';

    return 0;
}