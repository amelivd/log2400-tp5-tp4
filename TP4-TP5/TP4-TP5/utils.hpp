#pragma once

#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <array>
#include <string>

std::tm parseDateTime(std::string date_str, std::string time_str) {
    std::tm result = {};

    std::istringstream date_stream(date_str);
    date_stream >> std::get_time(&result, "%Y-%m-%d");

    std::istringstream time_stream(time_str);
    std::tm time_tmp = {};
    time_stream >> std::get_time(&time_tmp, "%H:%M");

    result.tm_hour = time_tmp.tm_hour;
    result.tm_min = time_tmp.tm_min;

    return result;
}

std::string formatDate(std::string inputDate) {
    std::string anneeStr = inputDate.substr(0, 4);
    std::string moisStr = inputDate.substr(5, 2);
    std::string jourStr = inputDate.substr(8, 2);

    int moisNum = std::stoi(moisStr);

    std::array<std::string, 12> mois = {
        "janvier", "février", "mars", "avril", "mai", "juin",
        "juillet", "août", "septembre", "octobre", "novembre", "décembre"
    };

    if (jourStr[0] == '0') {
        jourStr = jourStr[1];
    }

    return jourStr + " " + mois[moisNum - 1] + " " + anneeStr;
}