#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(NULL));
	
	//int num = rand();	// 1~25 사이의 난수
	int random_num[6] ;
	
	for (int i = 0; i < 6; i++) {
		random_num[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++) {
			if (random_num[i] == random_num[j]) {
				i--;
			}
		}
		//cout << random_num[i] << " ";
	}
	for (int i = 0; i < 6; i++) {
		cout << random_num[i] << " ";
		
	}
	return 0;
}