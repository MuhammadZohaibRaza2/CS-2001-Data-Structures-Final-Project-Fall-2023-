#pragma once
#include "DHT.h"
#include <Windows.h>
using namespace std;

void setCursorPosition(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(hConsole, pos);
}

void printWelcome() {
	setCursorPosition(56, 4);
	cout << " __      __       .__                               " << endl;
	setCursorPosition(56, 5);
	cout << "/  \\    /  \\ ____ |  |   ____  ____   _____   ____  " << endl;
	setCursorPosition(56, 6);
	cout << "\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ " << endl;
	setCursorPosition(56, 7);
	cout << " \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/ " << endl;
	setCursorPosition(56, 8);
	cout << "  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >" << endl;
	setCursorPosition(56, 9);
	cout << "       \\/       \\/          \\/            \\/     \\/ " << endl;
}

void printTo() {
	setCursorPosition(73, 12);
	cout << " ___________     " << endl;
	setCursorPosition(73, 13);
	cout << "\\__    ___/___  " << endl;
	setCursorPosition(73, 14);
	cout << "  |    | /  _ \\ " << endl;
	setCursorPosition(73, 15);
	cout << "  |    |(  <_> )" << endl;
	setCursorPosition(73, 16);
	cout << "  |____| \\____/ " << endl;
}

void printNebulaNodes1() {
	setCursorPosition(20, 19);
	cout << " _____  ___    _______  _______   ____  ____  ___            __      _____  ___      ______    ________    _______   ________ " << endl;
	setCursorPosition(20, 20);
	cout << "(\"   \\|\"   \\  /\"     \"||   _  \"\\ (\"  _||_ \" ||\"  |          /\"\"\\    (\"    \\|\"  \\    /    \" \\  |\"      \"\\  /\"     \"| /\"       )" << endl;
	setCursorPosition(20, 21);
	cout << "|.\\\\   \\    |(: ______)(. |_)  :)|   (  ) : |||  |         /    \\   |.\\\\   \\    |  // ____  \\ (.  ___  :)(: ______)(:   \\___/ " << endl;
	setCursorPosition(20, 22);
	cout << "|: \\.   \\\\  | \\/    |  |:     \\/ (:  |  | . )|:  |        /' /\\  \\  |: \\.   \\\\  | /  /    ) :)|: \\   ) || \\/    |   \\___  \\   " << endl;
	setCursorPosition(20, 23);
	cout << "|.  \\    \\. | // ___)_ (|  _  \\\\  \\\\ \\__/ //  \\  |___    //  __'  \\ |.  \\    \\. |(: (____/ // (| (___\\ || // ___)_   __/  \\\\  " << endl;
	setCursorPosition(20, 24);
	cout << "|    \\    \\ |(:      \"||: |_)  :) /\\\\ __ //\\ ( \\_|:  \\  /   /  \\\\  \\|    \\    \\ | \\        /  |:       :)(:      \"| /\" \\   :) " << endl;
	setCursorPosition(20, 25);
	cout << " \\___|\\____\\) \\_______)(_______/ (__________) \\_______)(___/    \\___)\\___|\\____\\)  \"_____/    (________/  \\_______)(_______/  " << endl;
}

void printNebulaNodes() {
	setCursorPosition(20, 4);
	cout << " _____  ___    _______  _______   ____  ____  ___            __      _____  ___      ______    ________    _______   ________ " << endl;
	setCursorPosition(20, 5);
	cout << "(\"   \\|\"   \\  /\"     \"||   _  \"\\ (\"  _||_ \" ||\"  |          /\"\"\\    (\"    \\|\"  \\    /    \" \\  |\"      \"\\  /\"     \"| /\"       )" << endl;
	setCursorPosition(20, 6);
	cout << "|.\\\\   \\    |(: ______)(. |_)  :)|   (  ) : |||  |         /    \\   |.\\\\   \\    |  // ____  \\ (.  ___  :)(: ______)(:   \\___/ " << endl;
	setCursorPosition(20, 7);
	cout << "|: \\.   \\\\  | \\/    |  |:     \\/ (:  |  | . )|:  |        /' /\\  \\  |: \\.   \\\\  | /  /    ) :)|: \\   ) || \\/    |   \\___  \\   " << endl;
	setCursorPosition(20, 8);
	cout << "|.  \\    \\. | // ___)_ (|  _  \\\\  \\\\ \\__/ //  \\  |___    //  __'  \\ |.  \\    \\. |(: (____/ // (| (___\\ || // ___)_   __/  \\\\  " << endl;
	setCursorPosition(20, 9);
	cout << "|    \\    \\ |(:      \"||: |_)  :) /\\\\ __ //\\ ( \\_|:  \\  /   /  \\\\  \\|    \\    \\ | \\        /  |:       :)(:      \"| /\" \\   :) " << endl;
	setCursorPosition(20, 10);
	cout << " \\___|\\____\\) \\_______)(_______/ (__________) \\_______)(___/    \\___)\\___|\\____\\)  \"_____/    (________/  \\_______)(_______/  " << endl;
}

