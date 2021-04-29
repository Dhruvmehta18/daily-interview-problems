#include <iostream>
#include <vector>

using namespace std;

class TicTacToe{
    private:
        int n;
        vector<vector<int>> tic;
    public:
        TicTacToe(int n1){
            n = n1;
            vector<int> t(n);
            for(int i=0;i<n; i++){
                tic.push_back(t);
            }
        }
        bool move(int row, int col, int player){
            tic[row][col] = player;
            int i, j;
            j=n-1;
            bool isWinningLeft = true;
            bool isWinningRight = true;
            for(i=0;i<n&&(isWinningLeft||isWinningRight);i++){
                 if(isWinningLeft&&(tic[i][i]==0||tic[i][i]!=player)){
                     isWinningLeft = false;
                }
                if(isWinningRight&&(tic[i][n-1-i]==0||tic[i][n-1-i]!=player)){
                    isWinningRight = false;
                }
            }
            if (isWinningLeft||isWinningRight)
            {
                return true;
            }
            
            for(i=0;i<n;i++){
                bool isWinning = true;
                for(j=0;j<n;j++){
                    if(tic[i][j]==0||tic[i][j]!=player){
                        isWinning = false;
                        break;
                    }
                }
                if(isWinning){
                    return true;
                }
            }
            
            for(i=0;i<n;i++){
                bool isWinning = true;
                for(j=0;j<n;j++){
                    if(tic[j][i]==0||tic[i][j]!=player){
                        isWinning = false;
                        break;
                    }
                }
                if(isWinning){
                    return true;
                }
            }
            return false;
        }
};

int main(){
    TicTacToe board(3);
    board.move(0, 0, 1);
    board.move(0, 2, 2);
    board.move(2, 2, 1);
    board.move(1, 1, 2);
    board.move(2, 0, 1);
    board.move(1, 0, 2);
    cout<<board.move(0, 1, 1)<<endl;
    return 0;
}