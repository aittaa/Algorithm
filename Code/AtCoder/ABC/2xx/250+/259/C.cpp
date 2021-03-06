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
    
    string s, t;
    cin >> s >> t;

    vector<pair<char, int>> ss;
    vector<pair<char, int>> tt;

    char prev = 'A';
    for(auto c : s){
        if(prev != c) ss.push_back({c, 1});
        else ss.back().second++;

        prev = c;
    }

    prev = 'A';
    for(auto c : t){
        if(prev != c) tt.push_back({c, 1});
        else tt.back().second++;

        prev = c;
    }

    bool flag = true;
    if(ss.size() != tt.size()){
        flag = false;
    }else{
    
        rep(i, ss.size()){
            if(ss.at(i).first != tt.at(i).first){
                flag = false;
                break;
            }
            if(ss.at(i).second == 1 && ss.at(i).second < tt.at(i).second){
                flag = false;
                break;
            }
            
            if(ss.at(i).second > tt.at(i).second){
                flag = false;
                break;
            }

        }
    }


    YesNo(flag);


    return 0;
}