#include "Utilities.h"




//namespace sdds {

size_t Utilities::m_widthField = 1;
char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t newWidth) {

	m_widthField = newWidth;
}


size_t Utilities::getFieldWidth() const {

	return m_widthField;
}


std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	size_t start = str.find(m_delimiter, next_pos + 1);
	std::string token = "";



	if (start < str.length()) {

		more = true;

	}
	else {

		start = str.length();
		more = false;
	}


	token = str.substr(next_pos + 1, start - next_pos - 1);
	next_pos = start;
	if (token == "") {
		throw 1;
	}


	return token;


}


void Utilities::setDelimiter(char newDelimiter) {

	m_delimiter = newDelimiter;
}


char Utilities::getDelimiter() {


	return m_delimiter;
}
//}