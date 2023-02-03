// 0203_cod.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
//using namespace std;
//#include <iostream>
//int main() {
//	double nums[3] = { 1.5, 2.5, 3.5 };
//
//	std::string fruit[2][3] = {
//		{ "apple", "banana", "orange"},
//		{ "apple2", "banana2", "orange2" }
//	};
//
//	// fruit[1] = { "apple2", "banana2", "orange2" }
//
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 3; j++) {
//			std::cout << fruit[i][j] << std::endl;
//		}
//	}
//
//	for (auto& f : fruit) {
//		for (std::string f2 : f) {
//			std::cout << f2 << std::endl;
//		}
//	}
//
//	std::cout << fruit << std::endl;
//
//	std::string friends[] = { "홍길동", "성춘향", "코딩온" };
//	/*std::cout << friends[0] << std::endl;
//	std::cout << friends[1] << std::endl;
//	std::cout << friends[2] << std::endl;*/
//
//	for (int i = 0; i < 3; i++) {
//		std::cout << friends[i] << std::endl;
//	}
//
//	// sizeof() : sizeof 안에 변수 or type을 인자로 넘겨줌. 크기를 byte단위로 구함.
//	// sizeof(friends)/sizeof(friends[0])
//	for (int i = 0; i < sizeof(friends) / sizeof(std::string); i++) {
//		std::cout << friends[i] << std::endl;
//	}
//
//	for (std::string f : friends) {
//		// f = "홍길동"
//		// f = "성춘향" 로 바뀜
//		// f = "코딩온" 로 바뀜
//		std::cout << f << std::endl;
//	}
//
//
//	// friends = { "홍길동", "성춘향" }
//	return 0;
//}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

int main() {

	int grade[5] ;
	int a;
	int sum = 0;
	for (int i=0 ; i<5;i++){
		std::cout << i+1<<"번째 학생의 성적을 입력하세요 :" << std::endl;
		std::cin >> grade[i];
	
		sum += grade[i];

	}
	std::cout << "성적평균 :" << sum / 5;
	


}