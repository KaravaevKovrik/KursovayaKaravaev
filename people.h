#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>

class People {
public:
    People(const std::string& name, const std::string& role);

    std::string getName() const;
    std::string getRole() const;

private:
    std::string name;
    std::string role;
};



People::People(const std::string& name, const std::string& role)
    : name(name), role(role) {}

std::string People::getName() const {
    return name;
}
std::string People::getRole() const {
    return role;
}

#endif 
