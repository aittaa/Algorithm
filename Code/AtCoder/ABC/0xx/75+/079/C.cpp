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

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

#define ll long long
#define lb long double
#define endl '\n'
#define sp ' '
#define pii pair<int, int>

#define pb push_back

#define YESNO(bool)            \
    if (bool)                  \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define yesno(bool)            \
    if (bool)                  \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define YesNo(bool)            \
    if (bool)                  \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }

#define ctoi(c) c - '0'

#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << sp << y << "\n"
#define print3(x, y, z) cout << x << sp << y << sp << z << "\n"
#define printv(x)    \
    for (auto v : x) \
    cout << v << sp

template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void fastIO()
{
    cin.tie(nullptr)->sync_with_stdio(false);
}

///////////////////////////////////////////////////

void operation(const int op, const int opd ,int &value, string &str)
{
    if (op)
    {
        value += opd;
        str += "+" + to_string(opd);
    }
    else
    {
        value -= opd;
        str += "-" + to_string(opd);
    }
}

int main()
{
    fastIO();

    string input;
    cin >> input;

    int a, b, c, d;
    a = ctoi(input.at(0));
    b = ctoi(input.at(1));
    c = ctoi(input.at(2));
    d = ctoi(input.at(3));

    int value = a;
    string str;
    str += to_string(a);

    rep(i, 2)
        rep(j, 2)
            rep(k, 2)
    {
        operation(i, b, value, str);
        operation(j, c, value, str);
        operation(k, d, value, str);

        if (value == 7)
        {
            print(str + "=7");
            return 0;
        }
        value = a;
        str = to_string(a);
    }
}