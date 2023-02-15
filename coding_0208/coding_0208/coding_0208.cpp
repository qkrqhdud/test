//#include <iostream>
//
using namespace std;//
////private > protected > public
////class Shape {
////
////protected:
////	double width;
////	int num;
////public:
////	Shape(double width,int num) {
////		this->width = width;
////		this->num = num;
////	}
////	void printInfo() {
////		cout << "밑변의 길이: " << width << endl << "변의 갯수 :" << num <<endl;
////	}
////
////};
////class Rectangle : public Shape {
////	double length; //세로
////public:
////	Rectangle(double length, double width, int num) : Shape(width, num) {
////		this-> length = length;
////	}
////
////	void area() {
////		cout << "사각형 넓이 : " << length * width<<endl;
////	}
////
////};
////
////class Triangle :public Shape {
////	double height;// 높이
////public:
////	Triangle(double height, double width,int num) : Shape(width,num) {
////		this->height = height;
////	}
////
////	void area() {
////		cout << "삼각형 넓이 : " << width * height<<endl;
////	}
////};
////
////
////
////int main() {
////	double height, width, lenght;
////	int num;
////	while (1) {
////		cout << "변의 갯수를 입력하세요 : ";
////		cin >> num;
////		switch (num)
////		{
////		case 3:
////		{cout << "높이와 밑변의 길이를 입력하세요 : ";
////		cin >> height >> width;
////		Triangle T(height, width, num);
////		T.area();
////		T.printInfo();
////		break; 
////		}
////		case 4:
////		{cout << "세로와 밑변의 길이를 입력하세요 : ";
////		cin >> lenght >> width;
////		Rectangle R(lenght, width, num);
////		R.area();
////		R.printInfo();
////		break;
////		}
////		default:
////			cout << "잘못입력했습니다 변의갯수는 : 3 or 4 \n";
////			break;
////		}
////
////	}
////}
//	
//	/*Triangle T(4,3.5,3);
//	Rectangle R(4, 3.5, 4);
//	T.area();
//	R.area();
//	T.printInfo();
//	R.printInfo();*/
//
//class Student {
//private:
//	string name;
//	string school;
//	string num;
//public:
//	Student() {
//
//	}
//	Student(string name, string school, string num) {
//		this->name = name;
//		this->school = school;
//		this->num = num;
//	}
//	void Info() {
//		cout << "이름 : " << name << endl << "학교 : " << school << endl << "학번 : " << num << endl;
//	}
//	void lunch() {
//		Info();
//		cout << "점심은 학식\n " << endl;
//	}
//	void lunch(string bob) {
//		cout << "점심은 :" << bob<<endl;
//	}
// };
//
//class Kim :public Student {	
//public:
//	Kim(string name, string school, string num) : Student(name, school, num) {
//	}
//	void lunch() {
//		Info();
//		cout << "점심은 김가네 김밥\n " << endl;
//	}
//};
//
//class Baek :public Student {
//public:
//	Baek(string name, string school, string num) : Student(name, school, num) {
//
//	}
//	void lunch() {
//		Info();
//		cout << "점심은 백종원 피자 " << endl;
//	}
//};
//
//int main() {
//	Student S;
//	Kim K("양윤호", "분식대학교", "11111");
//	Baek B("백종원", "설탕대학교", "22222");
//	S.lunch("떡볶이");
//	S.lunch();
//	K.lunch();
//	B.lunch();
//}

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//private > protected > public
class Person {
protected:
	string name;
public:
	Person() {}
	string get_name() {
		return name;
	}
	void show() {
		cout << "나는 사람이야 \n";
	}
	void show(int a) {
		cout << "나는 사람이야 2 \n";
	}
};

class Student : public Person { // 기본값 private
	string stu_id;
public:
	Student() : Person() {}

	using Person::show;
	void show() {
		cout << "나는 학생이야 \n";
	}
};


int main() {
	Student s2;
	s2.show();
	s2.show(1);
	// 오류가 난다
	// 둘 중에 하나가 실행될 것 같다.

	return 0;
}