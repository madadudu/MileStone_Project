// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 3/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"

using namespace std;
size_t Utilities::m_widthField = 1;  //default value 1.
char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	size_t temp = str.find(m_delimiter, next_pos + 1);
	string m_str = "";

	if (temp < str.length()) {
		more = true;
	}
	else {
		temp = str.length();
		more = false;
	}

	m_str = str.substr(next_pos + 1, temp - next_pos - 1);
	next_pos = temp;
	if (m_str == "") {
		throw 1;
	}

	return m_str;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}