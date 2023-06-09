#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** Adam, Node** Hanafi);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() {
	int nim;
	string na;
	cout << "\nEnter the rollnumber of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> na;
	Node* newNode = new Node();
	newNode->rollNumber = nim;
	newNode->name = na;
	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST;
		if (LAST != NULL)
			LAST->rollNumber =  NULL;
		newNode->rollNumber = NULL;
		LAST = newNode;
		return;
	}
};
bool CircularLinkedList::search(int rollno, Node** Adam, Node** Hanafi) {
	*Adam = LAST->next;
	*Hanafi = LAST->next;
	while (*Hanafi != LAST) {
		if (rollno == (*Hanafi)->rollNumber) {
			return true;
		} *
			Adam = *Hanafi;
		*Hanafi = (*Hanafi)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {
	Node* Adam, * Hanafi;
	Adam = Hanafi = NULL;
	if (search, &Adam, &Hanafi == false)
		return false;
	if (Hanafi->next != NULL)
		Hanafi->next->next = Adam;
	else
		LAST = Hanafi->next;
	delete Hanafi;
	return true;
};
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch)
			{
			case '1':
				addNode();
				cout << "Data berhasil ditambahkan" << endl;
				system("pause");
				system("cls");
				break;

			
			case '2': if (listEmpty())
			{
				cout << "list kosong" << endl;
				system("pause");
				system("cls");
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': 
			{
				
				return 0;
			}
			default: {
				cout << "Invalid option" << endl; 
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
};