//// 문제 풀이

// 필수 문제
// 백준 7562 - 나이트의 이동

// 문제 정의
// 체스판 위에서 나이트가 이동을 한다.
// 나이트 이동 범위는 +- (1,2) 혹은 (2,1)로 총 8곳
// 나이트가 몇 번 움직이면 마지막 칸으로 이동할 수 있을지 계산하는 문제

// 입력
// 첫째 줄에는 테스트 케이스의 개수
// 각 테스트 케이스에서 첫 줄은 한 변의 길이 l (4 <= l <= 300)
// 둘째 줄과 셋째 줄에는 나이트의 위치와 이동하려는 위치

// 문제 풀이
// 우선 최단 거리를 출력하는 문제기 때문에 BFS 방법으로 계산하면 되고,
// 기존에 dx, dy 구성한 것을 조금 다르게 구성하면 될 듯


#include <bits/stdc++.h>
using namespace std;

#define MAX 301

int test_case, l;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool visited[MAX][MAX];
int board[MAX][MAX];

void BFS(int cx, int cy, int tx, int ty)
{
    queue<pair<int,int>> q;
    q.push({cx,cy});
    visited[cx][cy] = true;

    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < l && ny < l && !visited[nx][ny]){
                q.push({nx,ny}); visited[nx][ny] = true; board[nx][ny] = board[x][y] + 1;   // 현재까지 지나오면서 걸린 거리는 이전 거리 +1
                if (nx == tx && ny == ty){  // 목표 지점에 도착하면 종료
                    return;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> test_case;
    for (int i = 0; i < test_case; i++){
        cin >> l;    // 한 변의 길이 입력
        int cx, cy; cin >> cx >> cy;    // 현재 위치 입력
        int tx, ty; cin >> tx >> ty;    // 목표 위치 입력

        // 방문 배열과 보드 다시 초기화
        memset(visited, false, sizeof(visited));
        memset(board, 0, sizeof(board));

        BFS(cx, cy, tx, ty);
        cout << board[tx][ty] << '\n'; 
    }

    return 0;
}