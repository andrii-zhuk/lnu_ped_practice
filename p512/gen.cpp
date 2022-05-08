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

string gen(LL size)
{
	string t;
	FOR(i, 0, size)
	{
		t.PB('0' + rand() % 10);
	}
	return t;
}

void change(string &s)
{
	if (s[0] == '0')
	{
		s[0] += rand() % 9;
	}
}

int main(int argc, char *argv[])
{
	LL test, minN, maxN, minSize, maxSize;
	test = toInt(argv[1]);
	minN = toInt(argv[2]);
	maxN = toInt(argv[3]);
	minSize = toInt(argv[4]);
	maxSize = toInt(argv[5]);
	srand(test);
	LL n = randLong() % (maxN - minN) + minN;
	vector<string> res;

	FOR(i, 0, n)
	{
		LL size = randLong() % (maxSize - minSize) + minSize;
		string s = gen(size);
		change(s);
		res.PB(s);
	}

	cout << res.size() << endl;
	FOR(i, 0, res.size())
	{
		cout << res[i] << endl;
	}
	return 0;
}
