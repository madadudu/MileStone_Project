// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 3/22/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"

using namespace std;
Station::Station() {
	m_name = "";
	m_description = "";
	m_serialNumber = 0u;
	m_quantity = 0u;
}

Station::Station(const std::string& src) {
	try {
		size_t posS = -1;
		bool more = true;

		m_name = utils.extractToken(src, posS, more);
		m_serialNumber = stoi(utils.extractToken(src, posS, more));
		m_quantity = stoi(utils.extractToken(src, posS, more));
		m_description = utils.extractToken(src, posS, more);

		if (utils.getFieldWidth() < m_name.size()) {
			utils.setFieldWidth(m_name.size());
		}
	}
	catch (int) {
		cout << "ERROR: PRPGRAM EXIT" << endl;
	}
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
	if (m_quantity > 0) {
		m_quantity--;
	}
}

void Station::display(std::ostream& os, bool full) const {
	//size_t width = utils.getFieldWidth();

	static int m_ID = 1;
	if (!full) {
		os << "[" << setw(3) << setfill('0') << m_ID << "] ";
		os << left << "Item: " << left << setw(utils.getFieldWidth()) << setfill(' ') << m_name;
		os << " [" << right << setw(6) << setfill('0') << m_serialNumber;
		os << setfill(' ') << "]" << endl;
		m_ID++;
	}
	else {
		static int m_ID = 1;
		os << "[" << setw(3) << setfill('0') << right << m_ID << "] ";
		os << left << "Item: " << left << setw(utils.getFieldWidth()) << setfill(' ') << m_name;
		os << " [" << right << setw(6) << setfill('0') << m_serialNumber;
		os << setfill(' ') << "] Quantity: " << left << setw(utils.getFieldWidth()) << m_quantity;
		os << " Description: " << m_description << endl;
		m_ID++;
	}

	//2.
	//size_t width = utils.getFieldWidth();

	/*static int m_ID = 1;
	if (full) {
		static int m_ID = 1;
		os << "[" << setw(3) << setfill('0') << right << m_ID << "] "
			<< left << "Item: " << left << setw(utils.getFieldWidth()) << setfill(' ') << m_name
			<< " [" << right << setw(6) << setfill('0') << m_serialNumber
			<< setfill(' ') << "] Quantity: " << left << setw(utils.getFieldWidth()) << m_quantity
			<< " Description: " << m_description << endl;
		m_ID++;
	}
	else {
		os << "[" << setw(3) << setfill('0') << m_ID << "] "
			<< left << "Item: " << left << setw(utils.getFieldWidth()) << setfill(' ') << m_name
			<< " [" << right << setw(6) << setfill('0') << m_serialNumber
			<< setfill(' ') << "]" << endl;
		m_ID++;
	}*/

	//1.
	/*size_t width = utils.getFieldWidth();

	static int m_ID = 1;
	if (full) {
		static int m_ID = 1;
		os << "[" << setw(3) << setfill('0') << right << m_ID << "] "
			<< left << "Item: " << left << setw(width) << setfill(' ') << m_name
			<< " [" << right << setw(6) << setfill('0') << m_serialNumber
			<< setfill(' ') << "] Quantity: " << left << setw(width) << m_quantity
			<< " Description: " << m_description << endl;
		m_ID++;
	}
	else {
		//static int m_ID = 1;
		os << "[" << setw(3) << setfill('0') << m_ID << "] "
			<< left << "Item: " << left << setw(width) << setfill(' ') << m_name
			<< " [" << right << setw(6) << setfill('0') << m_serialNumber
			<< setfill(' ') << "]" << endl;
		m_ID++;
	}*/

}