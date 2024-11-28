﻿#include "User.h"
#include <regex>
#include <algorithm>
#include <ctime>

std::vector<std::string> User::takenUsernames;
std::vector<std::string> User::userPasswords;

User::User(const std::string& username, const std::string& password, int scr, int uppt)
    : m_score(scr), m_upgradePoints(uppt), m_validUsername(false), m_validPassword(false)
{
    if (!isValidUsername(username)) {
        std::cerr << "Invalid username: " << username << std::endl;
        return;
    }

    if (!isValidPassword(password)) {
        std::cerr << "Invalid password." << std::endl;
        return;
    }

    this->m_username = username;
    this->m_password = password;
    this->m_accountCreated = std::time(nullptr);
    this->m_validUsername = true;
    this->m_validPassword = true;

    // Debugging
    std::cout << "User created - Username: " << m_username
        << ", Password: " << m_password << std::endl;
}

int User::getUserId() const
{
    return m_userID;
}



std::string User::getUsername() const {
    return m_username;
}

std::string User::getPassword() const {
    return m_password;
}

bool User::isUsernameValid() const {
    return m_validUsername;
}

bool User::isPasswordValid() const {
    return m_validPassword;
}

bool User::setUsername(const std::string& newUsername) {
    if (isValidUsername(newUsername) && std::find(takenUsernames.begin(), takenUsernames.end(), newUsername) == takenUsernames.end()) {
        m_username = newUsername;
        takenUsernames.push_back(newUsername);
        return true;
    }
    return false;
}

bool User::setPassword(const std::string& newPassword) {
    if (isValidPassword(newPassword) && checkPasswordStrength(newPassword)) {
        m_password = newPassword;
        return true;
    }
    return false;
}

std::time_t User::getAccountCreationTime() const {
    return m_accountCreated;
}

bool User::authenticate(const std::string& inputPassword) {

    auto it = std::find(takenUsernames.begin(), takenUsernames.end(), m_username);
    if (it != takenUsernames.end()) {
        size_t index = std::distance(takenUsernames.begin(), it);
        return userPasswords[index] == inputPassword;
    }
    return false;
}

bool User::resetPassword(const std::string& oldPassword, const std::string& newPassword) {
    if (authenticate(oldPassword) && isValidPassword(newPassword)) {
        m_password = newPassword;

        auto it = std::find(takenUsernames.begin(), takenUsernames.end(), m_username);
        if (it != takenUsernames.end()) {
            size_t index = std::distance(takenUsernames.begin(), it);
            userPasswords[index] = newPassword;
        }
        return true;
    }
    return false;
}

bool User::checkPasswordStrength(const std::string& password) const {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    std::regex specialChars("[!@#$%^&*(),.?\":{}|<>]");

    for (char ch : password) {
        if (std::isupper(ch)) hasUpper = true;
        if (std::islower(ch)) hasLower = true;
        if (std::isdigit(ch)) hasDigit = true;
        if (std::regex_match(std::string(1, ch), specialChars)) hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int User::getScore() const
{
    return m_score;
}

int User::getUpgradePoints() const
{
    return m_upgradePoints;
}

void User::setScore(int scr)
{
    m_score = scr;
}

void User::setUpgradePoints(int upt)
{
    m_upgradePoints = upt;
}

bool User::isValidUsername(const std::string& name) {
    try {
        std::regex pattern("^[a-zA-Z0-9_.]{3,30}$");
        return std::regex_match(name, pattern);
    }
    catch (const std::regex_error& e) {
        std::cerr << "Regex error in username validation: " << e.what() << std::endl;
        return false;
    }
}

bool User::isValidPassword(const std::string& password) {
    try {
        std::regex pattern("^[a-zA-Z0-9!@#$%^&*()_+=?]{8,20}$");
        return std::regex_match(password, pattern);
    }
    catch (const std::regex_error& e) {
        std::cerr << "Regex error in password validation: " << e.what() << std::endl;
        return false;
    }
}
