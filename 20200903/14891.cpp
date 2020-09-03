#include <cstdio>
#include <deque>
using namespace std;
deque<int> dq[4];
int k;//회전 횟수
int ans;
void rotate(int num, int dir) {
	if (dir == 1) {
		//시계 방향
		int temp = dq[num].at(7);
		for (int i = 7; i > 0; i--) {
			dq[num].at(i) = dq[num].at(i - 1);
		}
		dq[num].at(0) = temp;
	}
	else if (dir == -1) {
		//반시계 방향
		int temp = dq[num].at(0);
		for (int i = 0; i < 7; i++) {
			dq[num].at(i) = dq[num].at(i + 1);
		}
		dq[num].at(7) = temp;
	}
}
void check(int num, int dir) {
	int rdir;
	if (dir == 1)
		rdir = -1;
	else if (dir == -1)
		rdir = 1;

	if (num == 0) {
		//1번 톱니바퀴
		if (dq[num].at(2) != dq[num + 1].at(6)) {
			//1번 2번 달러
			if (dq[num + 1].at(2) != dq[num + 2].at(6)) {
				//2번 3번 달러
				if (dq[num + 2].at(2) != dq[num + 3].at(6)) {
					//3번 4번 달러
					rotate(num, dir);//1번 돌려
					rotate(num + 1, rdir);//2번 돌려
					rotate(num + 2, dir);//3번 돌려
					rotate(num + 3, rdir);//4번 돌려
				}		
				else {
					//3번 4번 같어 = 4번 못돌려
					rotate(num, dir);//1번 돌려
					rotate(num + 1, rdir);//2번 돌려
					rotate(num + 2, dir);//3번 돌려
				}
			}
			else {
				//2번 3번 같어 = 3번 못돌려
				rotate(num, dir);//1번 돌려
				rotate(num + 1, rdir);//2번 돌려
			}
		}
		else {
			//1번 2번 같어 = 2번 못돌려
			rotate(num, dir);//1번 돌려
		}
	}
	else if (num == 1) {
		//2번 톱니바퀴
		if (dq[num].at(6) != dq[num - 1].at(2)) {
			//2번 1번 달러
			rotate(num - 1, rdir);//1번 돌려
		}

		if (dq[num].at(2) != dq[num + 1].at(6)) {
			//2번 3번 달러
			if (dq[num + 1].at(2) != dq[num + 2].at(6)) {
				//3번 4번 달러
				rotate(num, dir);//2번 돌려
				rotate(num + 1, rdir);//3번 돌려
				rotate(num + 2, dir);//4번 돌려
			}
			else {
				//3번 4번 같어 = 4번 못돌려
				rotate(num, dir);//2번 돌려
				rotate(num + 1, rdir);//3번 돌려
			}
		}
		else {
			//2번 3번 같어 = 3번 못돌려
			rotate(num, dir);//2번 돌려
		}		
	}
	else if (num == 2) {
		//3번 톱니바퀴
		if (dq[num].at(2) != dq[num + 1].at(6)) {
			//3번 4번 달러
			rotate(num + 1, rdir);//4번 돌려
		}
		if (dq[num].at(6) != dq[num - 1].at(2)) {
			//3번 2번 달러
			if (dq[num - 1].at(6) != dq[num - 2].at(2)) {
				//2번 1번 달러
				rotate(num, dir);//3번 돌려
				rotate(num - 1, rdir);//2번 돌려
				rotate(num - 2, dir);//1번 돌려
			}
			else {
				//2번 1번 같어 = 1번 못돌려
				rotate(num, dir);//3번 돌려
				rotate(num - 1, rdir);//2번 돌려
			}
		}
		else {
			//3번 2번 같어 = 2번 못돌려
			rotate(num, dir);//3번 돌려
		}
	}
	else if (num == 3) {
		//4번 톱니바퀴
		if (dq[num].at(6) != dq[num - 1].at(2)) {
			//4번 3번 달러
			if (dq[num - 1].at(6) != dq[num - 2].at(2)) {
				//3번 2번 달러
				if (dq[num - 2].at(6) != dq[num - 3].at(2)) {
					//2번 1번 달러
					rotate(num, dir);//4번 돌려
					rotate(num - 1, rdir);//3번 돌려
					rotate(num - 2, dir);//2번 돌려
					rotate(num - 3, rdir);//1번 돌려
				}
				else {
					//2번 1번 같어 = 1번 못돌려
					rotate(num, dir);//4번 돌려
					rotate(num - 1, rdir);//3번 돌려
					rotate(num - 2, dir);//2번 돌려
				}
			}
			else {
				//3번 2번 같어 = 2번 못돌려
				rotate(num, dir);//4번 돌려
				rotate(num - 1, rdir);//3번 돌려
			}
		}
		else {
			//4번 3번 같어 = 3번 못돌려
			rotate(num, dir);//4번 돌려
		}
	}
}

void input() {
	for (int i = 0; i < k; i++) {
		int num, dir;//번호, 방향
		scanf("%d%d", &num, &dir);
		check(num-1, dir);//확인하러
	}
	int j = 1;
	for (int i = 0; i < 4; i++) {
		if (dq[i].at(0) == 1)
			ans += j;
		j *= 2;
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int a;
			scanf("%1d", &a);
			dq[i].push_back(a);
		}
	}
	scanf("%d", &k);
	input();//회전하러
	printf("%d", ans);
	return 0;
}
