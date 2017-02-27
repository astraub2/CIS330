/*
 * test-caesar.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: Amber
 */


#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "caesar.hpp"

int getkey(){
	std::cout << "Enter Encryption key:" << std::endl;
	int key;
	std::cin >> key;
	return key;
}

int main(int argc, const char *argv[]) {
	int key=getkey();
	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = io.readFromStream();
	std::cout << "Original text:" << std::endl << input;


	CaesarCipher caesar(key);
	encrypted = caesar.encrypt(input);
	std::cout << "Encrypted text:" << std::endl << encrypted;

	decrypted = caesar.decrypt(encrypted);
	std::cout << "Decrypted text:" << std::endl << decrypted;

	if (decrypted == input) std::cout << "Decrypted text matches input!" << std::endl;
	else {
		std::cout << "Oops! Decrypted text doesn't match input!" << std::endl;
		return 1;   // Make sure to return a non-zero value to indicate failure
	}

  return 0;
}




