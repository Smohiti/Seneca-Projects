// Date: 2016/11/27
// Author: M.Saeed Mohiti
// String.cpp
// work shop 10
/////////////////////////////////////////////
#include <cstring>
#include <iostream>
#include "String.h"
using namespace std;

namespace ict
{
	// write your implementations here
	void String::deallocate(){
		delete[] m_data;
		m_data = nullptr;
		m_memSize = 0;
	}
	void String::allocate(int memsize){
		delete[] m_data;
		m_data = new char[memsize];
		m_memSize = memsize;
		m_data[0] = '\0';
	}
	void String::init(const char* str, int memsize) {
		m_data = nullptr;
		m_len = strlen(str);
		if (memsize < m_len)
			memsize = m_len + 1;
		allocate(memsize);
		strcpy(m_data, str);
		m_data[m_len + 1] = '\0';
	}
	void String::resize(int newsize) {
		int i;
		char*temp= new char [newsize]; 
		temp[0] = '\0';
		if (m_data) {
			for (i = 0; (i < newsize - 1 && m_data[i] != '\0'); i++) {
				temp[i] = m_data[i];
			}
		//	while (m_data[i] != '\0' && i <= newsize - 1) {
		//		temp[i] = m_data[i];
		//		i++;
		//	}
			temp[i] = '\0';
		}
		allocate(newsize);
		if (temp[0] != '\0') {
			strcpy(m_data, temp);
		}
		m_len = strlen(m_data);
	}
	String::String(){
		m_data = nullptr;
		m_memSize = 0;
		m_len = 0;
	}
	String::String(const char* str, int memsize){
		init(str, memsize);
	}
	String::String(const String& other) {
		init(other.m_data, other.m_memSize);
	}
	String& String::operator=(const String& other){
		if (this != &other){
			delete[] m_data;
			init(other.m_data, other.m_memSize);
		}
		return *this;
	}
	String::~String() {
		delete[] m_data;
	}
	int String::getLength()const{
		return m_len;
	}
	int String::getMemSize()const{
		return m_memSize;
	}
    String::operator const char *()const {
	return m_data;
	}
	String::operator int()const {
		return strlen(m_data);
	}
	String& String::operator+=(const char* str){
		int tVar = strlen(str);
		if (m_len + tVar + 1 > m_memSize)
			resize(m_len + tVar + 1);
		strcat(m_data, str);
		m_len = strlen(m_data);
		return *this;
	}
	String String::operator+(const String& str)const{
		String temp;
		temp.allocate(ExpansionSize);
		temp += this->m_data;
		temp += " ";
		temp += str.m_data;
		temp.m_len = strlen(temp.m_data + 1);
		return temp;
	}
	String& String::operator+=(String& str) {
		*this += str.m_data;
		return *this;
	}
	String& String::operator++(){     
		char temp[ExpansionSize];
		strcpy(temp, " ");
		strcat(temp, m_data);
		strcpy(m_data, temp);
		m_len = strlen(m_data);
		return *this;
	}
	String String::operator++(int){   
		String copy = *this;
		copy += " ";
		return *this;
	}
	char& String::operator[](int idx){
		if (idx > m_memSize - 1)
		//if (m_data[idx] < 0 || m_data[idx] > m_len)
			resize(idx + ExpansionSize);
		return m_data[idx];
	}
	ostream& operator<<(ostream& ostr, const String& s){
		s.display(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, String &s){
		s.read(istr);
		return istr;
	}
	ostream& String::display(ostream& ostr) const {
		if (m_data != nullptr) {
			ostr << m_data;
		}
		return ostr;
	}
	istream& String::read(istream& istr) {
		char c;
		int i = 0;
		while ((c = istr.get() != '\n')) {
			if (i > m_memSize) {
				resize(m_memSize + ExpansionSize);
			}
			m_data[i] = c;
			i++;
		}
		m_data = NULL;
		return istr;
	}

}
