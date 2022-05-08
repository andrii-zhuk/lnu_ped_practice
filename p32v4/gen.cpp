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
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF*INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
LL mod = 1000LL * 1000 * 1000 + 7;


LL x;

LL toInt(string s) {
	LL res = 0;
	for (int i = 0; i < s.length(); i++) {
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

int main(int argc, char* argv[])
{
	LL test, minN, maxN;
	test = toInt(argv[1]);
  minN = toInt(argv[2]);
	maxN = toInt(argv[3]);
	const LL maxEntry = 1000LL * 1000 * 1000;
	srand(test);
	LL n = randLong() % (maxN - minN) + minN;

  vector<LL> a;
  a.push_back(4);
  a.push_back(7);
  FOR(i, 2, 8 * n / 10) // fill 80% of preudo- non-geometrical sequence values
  {
    LL cur = rand() % 100 + 1;
    a.PB(cur);
  }
  int leftToFill = n - 8 * n / 10;
	vector<int> cnt(a.size(), 0);

	while (leftToFill > 0)
	{
		int id = randLong() % cnt.size();
		int cur = rand() % 10 + 1;
		cur = min(cur, leftToFill);
		if (cur + cnt[id] > 10)
			continue;
		cnt[id] += cur;
		leftToFill -= cur;
	}
  cout << n << endl;
  FOR(i, 0, a.size())
  {
		if (cnt[i] == 0)
		{
			cout << a[i] << ' ';
			continue;
		}
		int q = rand() % 15 + 1;
		int strategy = rand() % 10;

		if (strategy < 4) // 40% ascending sequences
		{
			cout << a[i] << ' ';
			FOR(j, 0, cnt[i])
			{
				a[i] *= q;
				cout << a[i] << ' ';
			}
		}
		if (strategy > 5) // 40% descending sequences
		{
			FOR(j, 0, cnt[i])
			{
				a[i] *= q;
			}
			FOR(j, 0, cnt[i])
			{
				cout << a[i] << ' ';
				a[i] /= q;
			}
			cout << a[i] << ' ';
		}
		if (strategy == 4) // 10% sequences like 2 4 8 4 2
		{
			cout << a[i] << ' ';
			int ascending = rand() % cnt[i];
			ascending = max(ascending, cnt[i] - ascending);

			int descending = cnt[i] - ascending;

			FOR(j, 0, ascending)
			{
				a[i] *= q;
				cout << a[i] << ' ';
			}
			FOR(j, 0, descending)
			{
				a[i] /= q;
				cout << a[i] << ' ';
			}
		}
		if (strategy == 5) // 10% sequences like 8 4 2 4 8
		{
			int ascending = rand() % cnt[i];
			ascending = max(ascending, cnt[i] - ascending);

			int descending = cnt[i] - ascending;
			FOR(j, 0, descending)
			{
				a[i] *= q;
			}

			cout << a[i] << ' ';
			FOR(j, 0, descending)
			{
				a[i] /= q;
				cout << a[i] << ' ';
			}
			FOR(j, 0, ascending)
			{
				a[i] *= q;
				cout << a[i] << ' ';
			}
		}
  }

  return 0;
}
