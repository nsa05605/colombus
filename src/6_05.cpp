//// 문제 풀이

// 필수 문제
// 백준 11725 - 트리의 부모 찾기

// 문제 정의
// 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하라

// 입력 & 출력
// 첫 줄에 노드의 개수 N (2 <= N <= 100,000)
// 둘째 줄부터 N-1 개의 줄에 트리 상에서 연결된 두 정점이 주어진다.
// 첫째 줄부터 N-1 개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

// 문제 풀이
// 1번부터 시작해서 아래로 내려가는 트리 구조를 구성해보자
// 트리 구조의 특성 상 단방향 그래프를 생각하면 될 것 같고
// 예시로 트리 구조를 구성해보면,
//           1
//      4         6
//    7   2     3
//            5
// 그럼 1에서 시작하는 DFS를 생각해보고, 방문 여부를 저장하면서 방문하기 전에 들린 노드를 부모 노드로 저장하고 최종 출력하면 될 듯

#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int N;
vector<vector<int>> tree;       // 트리 구조를 담을 2차원 벡터 초기화
bool visited[MAX];              // 방문 여부를 저장할 배열 초기화
vector<int> parent(MAX, 0);     // 부모 노드를 저장할 벡터 초기화. DFS 함수에서 벡터 내부의 값을 바꾸도록 구성 예정이라 0으로 초기화 함

void DFS(int cur)
{
    visited[cur] = true;

    for (int i = 0; i < tree[cur].size(); i++){
        if (!visited[tree[cur][i]]){        // 새로운 노드에 방문하지 않았으면 == 자식 노드이면 (만약 연결되어 있는데 이미 방문했으면 그건 부모 노드를 의미)
            parent[tree[cur][i]] = cur;     // 자식 노드의 부모는 자신(cur)으로 설정
            DFS(tree[cur][i]);              // DFS 재귀
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int a, b;
    tree.reserve(N+1);                      // 벡터 인덱스가 0부터 시작이므로 N+1 만큼 reserve
    for (int i = 1; i < N; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1);

    for (int i = 2; i <= N; i++){
        cout << parent[i] << '\n';
    }

    return 0;
}