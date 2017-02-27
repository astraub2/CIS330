/*
 * caesar.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: Amber
 */
#include "cipher.hpp"
#include "caesar.hpp"
#include <fstream>
#include <iostream>
#include <string>

CaesarCipher:: CaesarCipher(int thekey): Cipher(){
	key=thekey;

}
CaesarCipher:: ~CaesarCipher(){

}


std::string CaesarCipher::encrypt( std::string &inputText){
	std::string text = inputText;
	std::string::size_type len = text.length();
	for (int i = 0; i != len-3; ++i) {
		//std::cout << text[i] << std::endl;

		if(text[i]+key==('z'+1) || text[i]+key==('Z'+1))
					text[i]=' ';
		else if((text[i])>='a' && (text[i])<='z'){
			if((text[i]+key)>'z'){
				int thing= (text[i]+key)-27;
				text[i]=thing;
			}
			else
				text[i]=text[i]+key;
		}
		else if((text[i])>='A' && (text[i])<='Z'){
			if((text[i]+key)>'Z'){
				int thing= (text[i]+key)-27;
				text[i]=thing;
			}
				else
					text[i]=text[i]+key;
				}

		else if(text[i]==' '){
					char k=('a'-1)+key;
					text[i]=k;
		}



		}




	return text;

}

std::string CaesarCipher::decrypt( std::string &inputText){
	std::string text = inputText;
	std::string::size_type len = text.length();
	for (int i = 0; i != len; ++i) {
			//std::cout << text[i] << std::endl;
		if(text[i]==' ')
					text[i]='z'-(key-1);
		else if(text[i]==(('a'-1)+key))
				text[i]=' ';
		else if((text[i])>='a' && (text[i])<='z'){
			if((text[i]-key)<'a'){
				int thing= (text[i]-key)+27;
				text[i]=thing;
			}
			else
				text[i]=text[i]-key;
			}
		else if((text[i])>='A' && (text[i])<='Z'){
			if((text[i]-key)<'A'){
				int thing= (text[i]-key)+27;
				text[i]=thing;
			}
				else
					text[i]=text[i]-key;
				}




		}

	return text;
}

