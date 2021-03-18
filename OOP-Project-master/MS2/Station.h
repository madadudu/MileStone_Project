// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 3/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _STATION_H
#define _STATION_H

#include <string>
#include <iomanip>
#include "Utilities.h"

class Station {
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;
	Utilities utils;
	unsigned int id_generator;

public:
	Station();
	Station(const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
		
};
#endif // !_STATION_H+.