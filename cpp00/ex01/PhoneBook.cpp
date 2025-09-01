/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:38:57 by mde-maga          #+#    #+#             */
/*   Updated: 2025/09/01 13:50:00 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::GetFirstName(int id) {
	return (Contacts[id].GetFirstName());
}

std::string PhoneBook::GetLastName(int id) {
	return (Contacts[id].GetLastName());
}

std::string PhoneBook::GetNickname(int id) {
	return (Contacts[id].GetNickname());
}

void PhoneBook::SetContactId(int id, std::string First, std::string Last, std::string Nick, std::string Phone,
				std::string Secret) {
	Contacts[id].SetContact(First, Last, Nick, Phone, Secret);
}

void PhoneBook::IdPrintContact(int id) {
	Contacts[id].PrintContact();
}

int PhoneBook::isContactUsed(int id) {
	return (Contacts[id].ContactExists());
}

bool PhoneBook::isFull() {
	for (int i = 0; i < MaxId; ++i) {
		if (!isContactUsed(i))
			return false;
	}
	return true;
}

std::string PhoneBook::GetContactFullName(int id) {
	if (id < 0 || id >= MaxId)
		return std::string();
	if (!isContactUsed(id))
		return std::string();

	std::string first = GetFirstName(id);
	std::string last  = GetLastName(id);

	if (first.empty() && last.empty())
		return std::string();

	std::ostringstream oss;
	if (!first.empty())
		oss << first;
	if (!last.empty()) {
		if (!first.empty())
			oss << ' ';
		oss << last;
	}
	return oss.str();
}

void TruncateAndReplace(std::string &str) {
	if (str.length() > MaxLength) {
		str.resize(MaxLength - 1);
		str += ".";
	}
}

void PhoneBook::ListPhoneBook() {
	std::string separator = "+----------+----------+----------+----------+\n";
	std::cout << separator
		    << std::right
		    << "|" << std::setw(10) << "Index"
		    << "|" << std::setw(10) << "First Name"
		    << "|" << std::setw(10) << "Last Name"
		    << "|" << std::setw(10) << "Nick Name"
		    << "|\n" << separator;

	// iterate all slots (0..MaxId-1) and print only those that exist
	for (int id = 0; id < MaxId; ++id) {
		if (!Contacts[id].ContactExists())
			continue;

		std::string firstname = GetFirstName(id);
		TruncateAndReplace(firstname);
		std::string lastname = GetLastName(id);
		TruncateAndReplace(lastname);
		std::string nickname = GetNickname(id);
		TruncateAndReplace(nickname);
		std::cout << "|" << std::setw(10) << id
			    << "|" << std::setw(10) << firstname
			    << "|" << std::setw(10) << lastname
			    << "|" << std::setw(10) << nickname
			    << "|" << std::endl;
	}
	std::cout << separator;
}
