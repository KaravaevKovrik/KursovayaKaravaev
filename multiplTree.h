#ifndef MULTIPLTREE_H
#define MULTIPLTREE_H

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <algorithm>

class MultiplTree {
public:
    MultiplTree(const std::string& name = "", const std::string& value = "")
        : name(name), value(value) {}

    void setName(const std::string& name) { this->name = name; }
    std::string getName() const { return name; }

    void setValue(const std::string& value) { this->value = value; }
    void setValue(double value) { this->value = std::to_string(value); }
    void setValue(int value) { this->value = std::to_string(value); }

    std::string getValue() const { return value; }

    bool isInt() const {
        try {
            std::stoi(value);
            return true;
        } catch (...) {
            return false;
        }
    }

    bool isDouble() const {
        try {
            std::stod(value);
            return true;
        } catch (...) {
            return false;
        }
    }

    int getInt() const {
        try {
            return std::stoi(value);
        } catch (...) {
            return 0;
        }
    }

    double getDouble() const {
        try {
            return std::stod(value);
        } catch (...) {
            return 0.0;
        }
    }

    size_t getCountSub() const { return children.size(); }

    std::shared_ptr<MultiplTree> getSub(size_t i) const {
        if (i < children.size()) {
            return children[i];
        }
        return nullptr;
    }

    std::shared_ptr<MultiplTree> getSub(const std::string& name) const {
        for (const auto& child : children) {
            if (child->getName() == name) {
                return child;
            }
        }
        return nullptr;
    }

    void addSub(const std::shared_ptr<MultiplTree>& subNode) {
        children.push_back(subNode);
    }

    void removeSub(const std::string& name) {
        auto it = std::remove_if(children.begin(), children.end(),
                                 [&](const std::shared_ptr<MultiplTree>& child) {
                                     return child->getName() == name;
                                 });
        children.erase(it, children.end());
    }

    std::shared_ptr<MultiplTree> findNode(const std::string& name) {
        if (this->name == name) {
            return std::shared_ptr<MultiplTree>(this);
        }
        for (const auto& child : children) {
            auto found = child->findNode(name);
            if (found != nullptr) {
                return found;
            }
        }
        return nullptr;
    }

private:
    std::string name;
    std::string value;
    std::vector<std::shared_ptr<MultiplTree>> children;
};

#endif 
