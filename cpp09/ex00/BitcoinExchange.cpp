#include "BitcoinExchange.hpp"


static std::string trim(const std::string &s) {
    size_t start = s.find_first_not_of(' ');
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(' ');
    return s.substr(start, end - start + 1);
}


BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange::BitcoinExchange(std::string file_path, std::string csv_path) {
    data_(csv_path);
    input_(file_path);
}


void BitcoinExchange::print(float rate, std::string date) {
    std::map<std::string, float>::iterator it = data.upper_bound(date);
    if (it == data.begin()) {
        err_str = "bad input => " + date;
        err();
        return;
    }
    --it;
    std::cout << date << " => " << rate << " = " << it->second * rate << std::endl;
}


void BitcoinExchange::parse_file(void) {}


bool BitcoinExchange::check_month(unsigned int month) {
    return (month > 0 && month < 13);
}


bool BitcoinExchange::isleap(unsigned int year) {
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}


bool BitcoinExchange::check_day(unsigned int day, unsigned int month, unsigned int year) {
    if (day > 31 || day < 1)
        return false;
    else if (month == 2) {
        if (isleap(year))
            return (day <= 29);
        else
            return (day <= 28);
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);
    return true;
}


bool BitcoinExchange::check_year(unsigned int year) {
    return (year >= 2009 && year < 9999);
}


bool BitcoinExchange::check_date(std::string date) {
    unsigned int year, month, day;
    char dash1, dash2;
    std::istringstream stream(date);
    if (!(stream >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
        err_str = "bad input => " + date;
        return false;
    } else if (!check_year(year) || !check_month(month) || !check_day(day, month, year)) {
        err_str = "bad input => " + date;
        return false;
    }
    return true;
}


void BitcoinExchange::err() {
    std::cerr << "Error: " << err_str << std::endl;
}


void BitcoinExchange::check_and_print(void) {
    std::string line;
    struct stat st;
    if (stat(input_path.c_str(), &st) == 0 && S_ISDIR(st.st_mode)) {
        err_str = "could not open file.";
        err();
        return;
    }
    std::ifstream file(input_path.c_str());
    if (!file.is_open()) {
        err_str = "could not open file.";
        err();
        return;
    }
    std::getline(file, line);
    if (trim(line) != "date | value")
        file.seekg(0);
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        size_t pipe = line.find('|');
        if (pipe == std::string::npos) {
            err_str = "bad input => " + line;
            err();
            continue;
        }
        std::string key = trim(line.substr(0, pipe));
        std::string value_str = trim(line.substr(pipe + 1));
        if (key.empty() || value_str.empty()) {
            err_str = "bad input => " + line;
            err();
            continue;
        }
        if (!check_data(value_str, 2) || !check_date(key)) {
            err();
            continue;
        }
        float float_v = std::strtof(value_str.c_str(), NULL);
        if (float_v > 1000) {
            err_str = "too large a number.";
            err();
        } else
            print(float_v, key);
    }
    file.close();
}


void BitcoinExchange::input_(std::string input) {
    input_path = input;
    check_and_print();
}


std::ostream &operator<<(std::ostream &o, BitcoinExchange &BTC) {
    (void)BTC;
    o << "BitcoinExchange\n";
    return o;
}


bool BitcoinExchange::isdigit_(std::string nbr) {
    for (unsigned long i = 0; i < nbr.size(); i++)
        if (!isdigit(nbr[i]) && nbr[i] != ' ')
            return false;
    return true;
}


bool BitcoinExchange::isdigit_(std::string nbr, char ignor) {
    for (unsigned long i = 0; i < nbr.size(); i++) {
        if (nbr[i] == '-') {
            err_str = "not a positive number.";
            return false;
        } else if (!isdigit(nbr[i]) && nbr[i] != ignor && nbr[i] != ' ') {
            err_str = "not a valid number.";
            return false;
        }
    }
    return true;
}


bool BitcoinExchange::check_data(std::string data, int order) {
    if (order == 1 || order == 3) {
        if (order == 1 && data.size() > 10)
            return false;
        else if (order == 3 && ((data[data.size() - 1] != ' ') || data.size() > 11))
            return false;
        else if (data[4] != data[7] && data[7] != '-')
            return false;
        char *cstr = new char[data.size() + 1];
        std::strcpy(cstr, data.c_str());
        char *value = strtok(cstr, "-");
        while (value) {
            if (!isdigit_(value)) {
                delete[] cstr;
                return false;
            }
            value = strtok(NULL, "-");
        }
        delete[] cstr;
    } else if (order == 2) {
        if (!isdigit_(data, '.'))
            return false;
    }
    return true;
}


void BitcoinExchange::data_(std::string path) {
    data_path = path;
    std::string line;
    std::ifstream file(data_path.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database." << std::endl;
        std::exit(1);
    }
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        char *cstr = new char[line.size() + 1];
        std::strcpy(cstr, line.c_str());
        char *key = strtok(cstr, ",");
        char *value = strtok(NULL, ",");
        if (!key || !value || strtok(NULL, ",") != NULL) {
            delete[] cstr;
            std::cerr << "Error: bad database." << std::endl;
            std::exit(1);
        }
        if (!check_data(key, 1) || !check_data(value, 2)) {
            delete[] cstr;
            std::cerr << "Error: bad database." << std::endl;
            std::exit(1);
        }
        data[key] = std::strtof(value, NULL);
        delete[] cstr;
    }
    file.close();
}


BitcoinExchange::BitcoinExchange(BitcoinExchange &btc) {
    this->data = btc.data;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc) {
    if (this == &btc)
        return *this;
    this->data = btc.data;
    return *this;
}