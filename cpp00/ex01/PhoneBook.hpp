/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:39:18 by mde-maga          #+#    #+#             */
/*   Updated: 2025/09/01 11:51:48 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EX01_PHONEBOOK_H
#define EX01_PHONEBOOK_H

#include "Contact.hpp"
#include "header.hpp"

class PhoneBook {
private:
    Contact Contacts[MaxId];

    std::string GetFirstName(int id);
    std::string GetLastName(int id);
    std::string GetNickname(int id);

public:
    void SetContactId(int id, std::string First, std::string Last, std::string Nick, std::string Phone, std::string Secret);
    void IdPrintContact(int id);
    int isContactUsed(int id);
    void ListPhoneBook();

    bool isFull();
    std::string GetContactFullName(int id);
};

#endif

