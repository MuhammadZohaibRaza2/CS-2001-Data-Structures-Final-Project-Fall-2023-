#pragma once
#include <iostream>
#include <iomanip>
#include <openssl/sha.h>
#include <sstream>
#include <string>
using namespace std;
string sha1(const string& input) {
	SHA_CTX shaContext;
	SHA1_Init(&shaContext);
	SHA1_Update(&shaContext, input.c_str(), input.length());
	unsigned char hash[SHA_DIGEST_LENGTH];
	SHA1_Final(hash, &shaContext);
	stringstream ss;
	for (int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
		ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
	}
	return ss.str();
}