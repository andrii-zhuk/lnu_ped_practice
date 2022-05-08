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

bool cmp(const string &lsh, const string &rsh)
{
  if (lsh.size() == rsh.size())
  {
    return lsh < rsh;
  }
  return lsh.size() < rsh.size();
}

int main()
{

  int n;
  cin >> n;
  vector<LL> foo;

  FOR(i, 0, n)
  {
    LL s;
    cin >> s;
    foo.PB(s);
  }

  sort(ALL(foo));

  cout << n << endl;
  FOR(i, 0, n)
  {
    cout << foo[i] << ' ';
  }

  return 0;
}