// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 4/10/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include "LineManager.h"

size_t LineManager::m_counter = 1;

using namespace std;
LineManager::LineManager(const std::string& f_name, std::vector<Workstation*>& assLine, std::vector<CustomerOrder>& isFilled) {
	Utilities utils;

	utils.setDelimiter('|');

	std::ifstream file(f_name);
	std::string m_post;
	std::string m_next;
	std::string m_temp;
	size_t m_position = 0;
	bool more = true;

	if (!file) {
		throw std::string("fail to open the file!");
	}
	else {
		while (!file.eof()) {
			more = true;
			getline(file, m_temp);
			m_post = utils.extractToken(m_temp, m_position, more);

			if (more) {
				m_next = utils.extractToken(m_temp, m_position, more);
			}
			else {
				m_next = "";
			}
			for (auto station : assLine) {
				if (m_post == station->getItemName()) {
					for (auto current : assLine) {
						if (current->getItemName() == m_next) {
							station->setNextStation(*current);
						}
					}
				}
			}
		}
	}

	AssemblyLine = assLine;
	m_cntCustomerOrder = isFilled.size();
	for (auto& order : isFilled) {
		ToBeFilled.push_back(move(order));
	}
}

bool LineManager::run(std::ostream& os) {
	CustomerOrder temp{};
	deque<Workstation*> AssemblyLineSorted = sort(AssemblyLine);

	os << "Line Manager Iteration: " << m_counter << endl;

	if (ToBeFilled.size() > 0) {
		*AssemblyLineSorted.front() += move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (auto item : AssemblyLine) {
		item->runProcess(os);
	}

	for (auto item : AssemblyLine) {
		item->moveOrder();
		if (item->getIfCompleted(temp)) {
			Completed.push_back(move(temp));
		}
	}

	m_counter++;
	return Completed.size() == m_cntCustomerOrder;
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (const auto& order : Completed) {
		order.display(os);
	}
}

void LineManager::displayStations() const {
	for (const auto& mstation : AssemblyLine) {
		mstation->display(cout);
	}
}

void LineManager::displayStationsSorted() const {
	std::deque<Workstation*> issorted = sort(AssemblyLine);
	for (const auto& station : issorted) {
		const_cast<Workstation*>(station)->display(cout);
	}
}

std::deque<Workstation*> LineManager::sort(const std::vector<Workstation*>& AssemblyLine)const {
	Workstation* myLastStation{};
	std::deque<Workstation*> sortedAssemblyLine;
	while (sortedAssemblyLine.size() != AssemblyLine.size()) {
		for (auto station : AssemblyLine) {
			if (station->getNextStation()==myLastStation) {
				sortedAssemblyLine.push_front(station);
				myLastStation = station;
			}
		}
	}
	return sortedAssemblyLine;
}