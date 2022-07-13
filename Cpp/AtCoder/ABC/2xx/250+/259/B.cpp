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

    print(1);
    print2(1, 2);
    print3(1, 2, 3);
}