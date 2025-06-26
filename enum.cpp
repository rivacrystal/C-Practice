// June 26, 2025
// allows user to write a day of the week and outputs a sentence depending on the day
// practice enum, switch, and trimming

#include <iostream>
#include <string>
#include <algorithm> //for transform()

// declare enum
enum Day {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    InvalidDay
};

// convert string to enum
Day returnDay(const std::string today) {
    if (today == "SUNDAY") {
        return Sunday;
    } else if (today == "MONDAY") {
        return Monday;
    } else if (today == "TUESDAY") {
        return Tuesday;
    } else if (today == "WEDNESDAY") {
        return Wednesday;
    } else if (today == "THURSDAY") {
        return Thursday;
    } else if (today == "FRIDAY") {
        return Friday;
    } else if (today == "SATURDAY") {
        return Saturday;
    } else {
        return InvalidDay;
    }
}

// turn everything to uppercase to create consistency
std::string uppercase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), toupper);
    return result;
}

// print a response depending on day
void printDay(Day d) {
    switch(d) {
        case Monday:
            std::cout << "Weekend's over. :(" << std::endl;
            break;
        case Tuesday:
            std::cout << "Keep going strong!" << std::endl;
            break;
        case Wednesday:
            std::cout << "Hump day!" << std::endl;
            break;
        case Thursday:
            std::cout << "Almost there!" << std::endl;
            break;
        case Friday:
            std::cout << "TGIF!" << std::endl;
            break;
        case Saturday:
        case Sunday:
            std::cout << "It's the weekend!!" << std::endl;
            break;
        default:
            std::cout << "Invalid day." << std::endl;
    }
}

// remove whitespace
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" ");
    if (first == std::string::npos) {
        return "";
    }

    size_t last = str.find_last_not_of(" ");
    
    return str.substr(first, last - first + 1);
}

int main() {
    std::string input;

    std::cout << "Input a day: ";
    std::getline(std::cin, input);

    Day today = returnDay(uppercase(trim(input)));
    printDay(today);

    return 0;
}
