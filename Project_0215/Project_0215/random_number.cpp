#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
	srand(time(NULL));

	//int num = rand();	// 1~25 사이의 난수
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
	cout << "6가지의  1~25까지의 숫자를 입력해주세요 \n";

	for (int i = 0; i < 6; i++) {

		cout << i+1 << "번째 숫자를 입력하세요! :";

		cin >> Player_num[i];
		if (Player_num[i] > 25 || Player_num[i] < 1) {
			i--;
		}
		for (int j = 0; j < i; j++) {
			if (Player_num[i] == Player_num[j]) {
				cout << " 중복된 숫자입니다 다시 입력해주세요.\n";
				i--;
			}
		}
	}

	cout << "-----------------당첨번호 공개!!-----------------\n";
	int cnt = 7;
	for (int i = 0; i < 6; i++) {
		cout << Com_num[i] << " ";
		for (int j = 0; j < 6; j++) {
			if (Com_num[i] == Player_num[j]) {
				cnt -= 1;
			}
		}
	}
	cout << "결과 : " << cnt << "등 입니다. 축하합니다!!!!" << endl;
	return 0;
}