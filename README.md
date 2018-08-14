# properties
a simple class for reading properties file such as
```
#this is a property file
author = author
appName = Cool App
appVersion = 1.0
```
Defined in _mc_ namespace. Example of usage:
```C++
// a key, specified in property file ( may be :-/ )
std::string key = "author";
// property file name
std::string filename = "config.properties";
// set properties variable ...
mc::properties properties;
// ... and load properties
properties.load_properties(filename);
std::cout << properties.filename(); // returns opened property file
// if specified key exists, access this property 
if(properties.has_key(key) == true){ // check if key exists
  std::string result = properties[key]; // access property by [] operator
}
 ```
All comments from property file will be ignored.
All leading and trailing whitespaces / tabs will be ignored.
Empty lines will be ignored.
All bad property definition lines will be ignored.
Bad property definition:
 * property name is not defined
 * property value is not defined
 * property definition contains more than 1 copy operator

## Interface of class Properties ##
```C++
class properties{
public:
  properties(); // default constructor. associated implicitly with file 'default.properties'
  void load_properties(const std::string& filename); // load properties from file 'filename'. exceptions are not analyzed
  bool has_property(std::string key) const; // check if property 'key' exists
  const std::string& operator[](const std::string& key) const; // get value of property 'key'
  const std::string& get_property(const std::string& key) const; // get value of property 'key'. pseudonim of operator []
  const std::string& filename() const; // returns name of associated property file
  const std::map<std::string, std::string>& all_properties() const; // returns all properties as map
  
  void save(); // save property file. 
  void create(const std::string& filename); // create a new property file with name 'filename' 
  bool set_property(std::string key, std::string value); // add new property key => value
};
```
