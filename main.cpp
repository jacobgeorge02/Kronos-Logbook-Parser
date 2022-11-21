// Copyright Jacob George 04/21/22
#include <iostream>
#include <string>
#include <fstream>
#include <boost/regex.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"

int main(int argc, const char* argv[]) {
    std::string whatLog = argv[1], line, temp;
    std::string bootMessage = "(log\\.c\\.166\\)\\sserver\\sstarted\\s";

    std::string bF = "SelectChannelConnector@\\d{1}.\\d{1}.";
    std::string bF2 = "INFO:oejs.AbstractConnector:Started\\s";
    std::string bF3 = "\\d{1}.\\d{1}:\\d{4}";
    std::string bF4 = "\\d{4}-\\d{2}-\\d{2}\\s\\d{2}:\\d{2}:\\d{2}.\\d{3}:";

    std::ofstream reportFile(whatLog + ".rpt");
    std::ifstream logFile;
    int pos = 0;
    bool result = 0;
    boost::regex bootStart
    ("\\d{4}-\\d{2}-\\d{2}\\s\\d{2}:\\d{2}:\\d{2}:\\s\\" + bootMessage);
    boost::regex bootCompleted(bF4 + bF2 + bF + bF3);
    boost::posix_time::ptime t;
    boost::posix_time::ptime t1;

    logFile.open(whatLog);
    if (!logFile.is_open()) {
        std::cout << "Log could not be opened";
        exit(1);
    }

    while (!logFile.eof()) {
        getline(logFile, line);
        pos+=1;
        temp = line.substr(0, 19);
        if (regex_match(line, bootStart)) {
            t = boost::posix_time::
            ptime(boost::posix_time::time_from_string(temp));
            if (result)
                reportFile << "**** Incomplete boot ****\n\n";
            result = 1;
            reportFile << "=== Device boot ===\n";
            reportFile << pos << "(" << whatLog << "): "
            << temp << " Boot Start\n";
        } else if (regex_match(line, bootCompleted)) {
            boost::posix_time::time_duration td = (t1 = boost::posix_time::
            ptime(boost::posix_time::time_from_string(temp))) - t;
            reportFile << pos << "(" << whatLog
            << "): " << temp << " Boot Completed\n";
            reportFile << "\t" << "Boot Time: "
            << td.total_milliseconds()  << "ms\n\n";
            result = 0;
        }
    }

    logFile.close();
    reportFile.close();
    return 0;
}
