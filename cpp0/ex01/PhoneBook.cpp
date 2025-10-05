#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact(PhoneBook &phoneBook)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, firstName) || firstName.empty())
	{
		std::cout << "Invalid input. Contact not added." << std::endl;
		return;
	}

	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, lastName) || lastName.empty())
	{
		std::cout << "Invalid input. Contact not added." << std::endl;
		return;
	}

	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, nickname) || nickname.empty())
	{
		std::cout << "Invalid input. Contact not added." << std::endl;
		return;
	}

	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, phoneNumber) || phoneNumber.empty())
	{
		std::cout << "Invalid input. Contact not added." << std::endl;
		return;
	}

	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, darkestSecret) || darkestSecret.empty())
	{
		std::cout << "Invalid input. Contact not added." << std::endl;
		return;
	}

	int index = phoneBook.contactCount % 8;

	phoneBook.contacts[index].setFirstName(firstName);
	phoneBook.contacts[index].setLastName(lastName);
	phoneBook.contacts[index].setNickname(nickname);
	phoneBook.contacts[index].setPhoneNumber(phoneNumber);
	phoneBook.contacts[index].setDarkestSecret(darkestSecret);

	phoneBook.contactCount++;

	std::cout << "Contact added successfully!" << std::endl;
}

std::string PhoneBook::formatField(const std::string &field) const
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void PhoneBook::searchContact(int index) const
{
	(void)index;

	if (contactCount == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}

	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	int displayCount = (contactCount < 8) ? contactCount : 8;
	for (int i = 0; i < displayCount; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << formatField(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << formatField(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << formatField(contacts[i].getNickname()) << std::endl;
	}

	std::string input;
	std::cout << "Enter the index of the contact to display: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << "Invalid input." << std::endl;
		return;
	}

	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
	{
		int idx = input[0] - '0';
		if (idx < displayCount)
		{
			std::cout << "First Name: " << contacts[idx].getFirstName() << std::endl;
			std::cout << "Last Name: " << contacts[idx].getLastName() << std::endl;
			std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
			std::cout << "Phone Number: " << contacts[idx].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << contacts[idx].getDarkestSecret() << std::endl;
		}
		else
			std::cout << "Index out of range." << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			break;
		}
		if (command == "ADD" || command == "add")
			phoneBook.addContact(phoneBook);
		else if (command == "SEARCH" || command == "search")
			phoneBook.searchContact(0);
		else if (command == "EXIT" || command == "exit")
			break;
		else if (!command.empty())
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
