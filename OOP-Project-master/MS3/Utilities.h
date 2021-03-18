// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 3/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _UTILITIES_H
#define _UTILITIES_H

#include <iostream> 
#include <iomanip>
#include <string>

class Utilities {
	size_t m_widthField;  //default value 1.
	static char m_delimiter;

public:
	Utilities();
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();

};
#endif // !_UTILITIES_H