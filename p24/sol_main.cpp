#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
#include <deque>
#include <stack>
#include <cmath>
#include <iterator>

using namespace std;

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b - 1; i >= a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
LL mod = 1000LL * 1000 * 1000 + 7;

LL numberOfDigits(LL x)
{
    LL ans = 0;
    while (x)
    {
        ans++;
        x /= 10;
    }
    return ans;
}

int kthDigit(LL d, int k)
{
    vector<int> a;
    while (d)
    {
        a.PB(d % 10);
        d /= 10;
    }
    reverse(ALL(a));
    return a[k];
}

bool isPrime(LL x)
{
    if (x == 1)
        return false;
    for (LL i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    LL k, curK, d;
    cin >> k;
    if (k == 1)
    {
        cout << "2 2" << endl;
        return 0;
    }
    if (k == 2)
    {
        cout << "3 3" << endl;
        return 0;
    }
    k--;
    curK = k - 2; // we are not gonna consider 2 smallest prime numbers (2 and 3) anymore
    FOR(i, 1, k + 2)
    {
        LL candidate;
        candidate = 6LL * i - 1; // since any prime > 3 is 6 * i +/- 1
        if (isPrime(candidate))
        {
            curK -= numberOfDigits(candidate);
            if (curK < 0)
            {
                d = candidate;
                break;
            }
        }
        candidate = 6LL * i + 1;
        if (isPrime(candidate))
        {
            curK -= numberOfDigits(candidate);
            if (curK < 0)
            {
                d = candidate;
                break;
            }
        }
    }
    curK += numberOfDigits(d);

    cout << kthDigit(d, curK) << ' ' << d << endl;

    return 0;
}
