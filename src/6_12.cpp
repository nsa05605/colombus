//// 문제 풀이

// 필수 문제
// 백준 16234 - 인구 이동

// 문제 정의
// N x N 크기의 땅이 있고, 땅은 1 x 1 개의 칸으로 나누어져 있다.
// 각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c] 명이 살고 있다.
// 모든 나라는 1 x 1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.
// 인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 방법에 의해 인구 이동이 없을 때까지 지속된다.
// 규칙 1. 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
// 규칙 2. 위의 조건에 의해 열려야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
// 규칙 3. 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으며, 그 나라를 오늘 하루 동안은 연합이라고 한다.
// 규칙 4. 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수)/(연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
// 규칙 5. 연합을 해체하고, 모든 국경선을 닫는다.
// 각 나라의 인구 수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하라.

// 입력
// 첫째 줄에 N, L, R이 주어진다. (1 <= N <= 50, 1 <= L <= R <= 100)
// 둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 <= A[r][c] <= 100)
// 인구 이동이 발생하는 일수가 2000번 보다 작거나 같은 입력만 주어진다.

// 문제 풀이
// 섬찾기를 하고, 각 섬에 대해 인구수를 평균치로 맞추기
// 이 과정을 반복하면서 step을 쌓아가고,
// 더 이상 갈 곳이 없다면, 종료
// 섬에 해당하는 국가의 인덱스(r,c)와 인구수(A[r][c])를 담을 벡터를 하나 만들어야 할 것 같음


#include <bits/stdc++.h>
using namespace std;

#define MAX_N 51
#define MAX_PEOPLE 101

int N, L, R;
bool visited[MAX_N][MAX_N];
vector<vector<int>> A(MAX_PEOPLE, vector<int>(MAX_PEOPLE));
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

vector<pair<int,int>> team;

void DFS(int cy, int cx)
{
    visited[cy][cx] = true;
    team.push_back({cy, cx});

    for (int i = 0; i < 4; i++){
        int ny = cy + dy[i], nx = cx + dx[i];
        // 여기에 조건으로 기존 DFS의 조건 외에 A[r][c] 간의 차이가 L보다 크고 R보다 작다 등의 조건도 포함되어야 함
        if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[ny][nx]){
            int diff = abs(A[cy][cx] - A[ny][nx]);
            if (diff >= L && diff <= R){
                DFS(ny, nx);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    for (int r = 0; r < N; r++){       // row(y)
        for (int c = 0; c < N; c++){   // col(x)
            cin >> A[r][c];
        }
    }

    int cnt = 0;
    bool moved = true;
    
    while(moved)
    {
        moved = false;
        memset(visited, false, sizeof(visited));
        for (int r = 0; r < N; r++){
            for (int c = 0; c < N; c++){
                if (!visited[r][c]){
                    team.clear();
                    DFS(r, c);
                    
                    if (team.size() > 1) {
                        moved = true;
                        int sum = 0;
                        for (auto &k : team){
                            sum += A[k.first][k.second];
                        }
                        int newPopulation = sum / team.size();
                        for (auto &k : team){
                            A[k.first][k.second] = newPopulation;
                        }
                    }
                }
            }
        }
        if (moved) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}