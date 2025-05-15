#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

// fast exponentiation a^e mod m
int64 modpow(int64 a, int64 e) {
    int64 r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n;
    cin >> n;

    // precompute modular inverses of 25 and 26
    int64 inv25 = modpow(25, MOD-2);
    int64 inv26 = modpow(26, MOD-2);

    // m = floor(n/2)
    int64 m = n / 2;

    // x = (1/26)^m mod MOD
    int64 x = modpow(inv26, m);

    int64 num;  // numerator of E(n)
    if ((n & 1) == 0) {
        // n = 2m
        // num = 27 * (1 - x) mod MOD
        num = (27LL * ((1 - x + MOD) % MOD)) % MOD;
    } else {
        // n = 2m + 1
        // num = 27 - 2*x mod MOD
        num = (27 - 2 * x % MOD + MOD) % MOD;
    }

    // answer = num * inv25 mod MOD
    int64 ans = num * inv25 % MOD;
    cout << ans << "\n";
    return 0;
}
