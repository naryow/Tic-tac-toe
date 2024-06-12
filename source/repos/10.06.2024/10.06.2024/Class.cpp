#include <iostream>

using namespace std;

class Animal {
private:
	int x = 0;
	int y = 0;

public:
	void move(int new_x, int new_y) {
		x = new_x;
		y = new_y;
	}

	void get_pos() {
		cout << x << ", " << y << endl;
	}

	void sound() {
		cout << "RRRRR" << endl;
	}
};

class Cat :public Animal {
public:
	void sound() {
		cout << "Myau Myau" << endl;
	}
};

class Dog :public Animal {
public:
	void sound() {
		cout << "Gav Gav" << endl;
	}
};

void test_animal() {
	Dog dog;
	Cat cat;
	dog.sound();
	cat.sound();
}



int main() {
	system("chcp 1251");
	system("cls");


	test_animal();
	
;

	return 0;
}