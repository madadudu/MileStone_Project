// Name: Junhua Zhou
// Seneca Student ID: 121136188
// Seneca email: jzhou165@myseneca.ca
// Date of completion: 3/29/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _CUSTOMERORDER_H
#define _CUSTOMERORDER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Station.h"
#include "Utilities.h"

/*struct ItemInfo{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_itemState = false;

	ItemInfo(std::string src) :m_itemName(src) {};
};*/

struct Item {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;
	Utilities util;

public:
	CustomerOrder();
	CustomerOrder(const std::string& str);

	CustomerOrder(const CustomerOrder&);// { throw "Copy Not allowed"; }
	CustomerOrder& operator=(const CustomerOrder&) = delete;

	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&) noexcept;
	~CustomerOrder();

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};
#endif // !_CUSTOMERORDER_H