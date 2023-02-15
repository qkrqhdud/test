// class_0210.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
using namespace std;

class Snack {
protected:
    string price;
    string name;
    string corp;
    static int count;
public:
    virtual void get_name(){
        cout << name << endl;
    }
    static int get_count() {
        return count;
    }
};
int Snack::count = 0;

class Candy : public Snack {
    string flavor;

public:
    Candy(string flavor, string price,string name,string corp){
        this->flavor = flavor;
        this->price = price;
        this->name = name;
        this->corp = corp;
        count++;

    }
    void get_name() {
        cout <<flavor<<"맛  "<< name << " "<<price<<" 회사 :"<<corp<<endl;
    }
  

};
class Chocolate :public Snack {
    string shape;
public:
    Chocolate(string shape, string price, string name, string corp) {
        this->shape = shape;
        this->price = price;
        this->name = name;
        this->corp = corp;
        count++;

    }
    void get_name() {
        cout << shape << "모양  " << name<< " " << price << " 회사 :" << corp << endl;
    }
};


int main()
{
    int num;
    string price;
    string name;
    string corp;
    string flavor;
    string shape;
    
    std::vector<Snack*> snacks;

    while (1) {
        cout << "과자 바구니에 추가할 간식을 고르시오( 1: 사탕, 2:초콜릿, 0:종료) :";
        cin >> num;
        switch (num) {
        case 1: {
            cout << "맛을 입력하세요 : ";
            cin >> flavor;
            cout << "가격을 입력하세요 : ";
            cin >> price;
            cout << "이름을 입력하세요 : ";
            cin >> name;
            cout << "회사을 입력하세요 : ";
            cin >> corp;

            snacks.push_back(new Candy(flavor,price,name,corp));
            break;
            
        }
        case 2: {
            cout << "모양을 입력하세요 : ";
            cin >> shape;
            cout << "가격을 입력하세요 : ";
            cin >> price;
            cout << "이름을 입력하세요 : ";
            cin >> name;
            cout << "회사을 입력하세요 : ";
            cin >> corp;

            snacks.push_back(new Chocolate(shape, price, name, corp));
            break;
        }
        case 0: {
            cout << "과자바구니에 담긴 간식의 개수는 " << Snack::get_count() << "개 입니다.\n" << endl;
            cout << " 과자 바구니에 담긴 간식 확인하기!\n" << endl;
            for (int i = 0; i < Snack::get_count(); i++) {
                snacks[i]->get_name();
               
            }
            return -1;
        }
        default: {
            cout << "0~2 사이의 숫자를 입력하세요." << endl;
        }

        }
    }

}

//class Shape {
//protected:
//	virtual void draw() = 0;
//};
//class Circle : public Shape {
//public:
//	void draw() {
//		cout << "Circle \n";
//	}
//};
//class Rect : public Shape {
//public:
//	void draw() {
//		cout << "Rect \n";
//	}
//};
//class Tria : public Shape {
//public:
//	void draw() {
//		cout << "Tria \n";
//	}
//};
//int main() {
//	Circle C;
//	Rect R;
//	Tria T;
//	C.draw();
//	T.draw();
//	R.draw();
//}

