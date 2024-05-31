// 문제 풀이

// 필수 문제
// 백준 5568 - 카드 놓기

// 문제 정의
// 카드 n장 중 k장을 선택하여 가로로 나란히 정수를 만들기
// 만들 수 있는 정수의 수를 출력
// 예를 들어 카드가 5장 있고, 그 수가 1,2,3,13,21 이고, 3장을 선택해서 정수를 만든다면
// 2,1,13 을 순서대로 2113을 만들거나 21,1,3을 순서대로 2113을 만들 수도 있음

// 입력
// 첫째 줄에 n, 둘째 줄에 k (4 <= n <= 10 / 2 <= k <= 4)
// 셋째 줄부터 카드에 적힌 수 n개

// 문제 풀이
// 


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> cards(n);
    for (int i=0; i<n; i++){
        cin >> cards[i];
    }

    

    return 0;
}