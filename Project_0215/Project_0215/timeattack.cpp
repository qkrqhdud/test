
#include <iostream>
#include <time.h>
#include<ctime>

using namespace std;
int time_sec(double S) {
	double F=  time(NULL);
	double sec;
	if (sec= (double)(F-S) > 5) return 0;
	else return 1;
}

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
		if ( pre.at(pre.size()-1) == next.at(0)) {
			if (time_sec(start)) {
				answer = answer + " -> " + next;
				pre = next;
				cout << answer<<endl;
				cnt++;
			}
			else {
				cout << "-------------Ÿ�ӿ���---------------\n\n" << "-------------��������---------------\n";
				cout << "�� �Է��� �ܾ� ��:" << cnt << endl;
				return -1;
			}
		}
		else {
			cout << "�߸����Է��Դϴ�\n";
		}
	}
	
	/*start = time(NULL);
	finish = time(NULL);*/



}