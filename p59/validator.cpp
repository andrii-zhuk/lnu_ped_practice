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

int main()
{
  const LL maxX = 1000LL * 1000 * 1000 * 1000 * 1000; // 1e15

  string s;
  getline(cin, s);

  if (s.size() < 4 || s.size() > 1e6)
  {
    cout << "Inappropriate string size" << endl;
    return 0;
  }
  FOR(i, 0, s.size() - 1)
  {
    if (not(s[i] == ' ' || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
    {
      cout << "Inappropriate character " << s[i] << " at position " << i << endl;
      return 0;
    }
  }
  if (s.back() != '.')
  {
    cout << "Line should end by '.'" << endl;
    return 0;
  }
  return 0;
}
