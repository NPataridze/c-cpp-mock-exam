#include <iostream>
#include <string>

class Customer
{
private:
    std::string name;
    std::string address;
    float shoeSize;

public:
    Customer(const std::string &n, const std::string &addr, float size)
        : name(n), address(addr), shoeSize(size) {}
    Customer(const Customer &other)
        : name(other.name), address(other.address), shoeSize(other.shoeSize) {}
    void setAddress(const std::string &addr)
    {
        address = addr;
    }
    float getShoeSize() const
    {
        return shoeSize;
    }
};
