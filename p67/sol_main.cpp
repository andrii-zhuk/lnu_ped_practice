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

bool isLeap(int year)
{
  if (year % 4 == 0)
  {
    if (year % 100 == 0)
    {
      return (year % 400 == 0);
    }
    return true;
  }
  return false;
}

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

int getMonthDays(int m, int year)
{
  if (m == 2)
  {
    return isLeap(year) + monthDays[1];
  }
  return monthDays[m - 1];
}

struct Date
{
  int d, m, y;

  int countLeapYears()
  {
    int years = y;
    if (m <= 2)
      years--;
    return years / 4 - years / 100 + years / 400;
  }

  int getDifference(Date dt2)
  {
    if (d == dt2.d && m == dt2.m && y == dt2.y)
      return 0;
    long int n1 = y * 365 + d;
    for (int i = 0; i < m - 1; i++)
      n1 += monthDays[i];
    n1 += countLeapYears();

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
      n2 += monthDays[i];
    n2 += dt2.countLeapYears();
    return (n2 - n1);
  }

  Date subtractYear()
  {
    Date result = {d, m, y + 1};
    return result;
  }
  Date subtractDay()
  {
    Date result = {d - 1, m, y};

    if (result.d < 1)
    {
      result.m--;
      if (result.m < 1)
      {
        result.y--;
        result.m = 12;
      }
      result.d = getMonthDays(result.m, result.y);
    }
    return result;
  }
  Date addDay()
  {
    Date result = {d + 1, m, y};

    if (result.d > getMonthDays(result.m, result.y))
    {
      result.d = 1;
      result.m++;
      if (result.m > 12)
      {
        result.y++;
        result.m = 1;
      }
    }
    return result;
  }

  Date subtractDays(int k)
  {
    Date result = {d, m, y};
    result.y -= k / 366;
    k += getDifference(result);
    while (k--)
    {
      result = result.subtractDay();
    }
    return result;
  }

  Date addDays(int k)
  {
    Date result = {d, m, y};
    result.y += k / 366;
    k -= getDifference(result);
    while (k--)
    {
      result = result.addDay();
    }
    return result;
  }
  int dayOfWeek()
  {
    Date dt1 = {3, 1, 2000}; // Monday
    int days = getDifference(dt1) % 7;
    if (days <= 0)
    {
      days = -days;
    }
    else
    {
      days = (7 - days);
    }
    return days;
  }
};

int main()
{
  int t;
  int d, m, y, k;
  cin >> t;
  while (t--)
  {
    cin >> d >> m >> y >> k;
    Date dt2 = {d, m, y};
    Date dt3 = dt2.subtractDays(k);
    cout << dt3.d << ' ' << dt3.m << ' ' << dt3.y << ' ' << endl;
    cout << dt3.dayOfWeek() << endl;
  }
  return 0;
}
