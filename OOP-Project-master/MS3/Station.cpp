// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 3/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

//#include <iostream>
//#include <iomanip>
//#include "Utilities.h"
#include "Station.h"

using namespace std;
size_t Station::id_generator = 0;
size_t Station::m_widthField = 0;

Station::Station() {
	m_ID = 0;
	m_name = "";
	m_description = "";
	m_serialNumber = 0;
	m_quantity = 0;
}

Station::Station(const std::string& src) {
	Utilities utils;

	size_t posS = 0;
	bool more = true;

	m_name = utils.extractToken(src, posS, more);
	m_serialNumber = std::stoi(utils.extractToken(src, posS, more));
	m_quantity = std::stoi(utils.extractToken(src, posS, more));

	if (m_widthField < utils.getFieldWidth()) {
		m_widthField = utils.getFieldWidth();
	}

	m_description = utils.extractToken(src, posS, more);

	m_ID = ++id_generator;
}

const std::string& Station::getItemName() const {
	return this->m_name;
}

unsigned int Station::getNextSerialNumber() {
	return this->m_serialNumber++;
}

unsigned int Station::getQuantity() const {
	return this->m_quantity;

}

void Station::updateQuantity() {
	this->m_quantity--;
	if (m_quantity < 0) {
		throw "ERROR: Quantity.";
	}
}

void Station::display(std::ostream& os, bool full) const {
	if (full) {
		os << right << setfill('0') << '[' << setw(3) << m_ID << "] ";
		os << setfill(' ') << "Item: " << setw(m_widthField) << left << m_name;
		os << " [" << setw(6) << setfill('0') << right << m_serialNumber << "]" << setfill(' ');
		os << " Quantity: " << setw(m_widthField) << left << m_quantity << " Description: " << m_description;
		os << endl;
	}
	else {
		os << right << setfill('0') << '[' << setw(3) << m_ID << "] ";
		os << setfill(' ') << "Item: " << setw(m_widthField) << left << m_name;
		os << " [" << setw(6) << setfill('0') << right << m_serialNumber << "]" << setfill(' ');
		os << endl;
	}
}