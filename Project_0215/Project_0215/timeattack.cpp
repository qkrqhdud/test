
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


		cout << "���� �ܾ �Է��ϼ��� : ";
		cin >> next;
		cout << endl;
		if ( pre.at(pre.size()-1) == next[0]) {
			answer = answer + " -> " + next;
			pre = next;
			cout << answer;
			cnt++;
		}
		else {
			cout << "�߸����Է��Դϴ�\n";
		}
		finish = time(NULL);
		cout << (double)(finish - start) << endl;
		if ((double)(finish - start) >= 5) {
			cout << "-------------Ÿ�ӿ���---------------\n\n" << "-------------��������---------------";
			cout << "�� �Է��� �ܾ� ��:" << cnt << endl;
			return -1;

		}
		
	}
	
	/*start = time(NULL);
	finish = time(NULL);*/



}