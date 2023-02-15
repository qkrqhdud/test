#include "Person.h"

int Person::count = 0;

void Person:: static_method(){
	cout << "스태틱 메소드 테스트" << endl;
}
int Person::get_count() {
	return count;
}
Person::Person() {
	this->name = "아무개";
	count++;
}
Person:: ~Person() {
	cout << "사람의 소멸자입니다." << endl;
	count--;
}
void Person::info(){
	cout << "사람입니다." << endl;
}
void Person::set_name(string name) {
	this->name = name;
}
string Person::get_name() {
	return name;
}