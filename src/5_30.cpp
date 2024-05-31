// 문제 풀이

// 필수 문제
// 백준 18511 - 큰 수 구성하기

// 문제 정의
// N보다 작거나 같은 자연수 중에서, 집합 K의 원소로만 구성된 가장 큰 수를 출력하는 프로그램을 작성하시오.
// K의 모든 원소를 1부터 9까지의 자연수로만 구성된다.
// 예를 들어 N=657이고, K={1, 5, 7}일 때 답은 577이다.

// 입력
// 첫째 줄에 N, K가 주어지고, (10 <= N <= 100,000,000, 1 <= K <= 3)
// 둘째 줄에 K의 원소들이 공백을 기준으로 주어진다.

// 문제 풀이
// 가장 쉬운 방법은 N이 몇 자리 수인지 파악하고, K에서 가장 앞자리 수는 N의 첫 자리보다 작은 가장 큰 수
// 만약 N의 첫 자리보다 작은 수가 없다면, 그 자릿수는 버리고 그 다음부터는 그냥 가장 큰 수로 넣으면 될 듯
// 그럼 일단 N의 자릿수부터 파악해야하는데, 이건 나누기로 하면 되고
// 그 다음부터는 max() 사용해서 하면 되려나
// 위 방법으로 하면 예외처리 해줄 부분이 많아져서, 재귀로 접근

#include <bits/stdc++.h>
using namespace std;

int N, K, answer;
vector<int> vec;

void max_num(int num){
    if (N < num){ return; } // N보다 크면 종료
    
    answer = max(answer, num);

    num *= 10;

    for (int i = 0; i < K; i++){
        max_num(num + vec[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> N >> K;
    for (int i = 0; i < K; i++){
        cin >> num; vec.push_back(num);
    }
    
    max_num(0);

    cout << answer << '\n';

    return 0;
}