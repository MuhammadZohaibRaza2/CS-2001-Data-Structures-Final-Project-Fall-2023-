#pragma once
#include "BigInt.h"
int hexCharToDecimal(char hexChar) {
	if (hexChar >= '0' && hexChar <= '9') {
		return hexChar - '0';
	}
	else if (hexChar >= 'A' && hexChar <= 'F') {
		return hexChar - 'A' + 10;
	}
	else if (hexChar >= 'a' && hexChar <= 'f') {
		return hexChar - 'a' + 10;
	}
	else {
		return -1;
	}
}
BigInt convertHextoDec(const string& hexString) {
	BigInt decimalValue = 0;
	BigInt base = 1;
	for (int i = hexString.length() - 1; i >= 0; --i) {
		BigInt hexDigitValue = hexCharToDecimal(hexString[i]);
		decimalValue += hexDigitValue * base;
		base *= 16;
	}

	//code to convert string to ascii
	/*for (int i = 0; i < hexString.length(); i++) {
		decimalValue = decimalValue + int(hexString[i]);
	}*/

	return decimalValue;
}