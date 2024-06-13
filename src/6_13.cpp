//// 문제 풀이

// 필수 문제
// 백준 1991 - 트리 순회

// 문제 정의
// 이진 트리를 입력받아 전위 순회, 중위 순회, 후위 순회한 결과를 출력하는 프로그램을 작성하라

// 입력
// 첫째 줄에는 이진 트리의 노드의 개수 N (1 <= N <= 26)이 주어진다.
// 둘째 줄부터 N개의 줄에 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.
// A는 루트 노드이며, 각 노드 이름은 대문자로 주어지고, 자식이 없으면 . 으로 표현

// 문제 풀이
// 트리구조이므로 인접 그래프로 만들어야하고, 이차원 벡터로 구성하자
// 각 순회에 대한 정의를 아직 확실히 몰라서 찾아보고 문제 풀이 시작
// 전위 순회 : 루트부터 시작해서 왼쪽 노드부터 DFS
// 중위 순회 : 왼쪽 리프 노드부터 시작해서 왼쪽자식 -> 부모 -> 오른쪽자식 순서로 순회
// 후위 순회 : 왼쪽 리프 노드부터 시작해서 왼쪽자식 -> 오른쪽자식(자식이 더 있다면 더 내려감) -> 부모
//
// 트리 탐색은 익숙하지 않기도하고 해서 인터넷 풀이 참고함
// 간단하게 풀었는데, 배열을 pair<char,char> node[MAX]만 만들어서 진행함
// 각 순회를 재귀를 통해 수행하는데, 출력하는 부분만 바꿔서 진행함

#include <bits/stdc++.h>
using namespace std;

#define MAX 27

pair<char, char> node[MAX];
int N;

// 전위 순회
void PreOrder(char cur){
    if (cur == '.') return;

    cout << cur;
    PreOrder(node[cur-'A'].first);
    PreOrder(node[cur-'A'].second);
}

// 중위 순회
void InOrder(char cur)
{
    if (cur == '.') return;

    InOrder(node[cur-'A'].first);
    cout << cur;
    InOrder(node[cur-'A'].second);
}

// 후위 순회
void PostOrder(char cur)
{
    if (cur == '.') return;

    PostOrder(node[cur-'A'].first);
    PostOrder(node[cur-'A'].second);
    cout << cur;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++){
        char P, L, R;
        cin >> P >> L >> R;
        node[P-'A'].first = L;
        node[P-'A'].second = R;
    }

    PreOrder('A');
    cout << '\n';
    InOrder('A');
    cout << '\n';
    PostOrder('A');
    cout << '\n';
}