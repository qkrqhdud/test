#include <iostream>
int add(int a,int b) {
	
	return a + b;
}

int minus(int a ,int b ) {
	if (a >= b) {
		return a - b;
	}
	else {
		return b - a;
	}
	
}
int multiple(int a ,int b) {


	return a * b;
}
double divide(int a,int b) {
	return (double)a / (double)b;
}
void odd(int a) {
	if (a % 2 == 0) {
		std::cout << "¦��"<< std::endl;
	}
	else {
		std::cout << "Ȧ��"<<std::endl;
	}
}
int Max(int a, int b, int c) {
	if (a >= b) {
		if (b >= c) {
			return a;
		}
		else if (a >= c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (a >= c) {
			return b;
		}
		else if (b >= c) {
			return b;
		}
		else {
			return c;
		}

	}
}


int main() {
	int a, b,c;
	//std::cout << "�� ������ �Է����ּ��� : ";
	//std::cin >> a >> b;
	//std::cout << "�� : " << add(a, b)<< std::endl;

	//std::cout << "�� : " << minus(a, b) << std::endl;

	//std::cout << "�� : " << multiple(a, b) << std::endl;

	//std::cout << "�� : "<< divide(a, b) << std::endl;

	std::cout << "�� ������ �Է����ּ��� : ";
	std::cin >> a >> b >> c;
	//odd(c);
	std::cout << "���� ū ��" << Max(a, b, c)<<std::endl;

}