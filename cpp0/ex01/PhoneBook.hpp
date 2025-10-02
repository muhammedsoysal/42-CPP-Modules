#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void addContact(PhoneBook &phoneBook);
	void searchContact(int index) const;

private:
	Contact contacts[8];
	int contactCount;
	std::string formatField(const std::string &field) const;
};
#endif