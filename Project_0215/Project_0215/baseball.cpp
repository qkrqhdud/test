#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	srand(time(NULL));


	int num = 3;
	int* Com_num = new int[num];
	int* Player_num = new int[num];
	int cnt = 1;

	for (int i = 0; i < num; i++) {
		Com_num[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++) {
			if (Com_num[i] == Com_num[j]) {
				i--;
			}
		}
	}
	while (1) {
		int cnt_strike = 0;
		int cnt_ball = 0;

		cout << "1~9 까지의 숫자 3개를 입력해주세요. (이외의 숫자 : 종료) \n";
		for (int i = 0;i < num;i++) {
			
			cin >> Player_num[i];

			if (Player_num[i] > 9 || Player_num[i] < 1) {
				cout << "게임을 종료하셨습니다.\n";
				return-1;
			}
			if (Player_num[i] == Com_num[i]) {
				cnt_strike += 1;
			}
			else {
				for (int j = 0; j < num;j++) {
					if (Player_num[i] == Com_num[j]) {
						cnt_ball += 1;
					}
				}
			}
		
		}
		if (cnt_strike == num) {
			cout << cnt << "번만에 맞췄습니다!!\n";
			return -1;
		}
		cout <<"Strike : "<< cnt_strike << "  Ball : "<< cnt_ball<<"\n"<<endl;

		cnt++;
	}
	


}