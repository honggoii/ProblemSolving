#include <cstdio>
#include <vector>
using namespace std;
typedef struct {
	int x; // 행
	int y; // 열
	int dir; // 방향
} Chess;
Chess chess[11]; // 말 관리
vector<int> ChessMap[21][21]; // 현재 위치에 놓여있는 말 번호
int map[21][21]; // 맵
int dx[] = { 0,0,0,-1,1 }; // 행
int dy[] = { 0,1,-1,0,0 }; // 열
int n, k;
bool checkEnd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ChessMap[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}
int changeDir(int dir) {
	if (dir == 1) return 2;
	if (dir == 2) return 1;
	if (dir == 3) return 4;
	if (dir == 4) return 3;
}
bool range(int nx, int ny) {
	return nx >= 1 && nx <= n && ny >= 1 && ny <= n;
}
void reverse_moveChess(int x, int y, int nx, int ny, int idx, int dir) {
	int del = 0; // 지워야할 말 갯수
	for (int i = ChessMap[x][y].size() - 1; i > -1; i--) {
		ChessMap[nx][ny].push_back(ChessMap[x][y][i]); // 이동할 곳에 넣는다.
		chess[ChessMap[x][y][i]] = { nx, ny, chess[ChessMap[x][y][i]].dir };
		del += 1;
		if (ChessMap[x][y][i] == idx) {
			break;
		}
	}

	while (del--) {
		ChessMap[x][y].pop_back(); // 이동한 말들 지우기
	}
}
void moveChess(int x, int y, int nx, int ny, int idx, int dir) {
	// 현재 칸에 있는 말 모두 확인
	bool check = false;
	int del = 0; // 지워야할 말 갯수
	for (int i = 0; i < ChessMap[x][y].size(); i++) {
		if (ChessMap[x][y][i] == idx || check) {
			// 움직여야할 말 부터면
			check = true;
			ChessMap[nx][ny].push_back(ChessMap[x][y][i]); // 이동할 곳에 넣는다.
			chess[ChessMap[x][y][i]] = { nx, ny, chess[ChessMap[x][y][i]].dir};
			del += 1;
		}		
	}
	
	while (del--) {
		ChessMap[x][y].pop_back(); // 이동한 말들 지우기
	}
}
int startGame() {
	int turn = 1;
	while (1) {
		if (1000 < turn) return -1; // 1000을 넘으면 -1

		for (int i = 1; i <= k; i++) {
			int x = chess[i].x;
			int y = chess[i].y;
			int dir = chess[i].dir; // 현재 방향 확인

 			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int color = map[nx][ny]; // 다음 칸 색 확인

			if (!range(nx, ny) || color == 2) {
				// 2거나 맵을 벗어나면, 방향을 반대로하고 이동
				int ndir = changeDir(dir);
				int nnx = x + dx[ndir];
				int nny = y + dy[ndir];
				chess[i] = { x, y, ndir };
				if (range(nnx, nny) && map[nnx][nny] != 2) {
					if (map[nnx][nny] == 0) {
						moveChess(x, y, nnx, nny, i, ndir); // i번 말 위에 있는 말도 모두 이동
					}
					else if (map[nnx][nny] == 1) {
						reverse_moveChess(x, y, nnx, nny, i, ndir);
					}
				}				
			}
			else if (color == 0) {
				// 0이면, 이동하고 해당 맵 관리에 현재 말 번호 push
				moveChess(x, y, nx, ny, i, dir);
			}
			else if (color == 1) {
				// 1이면, 쌓인 순서 반대로하고 이동
				reverse_moveChess(x, y, nx, ny, i, dir);
			}

			bool end = checkEnd(); // 말 한 번 이동마다 4개 쌓여있는지 확인
			if (end) return turn;
		}
		turn += 1; // 한 턴 끝남
	}
	return -1;
}
void inputChess() {
	int x, y, dir;
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &x, &y, &dir);
		chess[i] = { x, y, dir }; // 말 관리
		ChessMap[x][y].push_back(i); // 해당 좌표에 말 번호 입력
	}
}
void inputMap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	inputMap(); // 맵 입력
	inputChess(); // 말 입력
	int ans = startGame(); // 1번 ~ k번 말 이동
	printf("%d", ans);
	return 0;
}
