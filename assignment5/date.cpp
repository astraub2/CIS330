/*
 * dcipher.cpp
 *
 *  Created on: Feb 17, 2017
 *      Author: Amber
 */
/*
 * caesar.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: Amber
 */
#include "cipher.hpp"
#include "date.hpp"
#include <fstream>
#include <iostream>
#include <string>

DateCipher:: DateCipher(int thedate[6]): Cipher(){
	data=thedate;

}
DateCipher:: ~DateCipher(){

}


std::string DateCipher::encrypt( std::string &inputText){
	std::string text = inputText;
	std::string::size_type len = text.length();
		int datacount=0;
		int dates[1000];
		for (int x = 0; x != len; ++x) {
			if((text[x])>='a' && (text[x])<='z'){
			if(datacount<6){
				dates[x]=data[datacount];
				datacount+=1;
			}
			else{
				datacount=0;
				dates[x]=data[datacount];
				datacount+=1;
			}
			}
			else if((text[x])>='A' && (text[x])<='Z'){
				if(datacount<6){
					dates[x]=data[datacount];
					datacount+=1;
				}
				else{
					datacount=0;
					dates[x]=data[datacount];
					datacount+=1;
				}
			}
			else
				dates[x]=-1;


			//std::cout << dates[x];

		}
	for (int i = 0; i != len; ++i) {
		int key=dates[i];
		//std::cout << text[i] << std::endl;

		if((text[i])>='a' && (text[i])<='z'){
			if((text[i]+key)>'z'){
				int thing= (text[i]+key)-26;
				text[i]=thing;
			}
			else
				text[i]=text[i]+key;
		}
		else if((text[i])>='A' && (text[i])<='Z'){
			if((text[i]+key)>'Z'){
				int thing= (text[i]+key)-26;
				text[i]=thing;
			}
				else
					text[i]=text[i]+key;
				}





		}




	return text;

}

std::string DateCipher::decrypt( std::string &inputText){
	std::string text = inputText;
	std::string::size_type len = text.length();
	int datacount=0;
	int dates[1000];
	for (int x = 0; x != len; ++x) {
		if((text[x])>='a' && (text[x])<='z'){
		if(datacount<6){
			dates[x]=data[datacount];
			datacount+=1;
		}
		else{
			datacount=0;
			dates[x]=data[datacount];
			datacount+=1;
		}
		}
		else if((text[x])>='A' && (text[x])<='Z'){
			if(datacount<6){
				dates[x]=data[datacount];
				datacount+=1;
			}
			else{
				datacount=0;
				dates[x]=data[datacount];
				datacount+=1;
			}
		}
		else
			dates[x]=-1;


		//std::cout << dates[x];

	}

	for (int i = 0; i != len; ++i) {
		int key=dates[i];
			//std::cout << text[i] << std::endl;

		if((text[i])>='a' && (text[i])<='z'){
			if((text[i]-key)<'a'){
				int thing= (text[i]-key)+26;
				text[i]=thing;
			}
			else
				text[i]=text[i]-key;
			}
		else if((text[i])>='A' && (text[i])<='Z'){
			if((text[i]-key)<'A'){
				int thing= (text[i]-key)+26;
				text[i]=thing;
			}
				else
					text[i]=text[i]-key;
				}




		}

	return text;
}





