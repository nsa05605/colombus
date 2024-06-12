//// 문제 풀이


// 필수 문제
// 백준 2606 - 바이러스

// 문제 정의
// 한 컴퓨터가 바이러스에 걸리면 그 컴퓨터와 연결된 모든 컴퓨터는 바이러스에 걸린다.
// 컴퓨터의 수와 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터가 바이러스에 걸렸을 때 바이러스가 걸리는 컴퓨터의 수를 출력하라

// 입력
// 첫째 줄에는 컴퓨터의 수, 둘째 줄에는 연결의 개수
// 이후 연결 정보

// 문제 풀이
// 1. 방법론 생각
// 먼저 문제에서 "연결" 정보가 나왔기 때문에 그래프 알고리즘으로 해결 가능하다고 생각됨
// 이러한 이유로 DFS, BFS 알고리즘으로 풀이가 가능할 것 같다고 생각함.
// 
// 2. 계산 비용 생각
// 계산 비용은 DFS, BFS의 계산 비용으로 생각하면 O(N^2)인가? 찾아보자
// GPT에 물어본 결과로는 시간 복잡도는 O(V+E). 이때 V는 노드의 개수, E는 엣지의 개수
// 
// 3. DFS 구현
// DFS는 일반적으로 "스택" 혹은 "재귀" 방법으로 구현함
// 여기에서는 재귀로 구현을 진행
// 구현을 위해 필요한 작업으로는 우선
// 1. 그래프 생성 : 이중 벡터로 연결 관계 저장
// 2. 방문 여부를 검사할 배열(벡터) visited 초기화
// 3. 재귀를 통해 DFS 실행
// 4. visited==true인 경우의 수를 출력(cnt 등의 변수로 관리)
//
// 4. BFS 구현
// BFS는 큐(Queue)를 사용한 방법으로 구현함
// 구현을 위해 필요한 작업으로는 우선
// 1. DFS의 1-2번은 동일
// 2. 구현하면서 알아보자



#include <bits/stdc++.h>
using namespace std;

#define MAX 101     // 컴퓨터의 최대 개수가 100이므로 최대값은 101로 정의

vector<vector<int>> graph;      // 연결 관계를 저장할 그래프
bool visited[MAX] = {false};    // 방문 정보를 저장할 배열
int n_computers, n_edges;       // 전체 컴퓨터의 개수와 엣지의 개수를 입력받기 위한 변수
int cnt = 0;

vector<vector<int>> g(MAX, vector<int>(MAX, 0));

void DFS(int cur)
{
    visited[cur] = true;    // 현재 노드 방문처리

    for (int i = 0; i < graph[cur].size(); i++){
        int next = graph[cur][i];   // 다음에 방문할 노드(현재 노드와 연결된 노드)
        if (!visited[next]) {       // 해당 노드를 이미 방문했으면 넘김
            cnt++;                  // 감염된(=방문한) 컴퓨터의 수를 증가
            DFS(next);              // 재귀
        }
    }
}

void BFS(int cur)
{
    visited[cur] = true;    // 현재 노드 방문처리

    queue<int> Q;
    Q.push(cur);            // 큐에 시작 노드 삽입
    while(!Q.empty())       // 큐가 비는 순간까지 진행
    {
        for (int i = 0; i < graph[Q.front()].size(); i++){  // 큐에 담긴 맨 앞(front) 노드부터 진행
            int next = graph[Q.front()][i];
            if (!visited[next]){
                Q.push(next); visited[next] = true; cnt++;  // 방문하지 않은 노드를 큐에 넣고, 방문처리 및 cnt 증가
            }
        }
        Q.pop();    // 현재 진행한 노드(상위 노드) 삭제
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n_computers >> n_edges;
    int x, y;
    graph.reserve(n_computers+1);       // +1을 해준 이유는 벡터의 인덱스가 0부터 시작하므로
    for (int i = 0; i < n_edges; i++){
        cin >> x >> y;
        graph[x].push_back(y);  graph[y].push_back(x);  // 그래프에 연결 관계 넣어주기
    }

    // DFS(1);
    BFS(1);
    cout << cnt << '\n';

    return 0;
}



// // 도전 문제
// // 백준 1325 - 효율적인 해킹

// // 문제 정의
// // 필수 문제와 마찬가지로 컴퓨터 하나를 해킹하면 연결된 컴퓨터를 해킹할 수 있다는 문제
// // 다만 여기서는 신뢰라는 조건을 추가했는데, 이는 A->B 는 가능하지만 B->A 는 불가능하다는 것을 의미함

// // 입력
// // 첫째 줄에 N과 M이 입력됨(1 <= N <= 10,000, 1 <= M <= 100,000)
// // 둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B 의 형식으로 들어오고, 이는 A가 B를 신뢰한다는 것을 의미함
// // 컴퓨터는 1번부터 N번까지 존재함

// // 문제 풀이
// // DFS로 접근하면 될 것 같음
// // 그리고 그래프는 단방향 그래프로 만들어줘야함
// // 그리고 한 번에 해킹할 수 있는 컴퓨터가 가장 많은 컴퓨터를 오름차순으로 출력한다는데 그러면 각 숫자에 해당하는 해킹 가능한 개수도 저장해두고, 나중에 정렬까지 진행해야 함
// // 



// #include <bits/stdc++.h>
// using namespace std;

// #define MAX 10001

// vector<vector<int>> graph;
// bool visited[MAX] = {false};
// int N, M;
// vector<int> answer(MAX, 0);

// void DFS(int cur)
// {
//     visited[cur] = true;

//     for (int i = 0; i < graph[cur].size(); i++){
//         int next = graph[cur][i];
//     }

// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N >> M;
//     graph.reserve(MAX);
//     int x, y;
//     for (int i = 0; i < M; i++){
//         cin >> x >> y;
//         graph[y].push_back(x);      // 이번 문제는 단방향 그래프이기 때문에, graph[y]에만 x를 넣어줌
//     }

//     for (int i = 1; i <= graph.size(); i++){
//         DFS(i);
//     }
    


//     return 0;
// }