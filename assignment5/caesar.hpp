/*
 * caesar.hpp
 *
 *  Created on: Feb 15, 2017
 *      Author: Amber
 */

#ifndef CAESAR_HPP_
#define CAESAR_HPP_

#include "cipher.hpp"

class CaesarCipher : public Cipher {
public:
	CaesarCipher(int key);
	virtual ~CaesarCipher();
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
private:
	int key;
};



#endif /* CAESAR_HPP_ */
