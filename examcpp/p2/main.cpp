
#include <iostream>
using namespace std;
class Vehicle
{
protected:
    string brand;
    double average_speed;

public:
    Vehicle()
    {
        brand = "vehicle";
        average_speed = 50;
    }
    Vehicle(const Vehicle &obj)
    {
        brand = obj.brand;
        average_speed = obj.average_speed;
        cout << "Copy constructor" << endl;
    }
    virtual double compute_avg_time(double distance)
    {
        cout << "Compute in Vehicle" << endl;
        return distance / average_speed;
    }
    friend void print(Vehicle);
    virtual ~Vehicle()
    {
        cout << "Destructor Vehicle" << endl;
    }
};
void print(Vehicle a)
{
    cout << a.brand << endl;
}
class Car : public virtual Vehicle
{
protected:
    double engine_volume;

public:
    Car()
    {
        average_speed = 70;
    }
};
class Bike : public virtual Vehicle
{
protected:
    double wind_factor;

public:
    Bike()
    {
        average_speed = 20;
        wind_factor = 0.5;
    }
    double compute_avg_time(double distance)
    {
        cout << "Compute in Bike" << endl;
        return wind_factor * distance / average_speed;
    }
};
class Hybrid : public Car, public Bike
{
public:
    ~Hybrid()
    {
        cout << "Destructor Hybrid" << endl;
    }
};
int main()
{
    Vehicle *a[4];
    a[0] = new Vehicle();
    a[1] = new Car();
    a[2] = new Bike();
    a[3] = new Hybrid();
    for (int i = 0; i < 4; i++)
        cout << a[i]->compute_avg_time(100) << endl;
    print(*(a[0]));
    for (int i = 0; i < 4; i++)
        delete a[i];
    return 0;
}
