/*
NAME: Yehuda Daniel
ID: 211789680
*/

#include "str.h"

//Default Ctor, initializes the string to "none"
Str::Str(){
	m_str = new char[5];
	strcpy(m_str, "none");
}

Str::Str(const Str& other){
	m_str = new char[strlen(other.m_str) + 1];

	strcpy(m_str, other.m_str);
}

Str::Str(const char* str){
	m_str = new char[strlen(str) + 1];
	
	strcpy(m_str, str);
}

//Deletes all the dynamic allocations
Str::~Str(){
	delete[] m_str;
}

bool Str::operator==(const Str& other) const{
	if (strcmp(m_str, other.m_str) == 0)
		return true;
	else
		return false;
}

bool Str::operator!=(const Str& other) const{
	if (strcmp(m_str, other.m_str) != 0)
		return true;
	else
		return false;
}

bool Str::operator>(const Str& other) const{
	if (strcmp(m_str, other.m_str) > 0)
		return true;
	else
		return false;
}

bool Str::operator<(const Str& other) const{
	if (strcmp(m_str, other.m_str) < 0)
		return true;
	else
		return false;
}

const Str& Str::operator=(const Str& other){
	if (&other != this) {
		delete[] this->m_str;

		m_str = new char[strlen(other.m_str) + 1];

		strcpy(m_str, other.m_str);
	}
	return *this;
}

const Str& Str::operator=(const char* str){
	if (this->m_str != str) {
		delete[] this->m_str;

		m_str = new char[strlen(str) + 1];

		strcpy(m_str, str);
	}
	return *this;
}

char& Str::operator[](int index) const{

	return this->m_str[index];
}

const Str& Str::operator++(){
	for (unsigned int i = 0; i < strlen(this->m_str); i++) {
		this->m_str[i] = this->m_str[i] + 1;
	}
	return *this;
}

Str Str::operator++(int){
	Str tmp = *this;
	++* this;
	return tmp;
}


Str::operator int() const{
	return (int)strlen(this->m_str);
}

int Str::operator()(char ch) const{
	for (int i = 0; i != strlen(m_str); i++){
		if (this->m_str[i] == ch){
			return i;
		}
	}
	return -1;
}

Str Str::operator+(const Str& other) const{
	char* newStr = new char[strlen(this->m_str) + strlen(other.m_str) + 1];

	strcpy(newStr, this->m_str);
	strcat(newStr, other.m_str);

	Str str = Str(newStr);
	return str;
}


Str operator+(const char* str, const Str& other){
	char* newStr = new char[strlen(str) + strlen(other.m_str) + 1];

	strcpy(newStr, str);
	strcat(newStr, other.m_str);

	Str strFinal = Str(newStr);
	return strFinal;
}

Str operator*(int num, const Str& other){
	char* newStr = new char[strlen(other.m_str) * num + 1];

	strcpy(newStr, other.m_str);
	for (int i = 0; i < num - 1; i++) {
		strcat(newStr, other.m_str);
	}
	
	Str finalStr = Str(newStr);
	return finalStr;
}


const Str& Str::operator+=(const Str& other){
	char* newStr = new char[strlen(this->m_str) + strlen(other.m_str) + 1];

	strcpy(newStr, this->m_str);
	strcat(newStr, other.m_str);

	*this = *this + other;
	return *this;
}