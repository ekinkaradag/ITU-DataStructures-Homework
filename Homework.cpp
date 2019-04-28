//
//  main.cpp
//  HWEXercise
//
//  Created by Berkan Yapıcı on 15.04.2019.
//  Copyright © 2019 Berkan Yapıcı. All rights reserved.
//


#include <iostream>
#include <string>

using namespace std;

struct node {
	node* link;
	string name;
	unsigned long long number;
};

class linkedlist {
private:
	node *first, *last; //head and tail nodes of the linkedlist
	unsigned long long length; //length of linkedlist
public:
	linkedlist() { //constructor of the linkedlist
		first = NULL;
		last = NULL;
		length = 0;
	}
	~linkedlist() { //deconstructor of the linkedlist

		node* temp = first;

		while (temp != NULL)
		{
			first = first->link;
			delete temp;
			temp = first;
		}
		last = NULL;
		length = 0;
	}
	unsigned long long length1()const { return length; } //get length of the linkedlist

	void insertBeginning(string na, unsigned long long nu) {

		node *valuenode = new node;
		valuenode->name = na;
		valuenode->number = nu;
		valuenode->link = first;
		first = valuenode;
		if (last == NULL)
		{
			last = valuenode;
		}
		length++;
	}

	void insertAtTheEnd(string na, unsigned long long nu) {
		node *valuenode = new node;

		valuenode->name = na;
		valuenode->number = nu;
		valuenode->link = NULL;

		if (last == NULL) {
			first = last = valuenode;
		}
		else
		{
			last->link = valuenode;
			last = valuenode;
		}
		length++;
	}

	void insertInMiddle(string na, unsigned long long nu) {

		if (first != NULL)
		{
			node *valuenode = new node;
			valuenode->name = na;
			valuenode->number = nu;

			node *prev = new node;
			node *cur = new node;
			cur = first;

			for (unsigned long long i = 0; i < length / 2; i++) {
				prev = cur;
				cur = cur->link;
			}
			prev->link = valuenode;
			valuenode->link = cur;
		}
		else {
			insertBeginning(na, nu);
		}

		length++;

	}

	void addRecord(string na, unsigned long long nu) {

		if (first != NULL)
		{
			node *valuenode = new node;
			valuenode->name = na;
			valuenode->number = nu;

			node *prev = new node;
			node *cur = new node;
			cur = first;
			while (cur->link != NULL)
			{
				if ((strcmp(prev->name.c_str(), na.c_str()) < 0) && (strcmp(cur->name.c_str(), na.c_str()) >= 0)) { //check alphabetically which comes first ( true if prev<na<=cur )
					prev->link = valuenode;
					valuenode->link = cur;
				}
				prev = cur;
				cur = cur->link;
			}
		}
		else {
			insertBeginning(na, nu);
		}

	}

	bool isEmptyList()const {
		if (length == 0)
			return true;
		else
			return false;
	}

	string searchNumber(unsigned long long nu)const {
		node *temp = first;

		while (temp != NULL)
		{
			if (temp->number == nu)
			{
				return temp->name;
			}
			temp = temp->link;
		}

		return "NOT FOUND!";
	}

	unsigned long long searchName(string na)const {
		node *temp = first;

		while (temp != NULL)
		{
			if (temp->name == na)
			{
				return temp->number;
			}
			temp = temp->link;
		}

		return 0; //if the searched name cannot be found in the phonebook
		//Upper and lower case matters
	}

	void printPhoneBook()const {
		node *temp = first;

		if (temp == NULL)
		{
			cout << "Empty Phone List..." << endl;
		}
		else
		{
			while (temp != NULL)
			{

				cout << "Name: " << temp->name << "\t\t\tNumber: " << temp->number << "\n";
				temp = temp->link;
			}
		}
	}

};



int main() {


	linkedlist phonebook;

	phonebook.insertBeginning("a", 314341);
	phonebook.insertBeginning("bc", 32214341);
	phonebook.insertBeginning("de", 3121212);
	phonebook.insertAtTheEnd("ffff", 3121111212);
	phonebook.insertInMiddle("IooooI", 100000000001);
	phonebook.addRecord("dc - alphabetical", 123123123);
	phonebook.printPhoneBook();

}
