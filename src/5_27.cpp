// 문제 풀이

// 필수 문제 1.
// 백준 10870 - 피보나치 수 5

#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n < 2){return n;}
    else { return fibo(n-2) + fibo(n-1);}
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << '\n';
    return 0;
}