#include <string>

/**
 * helper function. remove leading spaces/tabs from string 
 * @param str
 * @return 
 */
std::string ltrim(std::string str) {
    while (str.front() == ' ' || str.front() == '\t') {
        str.erase(str.begin());
    }
    return str;
}

/**
 * helper function. remove spaces/tabs from end of string
 * @param str
 * @return 
 */
std::string rtrim(std::string str) {
    while (str.back() == ' ' || str.back() == '\t') {
        str.pop_back();
    }
    return str;
}

/**
 * helper function. remove spaces/tabs from begin and end of string
 * @param str
 * @return 
 */
std::string trim(std::string str) {
    return ltrim(rtrim(str));
}