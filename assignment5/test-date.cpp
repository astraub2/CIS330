/*
 * test-date.cpp
 *
 *  Created on: Feb 17, 2017
 *      Author: Amber
 */
#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "date.hpp"

int main(int argc, const char *argv[]) {

	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = "ABCD XYZ abcd xyz";
	std::cout << "Original text:" << std::endl << input;

	// 2. Test various ciphers

	// Simple ROT13 cipher
	int date[6]={1,2,2,5,9,4};
	int thedate=122590;
	DateCipher data(date);

	encrypted = data.encrypt(input);
	std::cout <<std::endl;
	std::cout << "Key: "  << thedate<< std::endl;
	std::cout << "Encrypted text:" << std::endl << encrypted;

	decrypted = data.decrypt(encrypted);
	std::cout <<std::endl;
	std::cout << "Decrypted text:" << std::endl << decrypted;
	std::cout <<std::endl;

	if (decrypted == input) std::cout << "Decrypted text matches input!" << std::endl;
	else {
		std::cout << "Oops! Decrypted text doesn't match input!" << std::endl;
		return 1;   // Make sure to return a non-zero value to indicate failure
	}

	return 0;
}



