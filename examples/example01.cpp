#include <iostream>
#include <string>
#include "../properties.h"

int main(int argc, char ** argv) {
    // property file is specified as app parameter
    if(argc == 1){
        std::cout << "no property file specified" << std::endl 
                << "example of use: example01 <propertyfile>";
        return 0;
    }
    std::string property_file = argv[1];
    
    // properties names
    std::string maxvalue_property = "maxvalue";
    std::string minvalue_property = "minvalue";
    
    mc::properties p;    
    p.load_properties(property_file);

    std::cout << "loaded property file: " << p.filename() << std::endl;
    std::cout << "total properties loaded: " << p.all_properties().size() << std::endl;
    if (p.has_property(maxvalue_property)) {
        std::cout << maxvalue_property << ": " << p.get_property(maxvalue_property) << std::endl;
    }
    if (p.has_property(minvalue_property)) {
        std::cout << minvalue_property << ": " << p.get_property(minvalue_property) << std::endl;
    }
    return 0;
}