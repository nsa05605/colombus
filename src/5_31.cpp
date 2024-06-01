// 문제 풀이

// // 필수 문제
// // 백준 5568 - 카드 놓기

// // 문제 정의
// // 카드 n장 중 k장을 선택하여 가로로 나란히 정수를 만들기
// // 만들 수 있는 정수의 수를 출력
// // 예를 들어 카드가 5장 있고, 그 수가 1,2,3,13,21 이고, 3장을 선택해서 정수를 만든다면
// // 2,1,13 을 순서대로 2113을 만들거나 21,1,3을 순서대로 2113을 만들 수도 있음

// // 입력
// // 첫째 줄에 n, 둘째 줄에 k (4 <= n <= 10 / 2 <= k <= 4)
// // 셋째 줄부터 카드에 적힌 수 n개 (1 <= x <= 99)

// // 문제 풀이
// // 


// #include <bits/stdc++.h>
// using namespace std;

// unordered_set<string> result;
// vector<int> result_vec;
// bool visited[10] = {false};

// void permutation(vector<int> &cards, int k, int n)
// {
//     int answer = 0;
//     if (result_vec.size() == k){
//         string s = "";
//         for (int i = 0; i < result_vec.size(); i++){
//             s += to_string(result_vec[i]);
//         }
//         result.insert(s);
//         return;
//     }
//     for (int i = 0; i < n; i++){
//         if (visited[i]) continue;
//         visited[i] = true;
//         result_vec.push_back(cards[i]);
//         permutation(cards, k, n);
//         result_vec.pop_back();
//         visited[i] = false;
//     }

// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n, k;
//     cin >> n >> k;
//     vector<int> cards(n);
//     for (int i=0; i<n; i++){
//         cin >> cards[i];
//     }

//     permutation(cards, k, n);

//     cout << result.size() << '\n';

//     return 0;
// }


// 도전 문제
// 백준 2961 - 도영이가 만든 맛있는 음식

// 문제 정의
// N개의 재료와 그 재료의 신맛(S)과 쓴맛(B)이 주어진다.
// 음식의 신맛은 각 재료의 신맛의 곱이고, 쓴맛은 합이다.
// 신맛과 쓴맛의 차이가 가장 작은 요리를 만드는 프로그램

// 입력
// 첫째 줄에 재료의 개수 N (1 <= N <= 10)
// 다음 줄부터 각 재료의 신맛과 쓴맛 (1 <= S, B <= 1,000,000,000)

// 문제 풀이
// 재료를 일단 1개 이상 사용해야 하는데 다 사용할 필요는 없다
// DP 혹은 그래프 탐색으로 다룰 수 있을 것 같다.
// 사실 그냥 풀어도 계산 비용은 걱정하지 않아도 될 것 같기도한데,
// 일단 계산 편의를 위해 신맛(S)을 기준으로 오름차순 정렬을 먼저 하는게 좋을 듯
// 방법론을 생각해보는데, 잘 생각이 나지 않아서 인터넷 찾아보니 재귀로 해결하면 되는 것 같다.
// 


#include <bits/stdc++.h>
using namespace std;

int N, S, B;
int answer = INT_MAX;
vector<pair<int,int>> materials;

void recur(int cur, int cnt, int sour, int bitter)
{
    if (cur == N){
        if(cnt > 0) answer = min(answer, abs(sour - bitter)); return;
    }

    // 재료 사용 x - cur만 더해줌
    recur(cur+1, cnt, sour, bitter);
    // 재료 사용 o
    recur(cur+1, cnt+1, sour*=materials[cur].first, bitter+=materials[cur].second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> S >> B;
        materials.push_back(make_pair(S,B));
    }
    recur(0, 0, 1, 0);
    cout << answer << '\n';
}