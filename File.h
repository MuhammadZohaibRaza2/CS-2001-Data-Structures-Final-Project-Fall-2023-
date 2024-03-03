#pragma once
#include <fstream>
#include "SHA-1.h"
#include "BigInt.h"
#include "HexToDec.h"
class File {
private:
	string fileName;
	string fileHash;
	string fileContent;
	BigInt fileId;
public:
	File(string fileName, BigInt id = 0) {
		this->fileName = fileName;
		this->calculateHash();
		if (id == 0)
			this->calculateId();
		else
			this->fileId = id;
		this->readFile();
	}
	string getFileName() {
		return this->fileName;
	}
	string getFileHash() {
		return this->fileHash;
	}
	string getFileContent() {
		return this->fileContent;
	}
	void setFileName(string fileName) {
		this->fileName = fileName;
	}
	void setFileHash(string fileHash) {
		this->fileHash = fileHash;
	}
	void setFileContent(string fileContent) {
		this->fileContent = fileContent;
	}
	BigInt getFileId() {
		return this->fileId;
	}
	void setFileId(BigInt fileId) {
		this->fileId = fileId;
	}
	void readFile() {
		ifstream file(this->fileName);
		stringstream buffer;
		buffer << file.rdbuf();
		this->fileContent = buffer.str();
	}
	void calculateHash() {
		this->fileHash = sha1(this->fileName);
	}
	void calculateId() {
		this->fileId = convertHextoDec(this->fileHash);
	}
};