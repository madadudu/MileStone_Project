// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 3/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"

using namespace std;
char Utilities::m_delimiter = '|';

Utilities::Utilities() : m_widthField(1u) {}

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	size_t temp = str.find(m_delimiter, next_pos);
	string m_str = str.substr(next_pos, temp - next_pos);

	if (m_str.empty()) {
		more = false;
	}
	else {
		more = (temp != string::npos) ? true : false;
		next_pos = temp + 1;
		if (m_widthField < m_str.length()) {
			setFieldWidth(m_str.length());
		}
	}

	

	return m_str;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}