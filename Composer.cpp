#include "Composer.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


Composer::Composer(int newYear, string newName) {
	year = newYear;
	name = newName;
}

//Composer* Composer::createLinkedList(Composer& obj) {
//	ifstream inFile;
//	int counter = 0;
//	inFile.open("composers.txt");
//	if (!inFile) {
//		cout << "Error opening the file" << endl;
//	}
//	else {
//		string compName;
//		string temp;
//		int compYear;
//		Composer tmp;
//		LinkedList<Composer> val;
//		Node<Composer>* objFirst;
//
//		while (!inFile.eof()) {
//			getline(inFile, compName, ',');
//			inFile.ignore();
//
//			getline(inFile, temp);
//
//			compYear = stoi(temp);
//
//
//			tmp.name = compName;
//			tmp.year = compYear;
//			/*if (counter == 1) {
//				objFirst = &obj;
//			}*/
//			val.insert(tmp);
//			counter++;
//		}
//
//		val.printList();
//
//		return (val.getFirstPtr());
//	}
//}
bool Composer::operator < (const Composer& rhs) const{
	return (year < rhs.year);
}
bool Composer::operator > (const Composer& rhs) const{
	return (year > rhs.year);
}

ostream& operator << (ostream& out, const Composer& obj) {
	out << obj.name << " " << obj.year;

	return out;
}