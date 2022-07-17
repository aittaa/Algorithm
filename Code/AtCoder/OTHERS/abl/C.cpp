#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound, next_permutation, ...
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
#define rep_(i, j, n) for (int i = j; i < (int)(n); i++)
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
#define printv(container, end)    \
    for (auto e : container) \
    cout << e << end

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

const int dx2[8] = {0, 1, -1, 0, -1, 1, -1, 1};
const int dy2[8] = {1, 0, 0, -1, -1, 1, 1, -1};

void fastIO()
{
    cin.tie(nullptr)->sync_with_stdio(false);
}



///////////////////////////////////////////////////

struct OptimizedDisjointSet{
    vector<int> parent, rank;
    OptimizedDisjointSet(int n) : parent(n), rank(n, 1){
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    // u가 속한 트리의 루트의 번호를 반환한다.
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }


    // u가 속한 트리와 v가 속한 트리를 합친다.
    void merge(int u, int v) {
        u = find(u); v = find(v);
        
        if (u == v) return; // u와 v가 이미 같은 트리에 속하는 경우를 걸러낸다.
        
        if(rank[u] < rank[v]) swap(u, v);
        // 이제 rank[u]가 항상 rank[v] 이상이므로 v를 u의 자식으로 넣는다.
        parent[v] = u; // merge
        
        if(rank[u] == rank[v]) ++rank[u]; // 두 트리의 높이가 같은 경우 트리의 높이가 증가되어야 함.
    }
};


int main()
{
    fastIO();
    
    int N, M;
    cin >> N >> M;
    OptimizedDisjointSet uf(N);

    rep(i, M){
        int a, b;
        cin >> a >> b;
        uf.merge(a-1, b-1);
    }

    unordered_set<int> resultSet;

    rep(i, N){
        resultSet.insert(uf.find(i));
        
    }
    cout << resultSet.size() - 1 << endl;

}

