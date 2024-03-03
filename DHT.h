#pragma once
#include<cstring>
#include "Machine.h"
#include "HexToDec.h"
class DHTNode {
private:
	Machine* machine;
	DHTNode* next;
public:
	DHTNode(string name, BigInt id, int order) {
		this->machine = new Machine(name, id, order);
		next = nullptr;
	}
	Machine* getMachine() {
		return machine;
	}
	DHTNode* getNext() {
		return next;
	}
	void setMachine(Machine* machine) {
		this->machine = machine;
	}
	void setNext(DHTNode* next) {
		this->next = next;
	}
};

class DHT {
private:
	DHTNode* head;
	DHTNode* current;
	BigInt max_Size;
	BigInt curr_Size;
	int order;
public:
	DHT(int order) {
		head = nullptr;
		current = nullptr;
		this->order = order;
		BigInt pwr = order;
		BigInt base = 2;
		this->max_Size = pwr.power(base, pwr);
		curr_Size = 0;
	}

	DHTNode* getHead() {
		return head;
	}

	DHTNode* getCurrent() {
		return current;
	}
	BigInt getMax_Size() {
		return max_Size;
	}
	BigInt getCurr_Size() {
		return curr_Size;
	}
	int getOrder() {
		return order;
	}

	void setHead(DHTNode* head) {
		this->head = head;
	}
	void setCurrent(DHTNode* current) {
		this->current = current;
	}
	void setMax_Size(BigInt max_Size) {
		this->max_Size = max_Size;
	}
	void setCurr_Size(BigInt curr_Size) {
		this->curr_Size = curr_Size;
	}
	void setOrder(int order) {
		this->order = order;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	Machine* search(string name) {
		if (isEmpty()) {
			return nullptr;
		}
		DHTNode* current = head->getNext();
		do {
			if (current->getMachine()->getName() == name) {
				return current->getMachine();
			}
			current = current->getNext();
		} while (current != head->getNext());
		return nullptr;
	}

	Machine* search(BigInt id) {
		if (isEmpty()) {
			return nullptr;
		}
		DHTNode* current = head->getNext();
		do {
			if (current->getMachine()->getId() == id) {
				return current->getMachine();
			}
			current = current->getNext();
		} while (current != head->getNext());
		return nullptr;
	}


	BigInt randomizeId(string name) {
		BigInt zero = 0;
		BigInt id = convertHextoDec(sha1(name));
		id = id.Mod(id, max_Size);
		return id;
	}

	void insert(string name, BigInt id = 0) {
		if (curr_Size == max_Size) {
			cout << "DHT is full." << endl;
			return;
		}
		BigInt zero = 0;
		while (id == zero) {
			id = randomizeId( name);
			if (search(id) != nullptr) {
				id = zero;
			}
		}

		DHTNode* newNode = new DHTNode(name, id, this->order);
		if (head == nullptr) {
			newNode->setNext(newNode);
			head = newNode;
		}
		DHTNode* current = head;
		DHTNode* prev = head;
		do {

			if (current->getMachine()->getId() > id) {
				break;
			}
			prev = current;
			current = current->getNext();

		} while (current != head);
		DHTNode* temp = prev->getNext();
		prev->setNext(newNode);
		newNode->setNext(temp);
		curr_Size++;
		update_FRT();
	}

	bool deleteMachine(BigInt Id) {
		if (isEmpty()) {
			return false;
		}
		DHTNode* current = head->getNext();
		DHTNode* prev = head;
		do {
			if (current->getMachine()->getId() == Id) {
				prev->setNext(current->getNext());
				if (current == head) {
					head = prev;
				}

				BTree* tree = current->getMachine()->getTree();
				File** files = nullptr;
				int index = 0;
				tree->traversetoCopy(files, index);
				delete current;
				for (int i = 0; i < index; i++)
				{
					insertFiletoMachine(files[i]);
				}
				curr_Size--;
				update_FRT();
				return true;
			}
			prev = current;
			current = current->getNext();
		} while (current != head->getNext());
		return false;
	}

	bool deleteMachine(string name) {

		return deleteMachine(search(name)->getId());
	}
	bool delteMachineByID(BigInt id) {
		if (search(id)->getId()) {
						return deleteMachine(id);
		}
		else {
						return false;
		}
	}


	void printDHTByName() {
		if (isEmpty()) {
			cout << "List is empty." << endl;
			return;
		}
		DHTNode* current = head->getNext();
		do {
			cout << current->getMachine()->getName() << "  ";
			current = current->getNext();
		} while (current != head->getNext());
		cout << endl;
	}
	void printDHTById() {
		if (isEmpty()) {
			cout << "List is empty." << endl;
			return;
		}
		DHTNode* current = head->getNext();
		do {
			cout << current->getMachine()->getName() << "     " << current->getMachine()->getId() << endl;
			current = current->getNext();
		} while (current != head->getNext());
		cout << endl;
	}

	Machine* Search_FRT(BigInt id) {
		if (isEmpty()) {
			return nullptr;
		}
		if (id == 0)
		{
			return head->getMachine();
		}
		DHTNode* current = head;
		do {
			if (current->getMachine()->getId() == id) {
				return current->getMachine();
			}
			current = current->getNext();
		} while (current->getMachine()->getId() < id && current != head);
		return current->getMachine();

	}


	void update_FRT() {
		if (isEmpty()) {
			return;
		}
		DHTNode* current = head;
		do {
			current->getMachine()->clearfrt();
			for (int i = 0; i < order; i++) {
				BigInt base = 2;
				BigInt index = current->getMachine()->getId() + base.power(base, i);
				index = base.Mod(index, max_Size);
				Machine* temp = Search_FRT(index);
				current->getMachine()->frtinsert(temp);
			}
			current = current->getNext();
		} while (current != head);
	}


	void insertFiletoMachine(File* file) {
		if (isEmpty()) {
			return;
		}
		Machine* current;
		if (this->current == nullptr)
		{
			current = head->getMachine();
		}
		else
		{
			current = this->current->getMachine();
		}
		BigInt fileId = file->getFileId();
		BigInt dd = string(fileId);
		fileId = fileId.Mod(fileId, max_Size);
		string iddd = string(fileId);
		cout << iddd << endl;
		bool insert = false;
		do {

			for (int i = 0; i < order; i++) {

				BigInt bb = current->atIndex(i)->getId();
				string curid = string(bb);
				if (i == 0)
				{
					if (fileId < current->atIndex(i)->getId())
					{
						if (this->current && this->current->getMachine() == current) {
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							break;
						}

						cout << "Control shifted from machine : " << current->getId();
						current = current->atIndex(i);
						cout << " to machine : " << current->getId() << endl;
						insert = true;
						break;
					}
				}
				else
				{

					if (current->atIndex(i)->getId() > fileId && current->atIndex(i - 1)->getId() < fileId)
					{
						cout << "Control shifted from machine : " << current->getId();
						current = current->atIndex(i - 1);
						cout << " to machine : " << current->getId() << endl;
						break;
					}
					else if (i == order - 1)
					{
						if (current->getId() > current->atIndex(i)->getId()) {
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							insert = true;
						}
						else if (current->getId() != current->atIndex(i)->getId())
						{
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							break;
						}
						else {
							cout << "Control shifted from machine : " << current->getId();
							current = getnextmachine(current);
							cout << " to machine : " << current->getId() << endl;
							break;
						}
					}
				}

			}
			if (insert)
			{
				current->insertFile(file);
				cout << "File is Inserted in machine : " << current->getId() << "  " << current->getName() << endl;
				return;
				break;
			}

		} while (current != head->getMachine());
		current->insertFile(file);
		cout << "File is Inserted in machine : " << current->getId() << "  " << current->getName() << endl;
		return;

	}


	bool chkfullfrt(Machine* current, BigInt idofFile, int& index) {
		for (int i = 0; i < order; i++)
		{
			BigInt bb = current->atIndex(i)->getId();
			string curid = string(bb);
			if (current->atIndex(i)->getId() == idofFile)
			{
				return false;
			}
			else if (current->atIndex(i)->getId() > idofFile)
			{
				continue;
			}
			else if (current->atIndex(i)->getId() < idofFile)
			{
				index = i;
				return true;
			}
		}
		return false;
	}

	File* searchFilefromMachine(string hash) {
		if (isEmpty()) {
			return nullptr;
		}
		Machine* current;
		if (this->current == nullptr)
		{
			current = head->getMachine();
		}
		else {
			current = this->current->getMachine();
		}
		File* file = nullptr;
		BigInt fileId = convertHextoDec(hash);
		fileId = fileId.Mod(fileId, max_Size);
		string iddd = string(fileId);
		cout << iddd << endl;
		bool insert = false;
		do {

			for (int i = 0; i < order; i++) {

				BigInt bb = current->atIndex(i)->getId();
				string curid = string(bb);
				if (i == 0)
				{
					if (fileId < current->atIndex(i)->getId())
					{
						if (this->current && this->current->getMachine() == current) {
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							break;
						}

						cout << "Control shifted from machine : " << current->getId();
						current = current->atIndex(i);
						cout << " to machine : " << current->getId() << endl;
						insert = true;
						break;
					}
				}
				else
				{

					if (current->atIndex(i)->getId() > fileId && current->atIndex(i - 1)->getId() < fileId)
					{
						cout << "Control shifted from machine : " << current->getId();
						current = current->atIndex(i - 1);
						cout << " to machine : " << current->getId() << endl;
						break;
					}
					else if (i == order - 1)
					{
						if (current->getId() > current->atIndex(i)->getId()) {
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							insert = true;
						}
						else if(current->getId()!=current->atIndex(i)->getId())
						{
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							break;
						}
						else {
							cout << "Control shifted from machine : " << current->getId();
							current = getnextmachine(current);
							cout << " to machine : " << current->getId() << endl;
							break;
						}
					}
				}

			}
			if (insert)
			{
				
				if (current->searchFile(fileId)) {
					cout << "File is Found from machine : " << current->getId() << "  " << current->getName() << endl;
				    return current->searchFile(fileId);
				}
				
				break;
			}

		} while (current != head->getMachine());
		if (current->searchFile(fileId)) {
			cout << "File is Found from machine : " << current->getId() << "  " << current->getName() << endl;
			return current->searchFile(fileId);
		}
		return file;
	}

	Machine* getnextmachine(Machine* current) {
		DHTNode* temp = head;
		do {
			  temp = temp->getNext();
		}while(temp->getMachine()!=current);
		return temp->getNext()->getMachine();
	}

	bool deleteFilefromMachine(string hash) {
		if (isEmpty()) {
			return false;
		}
		Machine* current;
		if (this->current == nullptr)
		{
			current = head->getMachine();
		}
		else {
			current = this->current->getMachine();
		}
		File* file = nullptr;
		BigInt fileId = convertHextoDec(hash);
		fileId = fileId.Mod(fileId, max_Size);
		string iddd = string(fileId);
		bool insert = false;
		do {

			for (int i = 0; i < order; i++) {

				BigInt bb = current->atIndex(i)->getId();
				string curid = string(bb);
				if (i == 0)
				{
					if (fileId < current->atIndex(i)->getId())
					{
						if (this->current && this->current->getMachine() == current) {
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							break;
						}

						cout << "Control shifted from machine : " << current->getId();
						current = current->atIndex(i);
						cout << " to machine : " << current->getId() << endl;
						insert = true;
						break;
					}
				}
				else
				{

					if (current->atIndex(i)->getId() > fileId && current->atIndex(i - 1)->getId() < fileId)
					{
						cout << "Control shifted from machine : " << current->getId();
						current = current->atIndex(i - 1);
						cout << " to machine : " << current->getId() << endl;
						break;
					}
					else if (i == order - 1)
					{
						if (current->getId() > current->atIndex(i)->getId()) {
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							insert = true;
						}
						else if (current->getId() != current->atIndex(i)->getId())
						{
							cout << "Control shifted from machine : " << current->getId();
							current = current->atIndex(i);
							cout << " to machine : " << current->getId() << endl;
							break;
						}
						else {
							cout << "Control shifted from machine : " << current->getId();
							current = getnextmachine(current);
							cout << " to machine : " << current->getId() << endl;
							break;
						}
					}
				}

			}
			if (insert)
			{
				
				
				break;

			}

		} while (current != head->getMachine());
		if (current->deleteFile(fileId)) {
			cout << "File is deleted from machine : " << current->getId() << "  " << current->getName() << endl;
			return true;
		}
		return false;
	}

	bool deleteFilefromMachineByname(string name) {
		return deleteFilefromMachine(sha1(name));
	}
	File* searchFilefromMachineByname(string name) {
		return searchFilefromMachine(sha1(name));
	}


	void printallfrt() {
		DHTNode* current = head->getNext();
		do {
			cout << "Viewing FRT of machine : " << current->getMachine()->getName() << "  " << current->getMachine()->getId() << endl << endl;

			current->getMachine()->printFRT();
			current = current->getNext();
		} while (current != head->getNext());
	}

	void printallBtree() {
		  DHTNode* current = head->getNext();
		do {
			 cout<<"Viewing B-Tree of machine : "<<current->getMachine()->getName()<<"  "<<current->getMachine()->getId() << endl<<endl;
			current->getMachine()->printFiles();
			current = current->getNext();
		} while (current != head->getNext());
	}

};