#include <iostream>
using namespace std;

#ifndef COMPOSER_H
#define COMPOSER_H

class Composer {
public:
	string name;
	int year;

	Composer(int year = -1, string name = " ");

	Composer* createLinkedList(Composer&);

	bool operator < (const Composer& rhs) const;
	bool operator > (const Composer& rhs) const;
	//bool operator == (const Composer rhs);
	friend ostream& operator << (ostream& out, const Composer& obj);

};



#endif // !COMPOSER_H
