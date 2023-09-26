#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[502][502];
bool status[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

}
