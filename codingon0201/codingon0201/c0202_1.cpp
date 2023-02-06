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
		std::cout << "짝수"<< std::endl;
	}
	else {
		std::cout << "홀수"<<std::endl;
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
	//std::cout << "두 정수를 입력해주세요 : ";
	//std::cin >> a >> b;
	//std::cout << "합 : " << add(a, b)<< std::endl;

	//std::cout << "차 : " << minus(a, b) << std::endl;

	//std::cout << "곱 : " << multiple(a, b) << std::endl;

	//std::cout << "나 : "<< divide(a, b) << std::endl;

	std::cout << "세 정수를 입력해주세요 : ";
	std::cin >> a >> b >> c;
	//odd(c);
	std::cout << "가장 큰 값" << Max(a, b, c)<<std::endl;

}