
#include<iostream>
#include<cstring>
using namespace std;


int arr[100][100];
bool visited[100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int visit(int x, int y, int N, int waterLevel){
    if(x < 0 || N <= x || y < 0 || N <= y) return 0;

    if(arr[x][y] > waterLevel && !visited[x][y]){
        visited[x][y] = 1;

        for(int i = 0; i < 4; i++){
            visit(x+dx[i], y+dy[i], N, waterLevel);
        }

        return 1;
    } else {
        return 0;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
                visited[i][j] = 0;
            }
        }


         int maxCnt = 0;

        for(int waterLevel = 0; waterLevel < 100; waterLevel++){
            memset(visited, 0, sizeof(visited));
            int cnt = 0;
            
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){

                    if(visit(i, j, N, waterLevel)) cnt++;

                }
            }

            if(maxCnt < cnt) maxCnt = cnt;
        }

        cout << "#" << i+1 << " "<< maxCnt <<"\n";
    }


}

