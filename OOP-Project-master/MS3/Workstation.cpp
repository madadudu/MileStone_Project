// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 4/10/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Workstation.h"
using namespace std;

Workstation::Workstation(const std::string& src) : Station(src) {
	this->m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& src) {
	if (!m_orders.empty() && !m_orders.front().isOrderFilled()) {

		while (!m_orders.front().isItemFilled(getItemName())) {
			m_orders.front().fillItem(*this, src);
		}
	}
}

bool Workstation::moveOrder() {


	if (!m_orders.empty()) {
		if (m_pNextStation != nullptr && m_orders.front().isItemFilled(getItemName())) {
			*this->m_pNextStation += std::move(m_orders.front());
			m_orders.pop_front();
		}
	}
	else {
		return false;
	}

	return true;
}

void Workstation::setNextStation(Workstation& station) {
	this->m_pNextStation = (Workstation*)&station;
}

const Workstation* Workstation::getNextStation() const {
	return this->m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {

	if (!m_orders.empty() && m_orders.front().isOrderFilled()) {
		//if (m_orders.front().isOrderFilled()) {
		order = move(this->m_orders.front());
		this->m_orders.pop_front();
		return true;
	}

	return false;
}

void Workstation::display(std::ostream& os) {
	std::string nextItemName = getNextStation() ? getNextStation()->getItemName() : "END OF LINE";
	os << getItemName() << " --> " << nextItemName << std::endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& myOrder) {
	m_orders.push_back(std::move(myOrder));
	return *this;
}