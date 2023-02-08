#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// input file stream -> ifstream
// ouput file stream -> ofstream

bool checkFileOpen(std::ifstream& file) {
	if (file.fail()) {
		cout << "���� ����" << endl;
		return false;
	}
	else return true;
}

int main() {
	string password;
	string name;
	string number;

	cout << "�̸��� �Է��ϼ��� :";
	cin >> name;
	cout << "��й�ȣ�� �Է��ϼ��� :";
	cin >> password;
	string login = name + " " + password;
	std::ifstream file_r("member.txt");
	if (!checkFileOpen(file_r)) return -1;

	std::string line, file_content = "";
	while (std::getline(file_r, line)) {
		// file_content = file_content + line + "\n";
		if (line == login) {
			cout << "�α��� ����"<<endl;
			break;
		}
	}
	if (line != login) {
		cout << "�α��� ����"<<endl;
		return -1;
	}

	cout << "��ȭ��ȣ�� �Է����ּ���(010-OOOO-OOOO) :";
	cin >> number;
	string tel = name + " " + number;
	int count = 1;
	std::ifstream file_m("member_tel.txt");
	while (std::getline(file_m, line)) {
		if (line.substr(0, name.size()) == name) {
			line = tel;
			count--;
		}
		file_content += line + "\n";
	}

	if (count) {
		std::ofstream file("member_tel.txt", std::ios::app);
		if (file.fail()) {
			cout << "���� ����" << endl;
			return -1;
		}
		file << tel<<"\n";
	}
	else {
		std::ofstream file("member_tel.txt");
		if (file.fail()) {
			cout << "���� ����" << endl;
			return -1;
		}
		file << file_content;
	}
	return 0;
}