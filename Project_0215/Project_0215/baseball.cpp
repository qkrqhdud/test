#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	srand(time(NULL));

	//int num = rand();	// 1~25 ������ ����
	int Com_num[3];
	int Player_num[3];
	int cnt = 1;

	for (int i = 0; i < 3; i++) {
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

		cout << "1~9 ������ ���� 3���� �Է����ּ���. (�̿��� ���� : ����) \n";
		for (int i = 0;i < 3;i++) {
			
			cin >> Player_num[i];

			if (Player_num[i] > 9 || Player_num[i] < 1) {
				cout << "������ �����ϼ̽��ϴ�.\n";
				return-1;
			}
			if (Player_num[i] == Com_num[i]) {
				cnt_strike += 1;
			}
			else {
				for (int j = 0; j < 3;j++) {
					if (Player_num[i] == Com_num[j]) {
						cnt_ball += 1;
					}
				}
			}
		
		}
		if (cnt_strike == 3) {
			cout << cnt << "������ ������ϴ�!!\n";
			return -1;
		}
		cout <<"Strike : "<< cnt_strike << "  Ball : "<< cnt_ball<<"\n"<<endl;

		cnt++;
	}
	


}