// 문제 풀이

// 필수 문제 1.
// 백준 19532 - 수학은 비대면강의입니다.

// 문제 정의
// 연립 방정식에서 x와 y의 값을 계산하시오
// ax + by = c
// dx + ey = f

// 입력
// 정수 a,b,c,d,e,f 가 공백으로 구분되어 차례로 주어진다. (-999 <= v <= 999)
// 문제에서 언급한 방정식을 만족하는 (x,y)가 유일하게 존재하고, 이때 x와 y는 각각 -999 ~ 999 사이의 정수임

// 문제 풀이
// a,b,c를 알고 있기 때문에, ax+by=c 를 만족하는 (x,y) 쌍을 찾고
// 이를 dx+ey=f 식에 넣어서 맞는 정답을 찾으면 될 것 같음

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    vector<pair<int,int>> xy;

    for (int x = -999; x <= 999; x++){
        for (int y = -999; y <= 999; y++){
            if (a*x + b*y == c){xy.push_back(make_pair(x,y));}
        }
    }

    for (int i = 0; i < xy.size(); i++){
        int x = xy[i].first, y = xy[i].second;
        if (d*x + e*y == f){cout << x << " " << y << '\n'; return 0;}
    }
    return 0;
}


// 필수 문제 2.
// 백준 18312 - 시각

// 문제 정의
// 정수 N, K가 입력되었을 때, 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 K가 하나라도 포함되는 모든 시각을 세는 프로그램 작성
// 예를 들어 K=3이면, 23시 00분 00초, 07시 08분 03초는 정답

// 입력
// 첫째 줄에 정수 N과 K가 공백으로 주어진다. (0 <= N <= 23, 0 <= K <= 9)

// 문제 풀이
// 일단 규칙을 만들어야지
// 1시간에 각 숫자가 시, 분, 초에서 몇 번 언급되는지 규칙을 찾아보자
// 시간은 단순하게 K <= N 이면 1
// 분은 기본적으로 6번씩인데, 0~5 는 9번을 더 카운트 해야 함
// 예를 들어
// 0 : 00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 20, 30, 40, 50
// 6 : 06, 16, 26, 36, 46, 56
// 초도 분과 마찬가지인데, 초는 매 분마다 있는 거니까 
// 근데 너무 복잡하게 생각하는 것 같아서 단순하게 반복문으로 구현해보자

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    int cnt = 0;
    cin >> N >> K;

    for (int h = 0; h <= N; h++){
        for (int m = 0; m < 60; m++){
            for (int s = 0; s < 60; s++){
                if ((h % 10 == K) || (h / 10 == K) || (m % 10 == K) || (m / 10 == K) || (s % 10 == K) || (s / 10 == K)) cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}

