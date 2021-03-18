#include "Station.h"
#include "Utilities.h"
#include <iomanip>
#include <iostream>


Station::Station(const std::string& str) {

	try {

		size_t pos = -1;
		bool more = true;

		m_name = utils.extractToken(str, pos, more);

		m_serialNumber = std::stoi(utils.extractToken(str, pos, more));
		itemLeft = std::stoi(utils.extractToken(str, pos, more));
		m_description = utils.extractToken(str, pos, more);

		if (utils.getFieldWidth() < m_name.size()) {
			utils.setFieldWidth(m_name.size());
		}

	}
	catch (int) {
		std::cout << "ERROR EXIT" << std::endl;

	}

}

const std::string& Station::getItemName() const
{
	// TODO: insert return statement here
	return this->m_name;
}

unsigned int Station::getNextSerialNumber()
{
	return this->m_serialNumber++;
}

unsigned int Station::getQuantity() const
{
	return this->itemLeft;
}

void Station::updateQuantity()
{
	if (itemLeft > 0) {
		itemLeft--;
	}
}

void Station::display(std::ostream& os, bool full) const
{
	size_t width = utils.getFieldWidth();

	if (full)
	{
		static int m_stationID = 1;
		os << "[" << std::setw(3) << std::setfill('0') << std::right << m_stationID << "] "
			<< std::left << "Item: " << std::left << std::setw(width) << std::setfill(' ') << m_name
			<< " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber
			<< std::setfill(' ') << "] Quantity: " << std::left << std::setw(width) << itemLeft
			<< " Description: " << m_description << std::endl;
		m_stationID++;

	}
	else
	{
		static int m_stationID = 1;
		os << "[" << std::setw(3) << std::setfill('0') << m_stationID << "] "
			<< std::left << "Item: " << std::left << std::setw(width) << std::setfill(' ') << m_name
			<< " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << std::setfill(' ') << "]" << std::endl;
		m_stationID++;

	}
}










