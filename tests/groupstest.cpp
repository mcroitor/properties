#include <cstdlib>
#include <iostream>
#include "property.h"

/*
 * Simple C++ Test Suite
 */

const std::string filename = "groups.properties";

void testLoadProperties() {
    mc::group_properties property;

    try {
        property.load_properties(filename);
        std::cout << "%TEST PASSED% time=0 testname=testLoadProperties (grouptest) message=test passed" << std::endl;
    } catch (std::exception& e) {
        std::cout << "%TEST_FAILED% time=0 testname=testLoadProperties (grouptest) message=" << e.what() << std::endl;
    }
}

void testHasGroup() {
    std::string group_name = "default";
    mc::group_properties property;
    property.load_properties(filename);
try {
    bool result = property.has_group(group_name);
    if (result == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasProperty (grouptest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testHasProperty (grouptest) message=test passed" << std::endl;
    }
    } catch (std::exception& e) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasProperty (grouptest) message=" << e.what() << std::endl;
    }
}

void testHasProperty() {
    std::string key = "author";
	std::string group_name = "default";
    mc::group_properties property;
    property.load_properties(filename);
    if (property.has_group(group_name) == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasProperty (grouptest) message=group not found" << std::endl;
    }
    bool result = property.has_property(group_name, key);
    if (result == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasProperty (grouptest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testHasProperty (grouptest) message=test passed" << std::endl;
    }
}

void testHasNoProperty() {
    std::string key = "version";
	std::string group_name = "default";
    mc::group_properties property;
    property.load_properties(filename);
    if (property.has_group(group_name) == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasProperty (grouptest) message=group not found" << std::endl;
    }
    bool result = property.has_property(group_name, key);
    if (result == true) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasNoProperty (grouptest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testHasNoProperty (grouptest) message=test passed" << std::endl;
    }
}

void testGetProperty() {
    std::string key = "author";
    std::string value = "author";
	std::string group_name = "default";
    mc::group_properties property;
    property.load_properties(filename);

    if (property.has_group(group_name) == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasProperty (grouptest) message=group not found" << std::endl;
    }

    if (property.has_property(group_name, key) == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testHasProperty (grouptest) message=property key not found" << std::endl;
    }

    std::string result = property[group_name][key];
    if (result != value) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetProperty (grouptest) message= found value is " << result << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testGetProperty (grouptest) message=test passed" << std::endl;
    }
}

void testPropertyFileName() {
    mc::group_properties property;
	std::string group_name = "default";
    property.load_properties(filename);
    const std::string& result = property.filename();
    if (result != filename) {
        std::cout << "%TEST_FAILED% time=0 testname=testPropertyFileName (grouptest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST PASSED% time=0 testname=testPropertyFileName (grouptest) message=test passed" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% grouptest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testLoadProperties (grouptest)" << std::endl;
    testLoadProperties();
    std::cout << "%TEST_FINISHED% time=0 testLoadProperties (grouptest)" << std::endl;

    std::cout << "%TEST_STARTED% testHasGroup (grouptest)" << std::endl;
    testHasGroup();
    std::cout << "%TEST_FINISHED% time=0 testHasGroup (grouptest)" << std::endl;    

	std::cout << "%TEST_STARTED% testHasProperty (grouptest)" << std::endl;
    testHasProperty();
    std::cout << "%TEST_FINISHED% time=0 testHasProperty (grouptest)" << std::endl;

    std::cout << "%TEST_STARTED% testHasNoProperty (grouptest)" << std::endl;
    testHasNoProperty();
    std::cout << "%TEST_FINISHED% time=0 testHasNoProperty (grouptest)" << std::endl;

    std::cout << "%TEST_STARTED% testGetProperty (grouptest)" << std::endl;
    testGetProperty();
    std::cout << "%TEST_FINISHED% time=0 testGetProperty (grouptest)" << std::endl;

    std::cout << "%TEST_STARTED% testPropertyFileName (grouptest)" << std::endl;
    testPropertyFileName();
    std::cout << "%TEST_FINISHED% time=0 testPropertyFileName (grouptest)" << std::endl;
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

