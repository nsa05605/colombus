// 문제 풀이


// // 필수 문제
// // 블랙잭 (백준 - 2798)

// // 문제 정의
// // 카드의 합이 21일 넘지 않는 한도 내에서, 카드의 합을 최대한 크게 만드는 게임
// // N 장의 카드 중 3장을 뽑아 그 합이 M과 최대한 가깝게 만들어야 한다.
// // N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가깝도록 만들 수 있는 3장의 합을 출력하라

// // 입력
// // 처음에 카드의 개수 N (3 <= N <= 100)과 M (10 <= M <= 300,000)
// // 다음 줄에는 카드에 쓰여진 수가 주어짐

// // 풀이
// // 가장 간단하게 푸는 방법은 Brute-Force 검사를 거치는 방법이 있을 것 같음
// // 뭔가 DP로도 가능할 것 같은데, 확실히 모르겠음
// // BF 검사로 푸는 방법은 그냥 시작 전에 M과의 차이를 기억하는 residual 변수를 하나 만들고,
// // for문 3개 만들어서 하나씩 검사하면서 합이 M보다 크거나, M과의 차이가 residual보다 크면 넘기는 방법으로 구현

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie();

//     int N, M;
//     cin >> N >> M;

//     int num; vector<int> cards; // 입력받을 변수 num과 해당 변수들을 담을 벡터 cards
//     for (int i = 0; i < N; i++){
//         cin >> num;
//         cards.push_back(num);
//     }

//     int residual = 300001;   // 각 단계에서 3개의 합과 M 간의 최소 차이를 기억하기 위함
//     int sum = 0;        // 각 단계에서 구할 합
//     for (int i = 0; i < N; i++){
//         for (int j = i+1; j < N; j++){
//             for (int k = j+1; k < N; k++){
//                 int curr = cards[i] + cards[j] + cards[k];
//                 if (curr > M || (M - curr) > residual) {continue;}    // 합이 M보다 크거나, M과의 차이가 기존 residual 보다 크면 넘김
//                 residual = M - curr;
//                 sum = curr;
//             }
//         }
//     }
//     cout << sum << endl;
//     return 0;
// }


// 도전 문제
// 번데기 (백준 - 15721)

// 문제 정의
// "뻔" - "데기" - "뻔" - "데기" - "뻔" x n번 - "데기" x n번
// 이때 n은 (회차 + 1)
// 위의 과정으로 진행하는 게임이 있다.
// T번째 "뻔" 혹은 "데기"를 외치는 사람이 원에서 몇 번 사람인지 구하라
// 시작 지점은 0번

// 입력
// 첫 줄에 게임을 진행하는 사람 A명
// 둘째 줄에는 구하고자 하는 번째 T (T <= 10000)
// 셋째 줄에는 구하고자 하는 구호가 "뻔"이면 0, "데기"면 1로 주어진다.

// 문제 풀이
// 규칙을 먼저 찾아보면,
// 한 회차에 시행 회수는 4 + 2(n+1)
// 한 회차에 나오는 각 단어는 2 + (n+1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();

    int A, T, sign;
    cin >> A >> T >> sign;

    int curr=0, tmp_curr=0, n=1, tmp_n=1;    // 현재까지 진행된 횟수와 그 회차를 기억하는 변수
    while (tmp_curr/2 < T) {curr=tmp_curr; n=tmp_n-1; tmp_curr += 4+2*(tmp_n+1); tmp_n++;} // curr은 2배로 증가하는 이유는 "뻔", "데기" 모두 고려하기 때문

    cout << "curr : " << curr << " n : " << n << endl;

    // 여기까지 진행했으면, 이제 n번째부터 시작할 건데 이때 시작하는 사람이 몇 번에 있는지 확인해야 함
    // curr이 이 정보를 갖고 있으므로, (curr % A)-1 이 현재 진행되고 있는 사람의 번호. -1을 한 이유는 첫 시작이 0번이기 때문
    int start = curr % A;           // 시작하는 사람의 번호로 현재까지 진행된 횟수를 전체 사람으로 나눈 나머지
    int remain_T = T - (curr/2);    // 앞으로 더 얻어야하는 T의 수
    // 1개 or 2개만 더 얻어도 괜찮으면, 처음 0-1-0-1 패턴에서 출력
    if (remain_T == 1){
        if (sign == 0){cout << start%A << '\n';}
        else {start += 1; cout << start%A << '\n';}
    }
    else if (remain_T == 2){
        if (sign == 0){start += 2; cout << start%A << '\n';}
        else {start += 3; cout << start%A << '\n';}
    }
    else{
        if (sign == 0){start += (3+remain_T); cout << start%A << '\n';}
        else {start += (3+n+remain_T); cout << start%A << '\n';}
    }

    return 0;
}