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

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << sp << y << "\n"
#define print3(x, y, z) cout << x << sp << y << sp << z << "\n"

void fastIO()
{
    cin.tie(nullptr)->sync_with_stdio(false);
}

//////

int main()
{
    fastIO();

    string s;

    cin >> s;

    bool a = false, b = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (!a && s.at(i) == 'C')
            a = true;
        if (a && s.at(i) == 'F')
        {
            b = true;
            break;
        }
    }

    if (b)
        print("Yes");
    else
        print("No");
}