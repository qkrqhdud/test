#include "Person.h"

int Person::count = 0;

void Person:: static_method(){
	cout << "����ƽ �޼ҵ� �׽�Ʈ" << endl;
}
int Person::get_count() {
	return count;
}
Person::Person() {
	this->name = "�ƹ���";
	count++;
}
Person:: ~Person() {
	cout << "����� �Ҹ����Դϴ�." << endl;
	count--;
}
void Person::info(){
	cout << "����Դϴ�." << endl;
}
void Person::set_name(string name) {
	this->name = name;
}
string Person::get_name() {
	return name;
}