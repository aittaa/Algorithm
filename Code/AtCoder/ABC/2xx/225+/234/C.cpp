
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

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

////

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    typedef long long ll;

    ll value;
    cin >> value;

    string result(bitset<64>(value).to_string());

    bool flag = false;

    for (int i = 0; i < result.size(); i++)
    {
        if (!flag && result.at(i) == '1')
            flag = true;

        if (flag)
        {
            if (result.at(i) == '0')
                cout << result.at(i);
            else
                cout << '2';
        }
    }
}