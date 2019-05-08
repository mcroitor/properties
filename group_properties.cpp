#include "property.h"

namespace mc {

    group_properties::group_properties() : _property_filename("default.properties") {
    }

    group_properties::~group_properties() {
    }

    void group_properties::load_properties(const std::string& filename) {
        // TODO#: implement this
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
}