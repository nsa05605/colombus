//// 문제 풀이

// 필수 문제
// 백준 7569 - 토마토

// 문제 정의
// 3차원 큐브 형태로 구성된 창고에 토마토가 보관되어 있다.
// 여기에 익은 토마토와 익지 않은 토마토가 있는데, 익은 토마토 옆에 있는 익지 않은 토마토는 하루가 지나면 익는다.
// 토마토가 익는 최소 일수를 출력하는 프로그램을 작성하라

// 입력 및 출력
// 첫 줄에는 상자의 크기를 나타내는 가로 M, 세로 N, 높이 H가 주어진다. (2 <= M, N <= 100, 1 <= H <= 100)
// 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다.
// 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸
// 처음부터 모든 토마토가 익어있으면 0, 토마토가 모두 익지 못하는 상황이면 -1을 출력하라

// 문제 풀이
// 우선 최단 거리를 계산하는 문제이므로 BFS로 구성하면 될 것 같고, 기존 2차원을 다루던 것을 3차원으로 생각해주면 되는 문제로 보임


#include <bits/stdc++.h>
using namespace std;

#define MAX 101

int M, N, H;
bool visited[MAX][MAX][MAX] = {false};
int box[MAX][MAX][MAX];

// 이동 가능한 방향이 6개이므로 총 6개의 경우의 수에 대해 작성
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int answer = 0;
queue<tuple<int,int,int>> q;

void BFS()
{
    while(!q.empty())
    {
        tuple<int,int,int> cur = q.front();
        int cur_x = get<0>(cur), cur_y = get<1>(cur), cur_z = get<2>(cur);
        q.pop();
        for (int i = 0; i < 6; i++){
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<2>(cur) + dz[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H && !visited[MAX][MAX][MAX] && box[nx][ny][nz] == 0)
            {
                
                q.push({nx,ny,nz});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> M >> N >> H;
    for (int height = 0; height < H; height++){
        for (int col = 0; col < N; col++){
            for (int row = 0; row < M; row++){
                cin >> box[height][col][row];
                if (box[height][col][row] == 1){q.push({height,col,row});}  // 토마토가 익은 상태이면 큐에 넣음
            }
        }
    }

    BFS();

    int max = 0;
    for (int height = 0; height < H; height++){
        for (int col = 0; col < N; col++){
            for (int row = 0; row < M; row++){
                if (box[row][col][height] == 0){
                    cout << -1 << '\n'; return 0;
                }
                if (max < box[row][col][height]) max = box[row][col][height];
            }
        }
    }

    //최댓값-1 출력
    cout << max-1 << "\n";

    return 0;
}