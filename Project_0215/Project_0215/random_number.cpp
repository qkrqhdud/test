#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
	srand(time(NULL));

	//int num = rand();	// 1~25 ������ ����
	int Com_num[6];
	int Player_num[6];

	for (int i = 0; i < 6; i++) {
		Com_num[i] = rand() % 25 + 1;
		for (int j = 0; j < i; j++) {
			if (Com_num[i] == Com_num[j]) {
				i--;
			}
		}
		//cout << random_num[i] << " ";
	}
	cout << "6������  1~25������ ���ڸ� �Է����ּ��� \n";

	for (int i = 0; i < 6; i++) {

		cout << i+1 << "��° ���ڸ� �Է��ϼ���! :";

		cin >> Player_num[i];
		if (Player_num[i] > 25 || Player_num[i] < 1) {
			i--;
		}
		for (int j = 0; j < i; j++) {
			if (Player_num[i] == Player_num[j]) {
				cout << " �ߺ��� �����Դϴ� �ٽ� �Է����ּ���.\n";
				i--;
			}
		}
	}

	cout << "-----------------��÷��ȣ ����!!-----------------\n";
	int cnt = 7;
	for (int i = 0; i < 6; i++) {
		cout << Com_num[i] << " ";
		for (int j = 0; j < 6; j++) {
			if (Com_num[i] == Player_num[j]) {
				cnt -= 1;
			}
		}
	}
	cout << "��� : " << cnt << "�� �Դϴ�. �����մϴ�!!!!" << endl;
	return 0;
}