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

LL gcd(LL a, LL b)
{
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

void check(const vector<LL> &a, vector<bool> &flag)
{
  if (a.size() < 3)
    return;

  FOR(i, 2, a.size())
  {
    double k = 1.0 * a[i - 1] / a[i - 2];
    double l = 1.0 * a[i] / a[i - 1];
    // then a[i-1] == a[i-2] * k && a[i] == a[i-1] * l
    if (abs(k - l) > EPS)
      continue;

    flag[i - 2] = true;
    flag[i - 1] = true;
    flag[i] = true;
  }
}

int main()
{
  LL n;
  cin >> n;
  vector<LL> a(n);
  FOR(i, 0, n)
  {
    cin >> a[i];
  }
  vector<bool> flag(n, false);

  FOR(i, 0, 2)
  {
    check(a, flag);
    reverse(ALL(a));
    reverse(ALL(flag));
  }

  FOR(i, 0, flag.size())
  {
    if (!flag[i])
    {
      cout << a[i] << ' ';
    }
  }

  return 0;
}
