#ifndef PROPERTY_H
#define PROPERTY_H
#include <map>
#include <string>

namespace mc {

    /**
     * class for property files reading 
     */
    class properties {
        std::map<std::string, std::string> _properties;
        std::string _property_filename;
    public:
        /**
         * default constructor. associated implicitly with file "default.properties"
         */
        properties();
        /**
         * destructor
         */
        virtual ~properties();

        /**
         * load properties from file <b>filename</b>
         * @param filename
         */
        void load_properties(const std::string&);
        /**
         * check if property exists. return false if property <b>key</b>
         * does not exist.
         * @param key
         * @return 
         */
        bool has_property(const std::string&) const;
        /**
         * return value of property <b>key</b>.
         * is the same as <b>getProperty</b>.
         * @param key
         * @return 
         */
        const std::string& operator[](const std::string&) const;
        /**
         * return value of property <b>key</b>.
         * is the same as <b>operator []</b>.
         * @param key
         * @return 
         */
        const std::string& get_property(const std::string&) const;
        /**
         * returns name of associated property file
         * @return 
         */
        const std::string& filename() const;
        /**
         * returns all properties as map
         * @return 
         */
        const std::map<std::string, std::string>& all_properties() const;

        // for adding new properties
        /**
         * save all properties in property file <b>propertyFileName()</b>
         */
        void save();
        /**
         * create empty property file with name <b>filename</b>
         * @param filename
         */
        void create(const std::string&);
        /**
         * set a new property <b>key</b> with value <b>value</b>.
         * return value is reserved.
         * @param key
         * @param value
         * @return 
         */
        bool set_property(std::string, std::string);
    private:

    };
}

#endif /* PROPERTY_H */

