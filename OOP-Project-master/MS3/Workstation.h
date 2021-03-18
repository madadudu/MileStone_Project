// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 4/10/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <deque>
#include <iostream>
#include <ostream>
#include <string>

#include "CustomerOrder.h"
#include "Station.h"

class Workstation : public Station {
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;

public:
	Workstation(const std::string& );
	Workstation(const Workstation& ) = delete;
	Workstation(Workstation&& ) = delete;
	Workstation& operator=(const Workstation& ) = delete;
	Workstation& operator=(Workstation&& ) = delete;

	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Workstation& station);
	const Workstation* getNextStation() const;   
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&);
	Workstation& operator+=(CustomerOrder&&);
};
#endif // !WORKSTATION_H