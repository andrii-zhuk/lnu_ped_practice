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
LL k;

pair<LL, LL> findD()
{
    LL x = 0;
    LL pow10 = 1;
    LL d = 0;
    FOR(i, 1, 18)
    {
        LL count = pow10 * 10 - pow10;

        x += count * i;
        if (x > k) // then k has i digits
        {
            LL curK = k;
            curK -= x - count * i;
            if (i == 1)
            {
                d = curK;
            }
            else
            {
                d = pow10 + curK / i;
            }
            return MP(d, curK % i);
        }
        pow10 *= 10;
    }
    return MP(0, 0);
}

int main()
{
    cin >> k;
    if (k < 10)
    {
        cout << k << ' ' << k << endl;
        return 0;
    }
    k--;
    pair<LL, LL> d = findD();
    cout << kthDigit(d.first, d.second) << ' ' << d.first << endl;

    return 0;
}
