#include "property.h"
#include <fstream>
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

namespace mc {

    /**
     * default constructor. associated implicitly with file "default.properties"
     */
    properties::properties() : _property_filename("default.properties") {
    }

    /**
     * destructor
     */
    properties::~properties() = default;

    /**
     * load properties from file <b>filename</b>
     * @param filename
     */
    void properties::load_properties(const std::string& filename) {
        _property_filename = filename;
        std::ifstream fin(_property_filename);
        std::string str;
        while (!fin.eof()) {
            std::getline(fin, str);
            str = trim(str);
            // TODO # for future add support for comments
            if (str.front() == '#') {
                continue;
            }
            std::size_t pos = str.find('=');
            std::size_t rpos = str.rfind('=');
            if (pos == 0 || pos == std::string::npos || pos != rpos) {
                // oops! bad line!
                continue;
            }
            std::string key = trim(str.substr(0, pos));
            std::string val = trim(str.substr(pos + 1, std::string::npos));
            _properties.insert(
                    std::make_pair(key, val)
                    );
        }
        fin.close();
    }

    /**
     * check if property exists. return false if property <b>key</b>
     * does not exist.
     * @param key
     * @return 
     */
    bool properties::has_property(std::string key) const {
        return _properties.count(key) == 1;
    }

    /**
     * return value of property <b>key</b>.
     * is the same as <b>getProperty</b>.
     * @param key
     * @return 
     */
    const std::string& properties::operator[](const std::string& key) const {
        return _properties.at(key);
    }

    /**
     * return value of property <b>key</b>.
     * is the same as <b>operator []</b>.
     * @param key
     * @return 
     */
    const std::string& properties::get_property(const std::string& key) const {
        return _properties.at(key);
    }

    /**
     * returns name of associated property file
     * @return 
     */
    const std::string& properties::filename() const {
        return _property_filename;
    }

    /**
     * returns all properties as map
     * @return 
     */
    const std::map<std::string, std::string>& properties::all_properties() const {
        return _properties;
    }

    /**
     * save all properties in property file <b>propertyFileName()</b>
     */
    void properties::save() {
        // TODO # : bug/feature - it ignore all commentaries!
        std::ofstream fout(_property_filename);
        std::map<std::string, std::string>::iterator it = _properties.begin();
        while (it != _properties.end()) {
            fout << (*it).first << " = " << (*it).second << std::endl;
            ++it;
        }
        fout.close();
    }

    /**
     * create empty property file with name <b>filename</b>
     * @param filename
     */
    void properties::create(const std::string& filename) {
        _property_filename = filename;
        std::ofstream fout(_property_filename);
        fout << std::endl;
        fout.close();
    }

    /**
     * set a new property <b>key</b> with value <b>value</b>.
     * return value is reserved.
     * @param key
     * @param value
     * @return 
     */
    bool properties::set_property(std::string key, std::string value) {
        _properties.insert(std::make_pair(key, value));
        return true;
    }
}