
#include <iostream>
#include <time.h>
#include<ctime>

using namespace std;

int main() {
	time_t start, finish;
	
	string pre = "airplane";
	string next;
	string answer=pre;
	int cnt = 0;

	cout << pre<<endl;

	start = time(NULL);


	while(1){


		cout << "다음 단어를 입력하세요 : ";
		cin >> next;
		cout << endl;
		if ( pre.at(pre.size()-1) == next[0]) {
			finish = time(NULL);
			if ((double)(finish - start) <= 5) {
				answer = answer + " -> " + next;
				pre = next;
				cout << answer<<endl;
				cnt++;
			}
			
		}
		else {
			cout << "잘못된입력입니다\n";
		}
		finish = time(NULL);
		
		if ((double)(finish - start) >= 5) {
			cout << "-------------타임오버---------------\n\n" << "-------------게임종료---------------\n";
			cout << "총 입력한 단어 수:" << cnt << endl;
			return -1;

		}
		
	}
	
	/*start = time(NULL);
	finish = time(NULL);*/



}