#pragma once

#include "Person.h"
#ifndef __STUDENT__H__
#define __STUDENT__H__
class Student : public Person {
	string stu_id;
public:
	~Student();
	void info();
	void test();
};

#endif