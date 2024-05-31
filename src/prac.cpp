#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n < 2) {return n;}
    else {
        return fibo(n-2) + fibo(n-1);
    }
}

int main()
{
    cout << fibo(10) << '\n';
    return 0;
}