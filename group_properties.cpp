#include "property.h"
#include <fstream>
#include <iostream>
#include <string>

std::string ltrim(std::string str);
std::string rtrim(std::string str);
std::string trim(std::string str);

namespace mc {

    group_properties::group_properties() : _property_filename("default.properties") {
    }

    group_properties::~group_properties() {
    }

    void group_properties::load_properties(const std::string& filename) {
        // default group
        std::string current_group = "_";
        if(has_group(current_group) == false){
            add_group(current_group);
        }

        _property_filename = filename;
        std::ifstream fin(_property_filename);
        std::string str;
        while (!fin.eof()) {
            std::getline(fin, str);
            str = trim(str);
            // section check
            if(str.front() == '[' && str.back() == ']'){
                current_group = str.substr(1, str.size() - 2);
                if(has_group(current_group) == false){
                    add_group(current_group);
                }
                continue;
            }
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
            get_group(current_group).add_property(key, val);
        }
        fin.close();
    }
    
    bool group_properties::has_group(const std::string& group_name) const{
        return _properties.count(group_name) == 1;
    }

    bool group_properties::has_property(const std::string& group_name, const std::string& key) const {
        return  has_group(group_name) && get_group(group_name).has_property(key) == 1;
    }

    const properties& group_properties::operator[](const std::string& group_name) const {
        return _properties.at(group_name);
    }

    properties& group_properties::get_group(const std::string& group_name){
        return _properties.at(group_name);
    }
    const properties& group_properties::get_group(const std::string& group_name) const{
        return _properties.at(group_name);
    }
    const std::string& group_properties::get_property(const std::string& group_name, const std::string& key) const {
        return get_group(group_name).get_property(key);
    }

    const std::string& group_properties::filename() const {
        return _property_filename;
    }

    const std::map<std::string, properties>& group_properties::all_properties() const {
        return _properties;
    }

    void group_properties::save() {
        // TODO#: implement this
    }
    
    void group_properties::add_group(const std::string& group_name){
        if(has_group(group_name) == true){
            return;
        }
        _properties[group_name] = properties();
    }
}