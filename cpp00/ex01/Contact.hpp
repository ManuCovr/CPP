/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:28:23 by mde-maga          #+#    #+#             */
/*   Updated: 2025/09/01 11:53:06 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_CONTACT_H
#define EX01_CONTACT_H

#include <iostream>


class Contact {
private:
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string PhoneNumber;
    std::string DarkestSecret;
    bool Initialized;

public:
    Contact() : Initialized(false) {};

    void SetContact(std::string First, std::string Last, std::string Nick, std::string Phone, std::string Secret);

    void PrintContact();

    int ContactExists();

    std::string GetFirstName();

    std::string GetLastName();

    std::string GetNickname();

};

#endif
