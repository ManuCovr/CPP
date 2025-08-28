/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:41:06 by mde-maga          #+#    #+#             */
/*   Updated: 2025/08/15 13:22:10 by mde-maga         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

bool isNumeric(const std::string &str) {
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

int main() {
	std::cout << "Welcome!\n";
	sleep(2);
	std::system("clear");
	std::cout << "Loading, please be patient...\n";
	sleep(1);
	std::system("clear");
	PhoneBook Book;
	int nextId = 0;

	while (1) {
		std::cout << "\nPlease input: ADD, SEARCH or EXIT\n";
		std::string input;
		std::cin >> input;
		std::system("clear");

		if (input == "ADD") {
			int insertIndex = -1;

			if (Book.isFull()) {
				// will overwrite nextId
				insertIndex = nextId;
				std::string oldest = Book.GetContactFullName(insertIndex);
				if (oldest.empty())
					oldest = "(unknown)";

				std::cout << "Warning: Adding this new contact will delete the oldest one, in this case \""
						  << oldest << "\".\n";
				std::cout << "Do you want to continue? (Y/N): ";
				char ans;
				std::cin >> ans;
				// clear leftover input so following getline works
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (ans != 'Y' && ans != 'y') {
					std::cout << "Add cancelled.\n";
					sleep(1);
					std::system("clear");
					continue;
				}
			} else {
				// find first free slot (lowest index)
				for (int i = 0; i < MaxId; ++i) {
					if (!Book.isContactUsed(i)) {
						insertIndex = i;
						break;
					}
				}
			}

			// Defensive fallback (shouldn't happen)
			if (insertIndex < 0)
				insertIndex = nextId;

			// Collect contact fields (validation as before)
			std::string First;
			std::string Last;
			std::string Nick;
			std::string Phone;
			std::string Secret;

			std::system("clear");

			std::cout << "First Name: ";
			// ensure no leftover newline
			// (when coming from std::cin >> input earlier)
			// safe to ignore a single newline here
			// we already ignored after confirmation above if needed
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			while (First.empty()) {
				std::getline(std::cin, First);
				if (First.empty()) {
					std::cout << "You can't have an empty first name. Try again...\n";
					std::cout << "Please input first name: ";
				}
			}

			std::cout << "\nLast Name: ";
			while (Last.empty()) {
				std::getline(std::cin, Last);
				if (Last.empty()) {
					std::cout << "You can't have an empty last name. Try again...\n";
					std::cout << "Please input last name: ";
				}
			}

			std::cout << "\nNick Name: ";
			while (Nick.empty()) {
				std::getline(std::cin, Nick);
				if (Nick.empty()) {
					std::cout << "You can't have an empty nick name. Try again...\n";
					std::cout << "Please input nick name: ";
				}
			}

			std::cout << "\nPhone Number: ";
			while (true) {
				std::getline(std::cin, Phone);
				if (!isNumeric(Phone) || Phone.length() < 3) {
					std::cout << "Invalid phone number. Please use digits only (min 3 numbers): ";
					continue;
				}
				break;
			}

			std::cout << "\nDarkest Secret: ";
			while (Secret.empty()) {
				std::getline(std::cin, Secret);
				if (Secret.empty()) {
					std::cout << "You're hiding something... Try again...\n";
					std::cout << "Please input your darkest secret: ";
				}
			}

			Book.SetContactId(insertIndex, First, Last, Nick, Phone, Secret);

			// advance the circular nextId so the next overwrite is correct
			nextId = (insertIndex + 1) % MaxId;

			std::cout << "\nContact saved (slot " << insertIndex << ").\n";
			sleep(1);
			std::system("clear");

		} else if (input == "SEARCH") {
			std::system("clear");
			Book.ListPhoneBook();
			std::cout << "\nType id for full informations: ";
			std::string input2;
			std::cin >> input2;
			const char *cstr = input2.c_str();
			int id = atoi(cstr);
			// validate id properly against MaxId
			if ((id == 0 && cstr[0] != '0' && cstr[1] == 0) || id < 0 || id >= MaxId || !Book.isContactUsed(id)) {
				std::cout << "Invalid ID";
				sleep(1);
				std::system("clear");
				continue;
			}
			std::system("clear");
			Book.IdPrintContact(id);
		} else if (input == "EXIT") {
			return (0);
		}
	}
}