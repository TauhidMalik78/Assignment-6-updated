#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
#include "Composer.h"
using namespace std;


int main() {
	//LinkedList<int> obj1;

	//cout << boolalpha;
	//cout << obj1.isEmpty() << endl;
	//obj1.insert(35);
	//obj1.insert(15);
	//obj1.insert(67);
	//obj1.insert(69);
	//obj1.append(1);
	//obj1.append(55);
	//obj1.prepend(23333333);
	//obj1.removeFront();
	//obj1.insert(54);
	//obj1.printList();

	//cout << obj1.isEmpty() << endl;
	//cout << obj1.getFirst() << endl;
	//cout << obj1.getLast() << endl;

	//cout << boolalpha;
	//cout << obj1.find(55) << endl;
	//cout << obj1.find(3) << endl;

	/*Composer temp ,temp2;
	bool loop = true;

	temp.createLinkedList(temp2);
	*/

	LinkedList<Composer> obj2;
	ifstream inFile;

	inFile.open("composers.txt");

	if (!inFile) {
		cout << "Error opening the file" << endl;
	}
	else {
		string compName;
		string temp;
		int compYear;
		Composer tmp;
		Node<Composer>* objFirst;

		while (!inFile.eof()) {
			getline(inFile, compName, ',');
			inFile.ignore();

			getline(inFile, temp);

			compYear = stoi(temp);


			tmp.name = compName;
			tmp.year = compYear;
			/*if (counter == 1) {
				objFirst = &obj;
			}*/
			obj2.insert(tmp);
		}
	}

	obj2.printList();
	return 0;
}

