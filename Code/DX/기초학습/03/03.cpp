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

ull solve(string& str, map<pair<int, ui>>& mem){

    int total = 0;
    rep(i, str.size()){

        int holder = 3 - (str.at(i) - 'A');
        int cnt = 0;
        for(size_t prev = 1; prev < (1<<4); ++prev){
            cnt += mem[{holder, prev}];
        }
    }

}

void memorize(map<pair<int, ui>, int>& mem){

    // D, C, B, A
    rep(i, 4){
        for(size_t prev = 1; prev < (1 << 4); ++prev){
            
            int cnt = 0;
            for(size_t j = 1; j < (1 << 4); ++j){
                if(!(j & (1 << i))) continue;
                if( (j & prev) == 0 ) continue;
                ++cnt;
            }
            mem[{i, prev}, cnt];
        }
    }
}



int main()
{
    fastIO();
    
    int tc;
    cin >> tc;

    ull cnt;
    map<pair<char, ui>, int> mem;

    memorize(mem);

    rep(i, tc){
        cnt = 0;
        string str;
        cin >> str;

        cnt += solve(str, mem);    

        print2("#"+to_string(i+1), cnt);
    }
    

    return 0;
}