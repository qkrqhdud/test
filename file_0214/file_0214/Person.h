#pragma once
#include<iostream>
using namespace std;

#ifndef __PRESON__H__
#define __PRESON__H__

class Person {
protected:
	string name;
	static int count; // 객체 별로 공간이 따로 할당되지 않고, 모든 객체가 같은 공간을 공유.
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