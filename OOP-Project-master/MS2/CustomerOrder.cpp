// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 3/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

//size_t CustomerOrder::m_widthField = 1;
size_t CustomerOrder::m_widthField = 0;
using namespace std;

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const std::string& str) {
	size_t temp_pos = -1;
	bool checker = false;
	vector<Item*> tempVector;
	m_name = util.extractToken(str, temp_pos, checker);
	m_product = util.extractToken(str, temp_pos, checker);

	while (checker) {
		tempVector.push_back(new Item(util.extractToken(str, temp_pos, checker)));
	}
	m_cntItem = static_cast<unsigned int>(tempVector.size());
	m_lstItem = new Item * [m_cntItem];
	for (size_t i = 0; i < m_cntItem; i++) {
		m_lstItem[i] = move(tempVector[i]);
	}

	if (util.getFieldWidth() < m_name.size()) {
		util.setFieldWidth(m_name.size());
	}
	if (util.getFieldWidth() < m_product.size()) {
		util.setFieldWidth(m_product.size());
	}

}

CustomerOrder::CustomerOrder(const CustomerOrder& copy) {
	throw "ERROR: Copy Not allowed";
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	*this = move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
	if (this != &src) {
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;

		src.m_lstItem = nullptr;
		src.m_name = "";
		src.m_cntItem = 0;
		src.m_product = "";
	}
	return *this;
}

CustomerOrder::~CustomerOrder() {
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::isOrderFilled() const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false) {
			return false;
		}
	}
	return true;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			if (!m_lstItem[i]->m_isFilled) {
				return false;
			}
		}
	}
	return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
			m_lstItem[i]->m_isFilled = true;

			os << "    " << (m_lstItem[i]->m_isFilled ? "Filled" : "Unfilled") << " "
				<< m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	m_widthField = util.getFieldWidth();

	os << m_name << " - " << m_product << endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << setw(6) << setfill('0') << "[" << m_lstItem[i]->m_serialNumber << "] "
			<< setfill(' ') << setw(static_cast<int>(m_widthField)) << m_lstItem[i]->m_itemName << " - ";
		os << (isItemFilled(m_lstItem[i]->m_itemName) ? "Filled" : "MISSING") << endl;
	}
}