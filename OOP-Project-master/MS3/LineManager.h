// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 4/10/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <iostream>
#include <deque>
#include <vector>
#include "Workstation.h"
#include "CustomerOrder.h"


class LineManager {
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	static size_t m_counter;

public:
	LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
	std::deque<Workstation*> sort(const std::vector<Workstation*>& AssemblyLine)const;
};
#endif // !LINEMANAGER_H