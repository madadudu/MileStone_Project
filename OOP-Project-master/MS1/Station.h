#pragma once
#ifndef _STATION_H
#define _STATION_H
#include <string>

#include "Utilities.h"


class Station {

	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int itemLeft = 0;
	Utilities utils;
	unsigned int id_generator;
public:

	Station(const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;

};

#endif // !SDDS_STATION_H

