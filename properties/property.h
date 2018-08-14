#ifndef PROPERTY_H
#define PROPERTY_H
#include <map>
#include <string>

namespace mc {

    class properties {
        std::map<std::string, std::string> _properties;
        std::string _property_filename;
    public:
        properties();
        virtual ~properties();

        void load_properties(const std::string&);
        bool has_property(std::string) const;
        const std::string& operator[](const std::string&) const;
        const std::string& get_property(const std::string&) const;
        const std::string& filename() const;
        const std::map<std::string, std::string>& all_properties() const;

        // for adding new properties
        void save();
        void create(const std::string&);
        bool set_property(std::string, std::string);
    private:

    };
}

#endif /* PROPERTY_H */

