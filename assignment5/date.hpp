/*
 * date.hpp
 *
 *  Created on: Feb 17, 2017
 *      Author: Amber
 */

#ifndef DATE_HPP_
#define DATE_HPP_
#include "cipher.hpp"

class DateCipher : public Cipher {
public:
	DateCipher(int date[6]);
	virtual ~DateCipher();
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
private:
	int* data;
};




#endif /* DATE_HPP_ */