void printCaption() {
	setCursorPosition(5, 28);
	cout << " _____                             _   _               _____       _            _             _   _                           _       _________________ _____ " << endl;
	setCursorPosition(5, 29);
	cout << "/  __ \\                           | | (_)             |  __ \\     | |          (_)           | | | |                         | |     |_   _| ___ \\  ___/  ___|" << endl;
	setCursorPosition(5, 30);
	cout << "| /  \\/ ___  _ __  _ __   ___  ___| |_ _ _ __   __ _  | |  \\/ __ _| | __ ___  ___  ___  ___  | |_| |__  _ __ ___  _   _  __ _| |__     | | | |_/ / |_  \\ `--. " << endl;
	setCursorPosition(5, 31);
	cout << "| |    / _ \\| '_ \\| '_ \\ / _ \\/ __| __| | '_ \\ / _` | | | __ / _` | |/ _` \\ \\/ / |/ _ \\/ __| | __| '_ \\| '__/ _ \\| | | |/ _` | '_ \\    | | |  __/|  _|  `--. \\" << endl;
	setCursorPosition(5, 32);
	cout << "| \\__/\\ (_) | | | | | | |  __/ (__| |_| | | | | (_| | | |_\\ \\ (_| | | (_| |>  <| |  __/\\__ \\ | |_| | | | | | (_) | |_| | (_| | | | |  _| |_| |   | |   /\\__/ /" << endl;
	setCursorPosition(5, 33);
	cout << " \\____/\\___/|_| |_|_| |_|\\___|\\___|\\__|_|_| |_|\\__, |  \\____/\\__,_|_|\\__,_/_/\\_\\_|\\___||___/  \\__|_| |_|_|  \\___/ \\__,_|\\__, |_| |_|  \\___/\\_|   \\_|   \\____/ " << endl;
	setCursorPosition(5, 34);
	cout << "                                                __/ |                                                                    __/ |                                " << endl;
	setCursorPosition(5, 35);
	cout << "                                               |___/                                                                    |___/                                 " << endl;
}

