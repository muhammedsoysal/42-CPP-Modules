#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact(PhoneBook &phoneBook)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	while (firstName.empty())
	{
		std::cout << "First name cannot be empty. Enter first name: ";
		std::getline(std::cin, firstName);
	}

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	while (lastName.empty())
	{
		std::cout << "Last name cannot be empty. Enter last name: ";
		std::getline(std::cin, lastName);
	}

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "Nickname cannot be empty. Enter nickname: ";
		std::getline(std::cin, nickname);
	}

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.empty())
	{
		std::cout << "Phone number cannot be empty. Enter phone number: ";
		std::getline(std::cin, phoneNumber);
	}

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.empty())
	{
		std::cout << "Darkest secret cannot be empty. Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
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
	std::getline(std::cin, input);

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
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add")
			phoneBook.addContact(phoneBook);
		else if (command == "SEARCH" || command == "search")
			phoneBook.searchContact(0);
		else if (command == "EXIT" || command == "exit")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
