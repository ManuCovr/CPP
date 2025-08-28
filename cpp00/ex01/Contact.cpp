/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:27:55 by mde-maga          #+#    #+#             */
/*   Updated: 2025/08/15 12:28:05 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


void Contact::SetContact(std::string First, std::string Last, std::string Nick, std::string Phone, std::string Secret) {
	FirstName = First;
	LastName = Last;
	Nickname = Nick;
	PhoneNumber = Phone;
	DarkestSecret = Secret;
	Initialized = true;
}

void Contact::PrintContact() {
	std::cout << (FirstName + "\n" + LastName + "\n" + Nickname + "\n" + PhoneNumber +
			  "\n" + DarkestSecret + "\n");
}

int Contact::ContactExists() {
	return (Initialized);
}

std::string Contact::GetFirstName() {
	return (FirstName);
}

std::string Contact::GetLastName() {
	return (LastName);
}

std::string Contact::GetNickname() {
	return (Nickname);
}