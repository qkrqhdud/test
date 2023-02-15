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
	int baskin = 1; //true : 사용자 false: 컴퓨터 
	bool flag = true;
	while (baskin<32)
	{
		if (flag){
			cout << " 개수를 입력하세요 ( 1~3 ) : ";
			cin >> num;
			cout << " 사용자의 차례입니다 \n ";
			for (int i = 0; i < num; i++) {
				cout << baskin << endl;
				baskin++;
				if (baskin == 32) break;
				
			}
			flag = false;
		}
		else {
			num_c = rand() % 3 + 1;
			cout << " 컴퓨터의 차례입니다 \n ";
			for (int i = 0; i < num_c; i++) {
					cout << baskin << endl;
					baskin++;
					if (baskin == 32) break;
					
				}
			flag = true;
		}	
	}
	cout << "------------게임 종료------------\n";
	flag ? cout << "컴퓨터의 승리!!" : cout << "사용자의 승리!!";
    
}

