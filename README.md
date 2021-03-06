# properties
Properties library propose a simple class for reading properties / ini file such as
```
#this is a property file
author = author
appName = Cool App
appVersion = 1.0
```
The class is defined in _mc_ namespace. Example of usage:
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
All leading and trailing white spaces / tabs will be ignored.
Empty lines will be ignored.
All bad property definition lines will be ignored.
Bad property definition:
 * property name is not defined
 * property value is not defined
 * property definition contains more than 1 copy operator

## How to use ##

Just download and compile. This is a NetBeans project, you can compile library using
this nice IDE.

Or do next:
```bash
git clone https://github.com/mcroitor/properties.git
cd properties
make
```
CMake build is proposed also:
```bash
git clone https://github.com/mcroitor/properties.git
cd properties
mkdir dist
cd dist
cmake .. -G "Unix Makefiles"
make
```

Sure, you can use any other CMake generator.

Example of use is represented in [example folder](https://github.com/mcroitor/properties/tree/master/examples). You can authomatically build this example by
command
```bash
make example --makefile=Makefile.example
```

## Interface of class Properties ##
```C++
class properties{
public:
  properties(); // default constructor. associated implicitly with file 'default.properties'
  void load_properties(const std::string& filename); // load properties from file 'filename'. exceptions are not analyzed
  bool has_property(const std::string& key) const; // check if property 'key' exists
  const std::string& operator[](const std::string& key) const; // get value of property 'key'
  const std::string& get_property(const std::string& key) const; // get value of property 'key'. pseudonim of operator []
  const std::string& filename() const; // returns name of associated property file
  const std::map<std::string, std::string>& all_properties() const; // returns all properties as map
  
  void save(); // save property file. 
  void create(const std::string& filename); // create a new property file with name 'filename' 
  bool set_property(std::string key, std::string value); // add new property key => value
};
```
