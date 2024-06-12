//// 문제 풀이

// 필수 문제
// 백준 2178 - 미로 탐색

// 문제 정의
// M x N 크기의 배열로 표현되는 미로
// 1은 이동할 수 있는 칸이고, 0은 이동할 수 없는 칸을 의미함
// (1,1)에서 출발하여 (N,M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 출력하는 프로그램

// 입력
// 첫째 줄에 두 정수 N, M (2 <= N, M <= 100)이 주어진다.
// 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수는 붙여서 주어진다.

// 문제 풀이
// DFS 알고리즘을 사용해서 구현
//  -> 이 부분은 풀다보니 사실 BFS 알고리즘을 사용해서 구현하는 것이 더 적합하다고 생각됨
//  -> 단순히 DFS 방법으로 풀다보니 최단 경로를 아는 방법이 불가능해서 GPT 도움을 받아 완성함
//  -> 방법은 백트래킹 방법을 사용해서 구현함
// 백트래킹은 우선 다 이동하고, 이동하다가 유효하지 않은 순간에는 이전에 방문했던 노드로 돌아가는 것을 의미함
// 시간이 남으면 BFS로 구현도 해보자
// 
// DFS + 백트래킹으로 작성한 코드를 백준에 제출했더니 시간 초과 발생함
// BFS로 구현

#include <bits/stdc++.h>
using namespace std;

#define MAX 101

bool visited[MAX][MAX];
vector<vector<int>> graph(MAX, vector<int>(MAX, 0));
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int N, M;
int min_steps = INT_MAX;

// steps는 DFS() 들어갈 때만 추가되기 때문에, 잘못된 길로 들어갔으면 업데이트 되지 않을 것으로 예상됨..?
void DFS(int cur_x, int cur_y, int steps)
{
    // 현재 위치가 도착지점이면, min_steps를 업데이트 해줌
    if (cur_x == N-1 && cur_y == M-1) {
        min_steps = min(min_steps, steps);
        return;
    }
    visited[cur_x][cur_y] = true;

    for (int i = 0; i < 4; i++){
        int next_x = cur_x + dx[i], next_y = cur_y + dy[i];
        if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !visited[next_x][next_y] && graph[next_x][next_y] == 1){
            DFS(next_x, next_y, steps+1);
        }
    }

    // 재귀 호출이 끝나면, 백트래킹을 위해 visited를 다시 초기화해줌
    visited[cur_x][cur_y] = false;
}

// BFS 코드 공부
int BFS(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    int steps = 0;

    while (!q.empty()) {
        int q_size = q.size();
        steps++;
        for (int i = 0; i < q_size; i++) {
            auto [cur_x, cur_y] = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int next_x = cur_x + dx[j], next_y = cur_y + dy[j];
                if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M &&
                    !visited[next_x][next_y] && graph[next_x][next_y] == 1) {
                    if (next_x == N-1 && next_y == M-1) {
                        return steps + 1;
                    }
                    q.push({next_x, next_y});
                    visited[next_x][next_y] = true;
                }
            }
        }
    }

    return -1; // 도착 지점에 도달할 수 없는 경우
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    char input[MAX];
    for (int i = 0; i < N; i++){
        cin >> input;
        for (int j = 0; j < M; j++){
            graph[i][j] = input[j] - '0';   // 그래프에 int 형태의 0 혹은 1을 넣어줘야 하기 때문에 - '0' 을 해줌
        }
    }
    // DFS(0,0,1);
    // cout  << min_steps << '\n';

    cout << BFS(0,0) << '\n';

    return 0;
}