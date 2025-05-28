#include <bits/stdc++.h>
using namespace std;

bool check(long long x, long long y, long long p, long long q, long long t)
{
    return p * t >= x && q * t - p * t >= y - x;
}

long long solve(int x, int y, int p, int q)
{
    long long l = 0, r = INT_MAX;
    if (!check(x, y, p, q, r))
    {
        return -1;
    }
    while (r - l > 1)
    {
        long long mid = l + (r - l) / 2;
        if (check(x, y, p, q, mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r * q - y;
}
