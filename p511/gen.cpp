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

string genWord(int len)
{
	string s;
	FOR(i, 0, len)
	{
		int ch = rand() % 26;
		if ((rand() % 2) == 0)
		{ // insert capital letter
			s.push_back('A' + ch);
		}
		else
		{
			s.push_back('a' + ch);
		}
	}
	return s;
}

string change(string s)
{
	FOR(i, 0, s.size())
	{
		if (rand() % 3 != 1)
		{
			continue;
		}
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] - 'A' + 'a';
		}
		else
		{
			s[i] = s[i] - 'a' + 'A';
		}
	}
	return s;
}

int main(int argc, char *argv[])
{
	LL test, minN, maxN;
	test = toInt(argv[1]);
	minN = toInt(argv[2]);
	maxN = toInt(argv[3]);
	srand(test);
	LL n = randLong() % (maxN - minN) + minN;
	n = min(n, maxN - 30);
	n = max(n, minN);
	string s = genWord(rand() % 20 + 5);
	string t = genWord(rand() % 20 + 5);

	string text = "Once";
	while (text.size() < n - 1)
	{
		int option = rand() % 20;
		text += ' ';
		if (option == 4) // 5% of s
		{
			if (rand() % 5 == 4)
			{
				text += change(s);
			}
			else
			{
				text += s;
			}
			continue;
		}
		string word = genWord(rand() % 20 + 3);
		text += word;
	}
	text += '.';

	cout << s << endl;
	cout << t << endl;
	cout << text << endl;

	return 0;
}
