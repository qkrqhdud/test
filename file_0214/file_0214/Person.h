#pragma once
#include<iostream>
using namespace std;

#ifndef __PRESON__H__
#define __PRESON__H__

class Person {
protected:
	string name;
	static int count; // ��ü ���� ������ ���� �Ҵ���� �ʰ�, ��� ��ü�� ���� ������ ����.
public:
	static void static_method();
	static int get_count();
	Person();
	virtual ~Person();
	virtual void info();
	void set_name(string name);
	string get_name();
};



#endif