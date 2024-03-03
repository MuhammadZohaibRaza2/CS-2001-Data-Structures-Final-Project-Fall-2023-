#pragma once
#include "BTree.h"
class Machine;

class FRTNode
{
public:
	Machine* machine;
	FRTNode* prev;
	FRTNode* next;
public:
	FRTNode(Machine* machine)
	{
		this->machine = machine;
		prev = nullptr;
		next = nullptr;
	}

	Machine* getmachine()
	{
		return machine;
	}

	FRTNode* getPrev()
	{
		return prev;
	}

	FRTNode* getNext()
	{
		return next;
	}

	void setMachine(Machine* machine)
	{
		this->machine = machine;
	}

	void setPrev(FRTNode* prev)
	{
		this->prev = prev;
	}

	void setNext(FRTNode* next)
	{
		this->next = next;
	}
};

class FRT
{
private:
	FRTNode* head;
	int size;
	int current_size;

public:
	FRT(int size)
	{

		head = nullptr;
		this->size = size;
		current_size = 0;

	}

	FRTNode* gethead()
	{
		return head;
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	void frtinsert(Machine* machine)
	{




		FRTNode* newNode = new FRTNode(machine);
		if (head == nullptr)
		{
			newNode->setPrev(newNode);
			newNode->setNext(newNode);
			head = newNode;
		}
		else
		{
			head->getPrev()->setNext(newNode);
			newNode->setPrev(head->getPrev());
			newNode->setNext(head);
			head->setPrev(newNode);

		}
		current_size++;
	}

	Machine* atIndex(int index)
	{
		if (index < 0 || index >= current_size)
		{
			return nullptr;
		}
		FRTNode* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->getNext();
		}
		return current->getmachine();
	}


	void clearfrt() {

		if (head != NULL) {
			FRTNode* temp, * current;
			current = head->next;
			while (current != head) {
				temp = current->next;
				free(current);
				current = temp;
			}
			free(head);
			head = NULL;
		}
	}


	int getCurrent_Size()
	{
		return current_size;
	}
};




//////////////////////////////////////////////////////////////////////////////////

class Machine : public FRT
{
private:
	string name;
	BigInt id;
	string machineHash;
	BTree* tree;


public:
	Machine(string name, BigInt id, int order);
	~Machine();
	string getName();
	BigInt getId();
	BTree* getTree();


	void setName(string name);
	void setId(BigInt id);
	void setTree(BTree* tree);

	void calculateMachineHash();

	void insertFile(File* file);
	bool deleteFile(BigInt file);
	File* searchFile(BigInt id);
	File* searchFileByName(string name);
	void printFiles();
	void setMachineHash(string machineHash);
	string getMachineHash();

	void printFRT();

};

Machine::Machine(string name, BigInt id, int order) : FRT(order)
{
	this->name = name;
	this->calculateMachineHash();
	this->tree = new BTree(order);
	this->id = id;

}


void Machine::printFiles()
{
	cout << "Files stored on machine " << this->name << " (" << this->id << ") : " << endl;
	this->tree->traverse();
	cout << endl;
}


File* Machine::searchFile(BigInt id)
{


	return this->tree->search(id);

}

void Machine::insertFile(File* file)
{
	BigInt fileId = file->getFileId();

	this->tree->insertion(file);

}

bool Machine::deleteFile(BigInt Id)
{
	File* file = this->searchFile(Id);

	return this->tree->deletion(file);

}

Machine::~Machine()
{
	delete tree;
}

string Machine::getName() {
	return this->name;
}

BigInt Machine::getId() {
	return this->id;
}

BTree* Machine::getTree() {
	return this->tree;
}

void Machine::setName(string name) {
	this->name = name;
}

void Machine::setId(BigInt id) {
	this->id = id;
}

void Machine::setMachineHash(string machineHash) {
	this->machineHash = sha1(this->name);
}

string Machine::getMachineHash() {
	return this->machineHash;
}


void Machine::setTree(BTree* tree) {
	this->tree = tree;
}

//FRT* Machine::getFRT() {
//	return this->frt;
//}

void Machine::calculateMachineHash() {
	this->machineHash = sha1(this->name);
}


void Machine::printFRT()
{
	if (FRT::isEmpty())
	{
		cout << "FRT is empty." << endl;
		return;
	}
	FRTNode* current = FRT::gethead();
	int i = 1;
	do
	{
		cout << i <<" :  " << current->machine->getId() << "   "<<current->getmachine()->getName()<<endl;
		current = current->getNext();
	} while (current != FRT::gethead());
	cout << endl;
}


File* Machine::searchFileByName(string name) {
	return this->tree->searchByName(name);
}