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

int main(){
    fastIO();
    //파일 입력
    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    
    rep(tc, 10){
        int n;
        cin >> n;

        list<int> li(n);

        auto iter = li.begin();

        rep(i, n){
            int input;
            cin>>input;
            *iter = input;
            ++iter;
        }

        int m;
        cin >> m;

        rep(i, m){
            char input;
            cin >> input;

            int idx, cnt;
            vector<int> temp;
            list<int>::iterator itr;

            switch(input){
                case 'I':
                    cin >> idx >> cnt;
                    temp = vector<int>(cnt);
                    rep(j, cnt) cin >> temp.at(j);
                    
                    itr = li.begin();
                    rep(j, idx) ++itr;

                    li.insert(itr, all(temp));
                break;

                case 'D':
                    cin >> idx >> cnt;

                    itr = li.begin();

                    rep(j, idx) ++itr; 
                    
                    rep(j, cnt) li.erase(itr++);
                    
                
                break;
                case 'A':
                    cin >> cnt;
                    temp = vector<int>(cnt);
                    rep(j, cnt) cin >> temp.at(j);

                    li.insert(li.end(), all(temp));
                
                break;
            }
        }


        print("#" + to_string(tc+1) + " ");

        int i = 0;
        for(auto& e : li){
            if(!(i < 10)) break;

            cout << e << sp;

            ++i;
        }

        cout << endl;

    }


    return 0;
}