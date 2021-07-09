#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for (int i=0; i<moves.size(); i++) {
        int c = moves[i]-1;//뽑을 열
        for (int j=0; j<board.size(); j++) {
            if (board[j][c] == 0) continue; //인형없음
            int temp = board[j][c]; //옮길 인형번호
            board[j][c] = 0;//옮겼으니까 0으로 갱신
            if (!st.empty() && st.top() == temp) {
                //스택이 비어있지 않으면서 스택 탑의 번호가 넣을 번호와 같으면
                //터트려짐
                answer+=2;//두개 터짐
                st.pop();//터졌으니까 꺼내기
            }
            else {
                st.push(temp);//터지지 않으니까 인형 넣음
            }    
            break;
        }
    }
    return answer;
}
