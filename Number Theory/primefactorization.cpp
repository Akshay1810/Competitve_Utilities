#define MAXN 100001
vector<int> spf(MAXN + 1, 1);

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    // stores smallest prime factor for every number

    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { // if the number is prime ,mark
                           // all its multiples who havent
                           // gotten their spf yet
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1) // if its smallest prime factor is
                          // 1 means its spf hasnt been
                          // found yet so change it to i
                    spf[j] = i;
            }
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}