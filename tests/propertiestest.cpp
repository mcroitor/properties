#include <cstdlib>
#include <iostream>
#include "../properties.h"

/*
 * Simple C++ Test Suite
 */

void testLoadProperties() {
    std::string filename = "config.properties";
    mc::properties property;

    try {
        property.load_properties(filename);
        std::cout << "%TEST PASSED% time=0 testname=testLoadProperties (propertytest) message=test passed" << std::endl;
    } catch (std::exception& e) {
        std::cout << "%TEST_FAILED% time=0 testname=testLoadProperties (propertytest) message=" << e.what() << std::endl;
    }
}

void testHasProperty() {
    std::string key = "author";
    std::string filename = "config.properties";
    mc::properties property;
    property.load_properties(filename);
    bool result = property.has_property(key);
    if (result == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasProperty (propertytest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testHasProperty (propertytest) message=test passed" << std::endl;
    }
}

void testHasNoProperty() {
    std::string key = "version";
    std::string filename = "config.properties";
    mc::properties property;
    property.load_properties(filename);
    bool result = property.has_property(key);
    if (result == true) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasNoProperty (propertytest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testHasNoProperty (propertytest) message=test passed" << std::endl;
    }
}

void testGetProperty() {
    std::string key = "author";
    std::string value = "author";
    std::string filename = "config.properties";
    mc::properties property;
    property.load_properties(filename);
    std::string result = property[key];
    if (result != value) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetProperty (propertytest) message= found value is " << result << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testGetProperty (propertytest) message=test passed" << std::endl;
    }
}

void testPropertyFileName() {
    std::string filename = "config.properties";
    mc::properties property;
    property.load_properties(filename);
    const std::string& result = property.filename();
    if (result != filename) {
        std::cout << "%TEST_FAILED% time=0 testname=testPropertyFileName (propertytest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testPropertyFileName (propertytest) message=test passed" << std::endl;
    }
}

void testSetProperty() {
    // TODO # finalize this
    std::string filename = "test.properties";
    std::string key = "key";
    std::string value = "value";

    mc::properties property;
    //property.create(filename);
    property.set_property(key, value);

    if (property.has_property(key) == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testSetProperty (propertytest) message=key '" << key << "' not exists" << std::endl;
        return;
    }
    if (property[key] != value) {
        std::cout << "%TEST_FAILED% time=0 testname=testSetProperty (propertytest) message=incorrect value of key" << std::endl;
        return;
    }

    std::cout << "%TEST PASSED% time=0 testname=testSetProperty (propertytest) message=test passed" << std::endl;
}

void testLoadBadProperties() {
    std::string filename = "bad.properties";
    mc::properties property;

    try {
        property.load_properties(filename);
        if(property.all_properties().size() == 3){
            std::cout << "%TEST PASSED% time=0 testname=testLoadBadProperties (propertytest) message=test passed" << std::endl;
        }
        else{
            std::cout << "%TEST_FAILED% time=0 testname=testLoadBadProperties (propertytest) message=some bad properties not ignored" << std::endl;
            std::cout << "message=total " << property.all_properties().size() << " properties was loaded" << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "%TEST_FAILED% time=0 testname=testLoadBadProperties (propertytest) message=" << e.what() << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% propertytest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testLoadProperties (propertytest)" << std::endl;
    testLoadProperties();
    std::cout << "%TEST_FINISHED% time=0 testLoadProperties (propertytest)" << std::endl;

    std::cout << "%TEST_STARTED% testHasProperty (propertytest)" << std::endl;
    testHasProperty();
    std::cout << "%TEST_FINISHED% time=0 testHasProperty (propertytest)" << std::endl;

    std::cout << "%TEST_STARTED% testHasNoProperty (propertytest)" << std::endl;
    testHasNoProperty();
    std::cout << "%TEST_FINISHED% time=0 testHasNoProperty (propertytest)" << std::endl;

    std::cout << "%TEST_STARTED% testGetProperty (propertytest)" << std::endl;
    testGetProperty();
    std::cout << "%TEST_FINISHED% time=0 testGetProperty (propertytest)" << std::endl;

    std::cout << "%TEST_STARTED% testSetProperty (propertytest)" << std::endl;
    testSetProperty();
    std::cout << "%TEST_FINISHED% time=0 testSetProperty (propertytest)" << std::endl;

    std::cout << "%TEST_STARTED% testPropertyFileName (propertytest)" << std::endl;
    testPropertyFileName();
    std::cout << "%TEST_FINISHED% time=0 testPropertyFileName (propertytest)" << std::endl;

    std::cout << "%TEST_STARTED% testLoadBadProperties (propertytest)" << std::endl;
    testLoadBadProperties();
    std::cout << "%TEST_FINISHED% time=0 testLoadBadProperties (propertytest)" << std::endl;
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

