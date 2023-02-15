// Project_0215.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	int num;
	int num_c;
	int baskin = 1;
	while (baskin!=32)
	{
		cout << " 개수를 입력하세요 ( 1~3 ) : ";
		cin >> num;
		if (num <= 3 && num >= 1) {
			cout << "사용자가 부른 숫자! \n";
			for (int i = 0; i < num; i++) {

				cout << baskin << endl;
				if (baskin == 31) {
					cout << "게임 종료 컴퓨터의 승리입니다" << endl;
					return -1;
				}
				baskin++;
			}
			cout << "컴퓨터가 부른 숫자\n";
			num_c = rand() % 3 + 1;
			for (int i = 0; i < num_c; i++) {
				cout << baskin << endl;
				if (baskin == 31) {
					cout << "게임 종료 사용자의 승리입니다" << endl;
					return -1;
				}

				baskin++;
			}
		}
		else {
			continue;
			
		}
		
	}
    
}

