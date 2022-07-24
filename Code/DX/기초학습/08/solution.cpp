#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, j, n) for (int i = j; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

#define ui unsigned int
#define ll long long
#define ull unsigned long long
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

int main()
{
    fastIO();
    
    int tc;
    cin >> tc;

    rep(t, tc){
        int n, m, l;
        cin >> n >> m >> l;
        list<int> array(n);
        
        for(auto& e : array)
            cin >> e;
        


        int idx, value;

        auto iter = array.begin();

        rep(j, m){
            char op;
            cin >> op;
            iter = array.begin();
            switch(op){
                case 'I':
                    cin >> idx >> value;
                    rep(i, idx) ++iter;
                    array.insert(iter, value);
                break;
                case 'D':
                    cin >> idx;
                    rep(i, idx) ++iter;
                    array.erase(iter);
                break;
                case 'C':
                    cin >> idx >> value;
                    rep(i, idx) ++iter;
                    *iter = value;
                break;
            }
        }
        iter = array.begin();

        if(array.size() < l) {
            print2("#"+to_string(t+1), -1);
        } else {
            rep(i, l) ++iter;
            print2("#"+to_string(t+1), *iter);
        }
    
    }
    
    return 0;
}