void Menu() {
	printNebulaNodes();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Enter your name: ";
	string name;
	cin >> name;
	system("cls");
	printNebulaNodes();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Hello " << name << endl;
	system("timeout 5");
	system("cls");
	printNebulaNodes();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Enter the Number of Bits for the DHT (2-160): ";
	int bits;
	cin >> bits;
	while (bits < 2 || bits > 160) {
		cout<<"Invalid number of bits!!!!!!!!!!"<<endl;
		cout << "Please enter valid Number of Bits for the DHT (2-160): ";
		cin >> bits;
	}
	DHT dht(bits);
	
	system("timeout 5");
	bool mainMenu = true;
	while (mainMenu) {
		system("cls");
		printNebulaNodes();
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "****************MainMenu****************" << endl;
		cout << "1. Perform operation on file" << endl;
		cout << "2. Perform operation on machine" << endl;
		cout << "3. View FRT of machine" << endl;
		cout << "4. View BTree of machine" << endl;
		cout << "5. View DHT" << endl;
		cout << "6. Generate Hash" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter you choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			bool fileMenu = true;
			while (fileMenu) {
				system("cls");
				printNebulaNodes();
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "*****Performing operation on file*****" << endl;	
				cout << "1. Add file" << endl;
				cout << "2. Get file" << endl;
				cout << "3. Remove file" << endl;
				cout << "4. Return" << endl;
				cout << "0. Exit" << endl;
				cout << "Enter your choice: ";
				int choice1;
				cin >> choice1;
				switch (choice1)
				{
				case 1:
				{
					bool fileMenu1 = true;
					while (fileMenu1) {
						system("cls");
						printNebulaNodes();
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "****************AddingFile****************" << endl;
						cout << "1. Add file by path" << endl;
						cout << "2. Return" << endl;
						cout << "0. Exit" << endl;
						cout << "Enter your choice: ";
						int choice2;
						cin >> choice2;
						switch (choice2)
						{
						case 1:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter path of file: ";
							string path;
							cin >> path;

							File* file = new File(path);

							if (dht.isEmpty()) {
								cout<<"Error... DHT is empty"<<endl;
							}
							else {
							/*	ifstream inputFile("test2.txt");
								if (inputFile.is_open()) {
									dht.insertFiletoMachine(file);
								}
								else {
									cout << "File does not exist." << endl;
								}
								inputFile.close();*/
								dht.insertFiletoMachine(file);
							}
							
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to add more files? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								fileMenu1 = false;
							}
						}
						break;
						
						case 2:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Returning****************" << endl;
							system("timeout 5");
							fileMenu1 = false;
						}
						break;
						case 0:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Exiting****************" << endl;
							system("timeout 5");
							fileMenu1 = false;
							fileMenu = false;
							mainMenu = false;
						}
						break;
						default:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************InvalidChoice****************" << endl;
							system("timeout 5");
							continue;
						}
						}
					}
				}
				break;
				case 2:
				{
					bool fileMenu1 = true;
					while (fileMenu1) {
						system("cls");
						printNebulaNodes();
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "****************GettingFile****************" << endl;
						cout << endl;
						cout << "1. Get file by path" << endl;
						cout << "2. Get file by hash" << endl;
						cout << "3. Return" << endl;
						cout << "0. Exit" << endl;
						cout << "Enter your choice: ";
						int choice2;
						cin >> choice2;
						switch (choice2)
						{
						case 1:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter path of file: ";
							string path;
							cin >> path;
							if (dht.searchFilefromMachineByname(path) == nullptr) {
								cout<<"File not found"<<endl;
							}
							else {
								cout<<"File found"<<endl;
							}
							
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to get more files? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								fileMenu1 = false;
							}
						}
						break;
						case 2:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter hash of file: ";
							string hash;
							cin >> hash;
							if (dht.searchFilefromMachine(hash) == nullptr) {
								cout<<"File not found"<<endl;
							}
							else {
								cout<<"File found"<<endl;
							}
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to get more files? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								fileMenu1 = false;
							}
						}
						break;
						case 3:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Returning****************" << endl;
							system("timeout 5");
							fileMenu1 = false;
						}
						break;
						case 0:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Exiting****************" << endl;
							system("timeout 5");
							fileMenu1 = false;
							fileMenu = false;
							mainMenu = false;
						}
						break;
						default:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************InvalidChoice****************" << endl;
							system("timeout 5");
							continue;

						}
						}
					}
				}
				break;
				case 3:
				{
					bool fileMenu1 = true;
					while (fileMenu1) {
						system("cls");
						printNebulaNodes();
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "****************RemovingFile****************" << endl;
						cout << "Removing file" << endl;
						cout << "1. Remove file by path" << endl;
						cout << "2. Remove file by hash" << endl;
						cout << "3. Return" << endl;
						cout << "0. Exit" << endl;
						cout << "Enter your choice: ";
						int choice2;
						cin >> choice2;
						switch (choice2)
						{
						case 1:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter path of file: ";
							string path;
							cin >> path;
							if (dht.deleteFilefromMachineByname(path) == false) {
								cout<<"File not found....."<<endl;
							}
							else {
								cout << "File removed" << endl;
							}
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to remove more files? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								fileMenu1 = false;
							}
						}
						break;
						case 2:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter hash of file: ";
							string hash;
							cin >> hash;
							if (dht.deleteFilefromMachine(hash) == false) {
								cout<<"File not found....."<<endl;
							}
							else {
								cout << "File removed" << endl;
							}
							
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to remove more files? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								fileMenu1 = false;
							}
						}
						break;
						case 3:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Returning****************" << endl;
							system("timeout 5");
							fileMenu1 = false;
						}
						break;
						case 0:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Exiting****************" << endl;
							system("timeout 5");
							fileMenu1 = false;
							fileMenu = false;
							mainMenu = false;
						}
						break;
						default:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************InvalidChoice****************" << endl;
							system("timeout 5");
							continue;
						}
						}
					}
				}
				break;
				case 4:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Returning****************" << endl;
					system("timeout 5");
					fileMenu = false;
				}
				break;
				case 0:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Exiting****************" << endl;
					system("timeout 5");
					fileMenu = false;
					mainMenu = false;
				}
				break;
				default:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************InvalidChoice****************" << endl;
					system("timeout 5");
					continue;
				}
				}
			}
		}
		break;
		case 2:
		{
			bool machineMenu = true;
			while (machineMenu) {
				system("cls");
				printNebulaNodes();
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "*****Performing operation on machine*****" << endl;
				cout << "1. Add machine" << endl;
				cout << "2. Get machine" << endl;
				cout << "3. Remove machine" << endl;
				cout << "4. Return" << endl;
				cout << "0. Exit" << endl;
				cout << "Enter your choice: ";
				int choice1;
				cin >> choice1;
				switch (choice1)
				{
				case 1:
				{
					bool machineMenu1 = true;
					while (machineMenu1) {
						system("cls");
						printNebulaNodes();
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "****************AddingMachine****************" << endl;
						cout << "Adding machine" << endl;
						cout << "1. Add machine by name" << endl;
						cout << "2. Add machine by Id" << endl;
						cout << "3. Return" << endl;
						cout << "0. Exit" << endl;
						cout << "Enter your choice: ";
						int choice2;
						cin >> choice2;
						switch (choice2)
						{
						case 1:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter name of machine: ";
							string path;
							cin >> path;
							dht.insert(path);
							cout << "Machine added" << endl;
							system("timeout 5");
							system("cls");
							cout << "Do you want to add more machines? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								machineMenu1 = false;
							}
						}
						break;
						case 2:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter name of machine: ";
							string name;
							cin >> name;
							cout << "Enter Id of machine: ";
						    BigInt Id;
							cin >> Id;
							dht.insert(name, Id);
							cout << "Machine added" << endl;
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to add more machines? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								machineMenu1 = false;
							}
						}
						break;
						case 3:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Returning****************" << endl;
							system("timeout 5");
							machineMenu1 = false;
						}
						break;
						case 0:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Exiting****************" << endl;
							system("timeout 5");
							machineMenu1 = false;
							machineMenu = false;
							mainMenu = false;
						}
						break;
						default:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************InvalidChoice****************" << endl;
							system("timeout 5");
							continue;
						}
						}
					}
				}
				break;
				case 2:
				{
					bool machineMenu1 = true;
					while (machineMenu1) {
						system("cls");
						printNebulaNodes();
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "****************GettingMachine****************" << endl;
						cout << "Getting machine" << endl;
						cout << "1. Get machine by path" << endl;
						cout << "2. Get machine by Id" << endl;
						cout << "3. Return" << endl;
						cout << "0. Exit" << endl;
						cout << "Enter your choice: ";
						int choice2;
						cin >> choice2;
						switch (choice2)
						{
						case 1:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter path of machine: ";
							string path;
							cin >> path;
							if (dht.search(path) == nullptr) {
								cout<<"Machine not found"<<endl;
							}
							else {
								cout << "Machine found" << endl;
							}
							
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to get more machines? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								machineMenu1 = false;
							}
						}
						break;
						case 2:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter Id of machine: ";
							BigInt Id;
							cin >> Id;
							if (dht.search(Id) == nullptr) {
								cout << "Machine not found" << endl;
							}
							else {
								cout << "Machine found" << endl;
							}
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to get more machines? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								machineMenu1 = false;
							}
						}
						break;
						case 3:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Returning****************" << endl;
							system("timeout 5");
							machineMenu1 = false;
						}
						break;
						case 0:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Exiting****************" << endl;
							system("timeout 5");
							machineMenu1 = false;
							machineMenu = false;
							mainMenu = false;
						}
						break;
						default:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************InvalidChoice****************" << endl;
							system("timeout 5");
							continue;
						}
						}
					}
				}
				break;
				case 3:
				{
					bool machineMenu1 = true;
					while (machineMenu1) {
						system("cls");
						printNebulaNodes();
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "****************RemovingMachine****************" << endl;
						cout << "Removing machine" << endl;
						cout << "1. Remove machine by path" << endl;
						cout << "2. Remove machine by hash" << endl;
						cout << "3. Return" << endl;
						cout << "0. Exit" << endl;
						cout << "Enter your choice: ";
						int choice2;
						cin >> choice2;
						switch (choice2)
						{
						case 1:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter path of machine: ";
							string path;
							cin >> path;
							if (dht.deleteMachine(path) == false) {
								cout<<"Machine not found"<<endl;
							}
							else {
								cout << "Machine removed" << endl;
							}
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to remove more machines? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								machineMenu1 = false;
							}
						}
						break;
						case 2:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Enter Id of machine: ";
							BigInt Id;
							cin >> Id;
							if (dht.deleteMachine(Id) == false) {
								cout << "Machine not found" << endl;
							}
							else {
								cout << "Machine removed" << endl;
							}
							system("timeout 5");
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "Do you want to remove more machines? (y/n): ";
							char choice3;
							cin >> choice3;
							if (choice3 == 'y' || choice3 == 'Y') {
								continue;
							}
							else {
								machineMenu1 = false;
							}
						}
						break;
						case 3:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Returning****************" << endl;
							system("timeout 5");
							machineMenu1 = false;
						}
						break;
						case 0:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************Exiting****************" << endl;
							system("timeout 5");
							machineMenu1 = false;
							machineMenu = false;
							mainMenu = false;
						}
						break;
						default:
						{
							system("cls");
							printNebulaNodes();
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "****************InvalidChoice****************" << endl;
							system("timeout 5");
							continue;
						}
						}
					}
				}
				break;
				case 4:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Returning****************" << endl;
					system("timeout 5");
					machineMenu = false;
				}
				break;
				case 0:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Exiting****************" << endl;
					system("timeout 5");
					machineMenu = false;
					mainMenu = false;
				}
				break;
				default:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************InvalidChoice****************" << endl;
					system("timeout 5");
					continue;
				}
				}
			}
		}
		break;
		case 3:
		{
			bool FRTMenu = true;
			while (FRTMenu) {
				system("cls");
				printNebulaNodes();
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "*****Viewing FRT of machine*****" << endl;
				cout << "1. View FRT of machine by path" << endl;
				cout << "2. View FRT of machine by Id" << endl;
				cout << "3. View FRT of All machines" << endl;
				cout << "4. Return" << endl;
				cout << "0. Exit" << endl;
				cout << "Enter your choice: ";
				int choice1;
				cin >> choice1;
				switch (choice1)
				{
				case 1:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************ViewingFRT****************" << endl;
					cout << "Enter path of machine: ";
					string path;
					cin >> path;
					if (dht.search(path)) {
						dht.search(path)->printFRT();
					}
					else {
						cout << "Machine not found...." << endl;
					}
					system("timeout 5");
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "Do you want to view more FRTs? (y/n): ";
					char choice3;
					cin >> choice3;
					if (choice3 == 'y' || choice3 == 'Y') {
						continue;
					}
					else {
						FRTMenu = false;
					}
				}
				break;
				case 2:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************ViewingFRT****************" << endl;
					cout << "Enter Id of machine: ";
					BigInt Id;
					cin >> Id;
					if (dht.search(Id)) {
						dht.search(Id)->printFRT();
					}
					else {
						cout << "Machine not found...." << endl;
					}
					system("timeout 5");
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "Do you want to view more FRTs? (y/n): ";
					char choice3;
					cin >> choice3;
					if (choice3 == 'y' || choice3 == 'Y') {
						continue;
					}
					else {
						FRTMenu = false;
					}
				}
				break;
				case 3:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					if (dht.isEmpty()) {
						cout << "Error! DHT is empty...." << endl;
					}
					else {
						dht.printallfrt();
					}
					system("timeout 5");
					continue;
				}
				break;
				case 4:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Returning****************" << endl;
					system("timeout 5");
					FRTMenu = false;
				}
				break;
				case 0:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Exiting****************" << endl;
					system("timeout 5");
					FRTMenu = false;
					mainMenu = false;
				}
				break;
				default:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************InvalidChoice****************" << endl;
					system("timeout 5");
				}
				}
			}
		}
		break;
		case 4:
		{	
			bool BTreeMenu = true;
			while (BTreeMenu) {
				system("cls");
				printNebulaNodes();
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "*****Viewing BTree of machine*****" << endl;
				cout << "Viewing BTree of machine" << endl;
				cout << "1.View BTree of machine by ID" << endl;
				cout << "2.View BTree of machine by name" << endl;
				cout << "3. View BTree of all machines" << endl;
				cout << "4. Return" << endl;
				cout << "0. Exit" << endl;
				int choice1;
				cin >> choice1;
				switch (choice1)
				{
				case 1:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************ViewingBTree****************" << endl;
					cout << "Enter name of machine: ";
					string path;
					cin >> path;
					if (dht.search(path)) {
						dht.search(path)->printFiles();
					}
					else {
						cout << "Machine not found...." << endl;
					}
					system("timeout 5");
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "Do you want to view more BTrees? (y/n): ";
					char choice3;
					cin >> choice3;
					if (choice3 == 'y' || choice3 == 'Y') {
						continue;
					}
					else {
						BTreeMenu = false;
					}
				}
				break;
				case 2:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************ViewingBTree****************" << endl;
					cout << "Enter Id of machine: ";
					BigInt Id;
					cin >> Id;
					if (dht.search(Id)) {
						dht.search(Id)->printFiles();
					}
					else {
						cout << "Machine not found...." << endl;
					}
					system("timeout 5");
					system("cls");
					cout << "Do you want to view more BTrees? (y/n): ";
					char choice3;
					cin >> choice3;
					if (choice3 == 'y' || choice3 == 'Y') {
						continue;
					}
					else {
						BTreeMenu = false;
					}
				}
				break;
				case 3:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					if (dht.isEmpty()) {
						cout << "Error! DHT is empty...." << endl;
					}
					else {
						dht.printallBtree();
					}
					system("timeout 5");
					continue;
				}
				break;
				case 4:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Returning****************" << endl;
					system("timeout 5");
					BTreeMenu = false;
				}
				break;
				case 0:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Exiting****************" << endl;
					system("timeout 5");
					BTreeMenu = false;
					mainMenu = false;
				}
				break;
				default:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************InvalidChoice****************" << endl;
					system("timeout 5");
				}
				}

			}
		}
		break;
		case 5:
		{
			system("cls");
			printNebulaNodes();
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "****************ViewingDHT****************" << endl;
			if (dht.isEmpty()) {
				cout << "Error! DHT is empty...." << endl;
			}
			else {
				dht.printDHTById();
			}
			system("timeout 5");
		}
		break;
		case 6:
		{
			bool hashMenu = true;
			while (hashMenu) {
				system("cls");
				printNebulaNodes();
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "*****Generating Hash*****" << endl;
				cout << "Generating Hash" << endl;
				cout << "1.Generate Hash of file" << endl;
				cout << "2.Generate Hash of machine" << endl;
				cout << "3.Return" << endl;
				cout << "0.Exit" << endl;
				cout << "Enter your choice: ";
				int choice1;
				cin >> choice1;
				switch (choice1)
				{
				case 1:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************GeneratingHash****************" << endl;
					cout << "Enter path of file: ";
					string path;
					cin >> path;
					cout << "Hash of "<<path<<" is: " ;
					cout << sha1(path) << endl;
					
					system("timeout 5");
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "Do you want to generate more hashes? (y/n): ";
					char choice3;
					cin >> choice3;
					if (choice3 == 'y' || choice3 == 'Y') {
						continue;
					}
					else {
						hashMenu = false;
					}
				}
				break;
				case 2:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************GeneratingHash****************" << endl;
					cout << "Enter name of machine: ";
					string name;
					cin >> name;
					cout << "Hash of " << name << " is: ";
					cout << sha1(name) << endl;
					system("timeout 5");
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "Do you want to generate more hashes? (y/n): ";
					char choice3;
					cin >> choice3;
					if (choice3 == 'y' || choice3 == 'Y') {
						continue;
					}
					else {
						hashMenu = false;
					}
				}
				break;
				case 3:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Returning****************" << endl;
					system("timeout 5");
					hashMenu = false;
				}
				break;
				case 0:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************Exiting****************" << endl;
					system("timeout 5");
					hashMenu = false;
					mainMenu = false;
				}
				break;
				default:
				{
					system("cls");
					printNebulaNodes();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << "****************InvalidChoice****************" << endl;
					system("timeout 5");
					continue;
				}
				}
			}
		}
		break;
		case 0:
		{
			system("cls");
			printNebulaNodes();
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "****************Exiting****************" << endl;
			system("timeout 5");
			mainMenu = false;
		}
		break;
		default:
		{
			system("cls");
			printNebulaNodes();
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "****************InvalidChoice****************" << endl;
			system("timeout 5");
		}
		}
	}
}