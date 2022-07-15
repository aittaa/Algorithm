#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <iomanip>       // setprecision
#include <cmath>         // hypot

using namespace std;

string delim = " ";

#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << delim << y << "\n"
#define print3(x, y, z) cout << x << delim << y << delim << z << "\n"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

#define ll long long
#define lb long double

void fastIO()
{
    cin.tie(nullptr)->sync_with_stdio(false);
}

//////

int main()
{
    fastIO();

    double a, b, d;

    cin >> a >> b >> d;

    double r, d0;

    r = hypot(a, b);
    d0 = atan2(b, a); //각도 라디안으로 구해진다.

    d0 += d * acos(-1.0) / 180.0; // 각도 추가.

    double x, y;
    x = cos(d0) * r;
    y = sin(d0) * r;

    cout << fixed << setprecision(10) << x << endl << y << endl;
}