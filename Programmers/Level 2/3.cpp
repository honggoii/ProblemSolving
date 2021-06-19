#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int row = board.size();
    int col = board[0].size();

    if (row == 1) {
        for (int i=0; i<col; i++) {
            if (board[0][i]==1) {
                answer = 1;
                break;
            }
        }
    }
    else if (col == 1) {
        for (int i=0; i<row; i++) {
            if (board[i][0]==1) {
                answer = 1;
                break;
            }
        }
    }
    else {
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (board[i][j] == 1) {
                    board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
                }                
               
                if (answer < board[i][j])
                    answer = board[i][j];
            }
        }
    }

    answer *= answer;
    return answer;
}
