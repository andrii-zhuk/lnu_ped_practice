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

LL x;

LL toInt(string s)
{
    LL res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

LL randLong()
{
    return 1LL * rand() * 32767 + rand();
}

LL randLL()
{
    return randLong() * 32767 * 32767 + rand();
}

int main(int argc, char *argv[])
{
    LL test, minK, maxK;
    test = toInt(argv[1]);
    minK = toInt(argv[2]);
    maxK = toInt(argv[3]);
    srand(test + maxK);
    LL k = rand() % (maxK - minK) + minK;
    cout << k << endl;
    return 0;
}
