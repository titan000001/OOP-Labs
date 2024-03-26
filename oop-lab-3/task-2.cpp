#include<bits/stdc++.h>
using namespace std;

class Vehicle{
protected: 
    string m_fuelType;
    int m_capacity;
public:
    Vehicle(const string& fuelType, int capacity) : m_fuelType(fuelType), m_capacity(capacity){}

    virtual ~Vehicle(){}

    virtual void displayDetails() const{
        cout << "The vehicle's fuel type is " << m_fuelType << endl;
        cout << "The capacity of the tank is " << m_capacity << endl;
    }
};

class Car : public Vehicle{
protected:
    int m_numSeats;
public:
    Car(const string& fuelType, int capacity, int numSeats): Vehicle(fuelType, capacity), m_numSeats(numSeats){}

    void displayDetails() const override{
        Vehicle:: displayDetails();
        cout << "It has " << m_numSeats << " seats" << endl;
    }
};

class Sedan : public Car{
protected: 
    int m_bootSpace;
public:
    Sedan(const string& fuelType, int capacity, int numSeats, int bootSpace) : Car(fuelType, capacity, numSeats), m_bootSpace(bootSpace){}

    void displayDetails() const override{
        Car::displayDetails();
        cout << "The bootspace is " << m_bootSpace << " feet" << endl;
    }
};

int main(){
    Car car("Petrol", 1600,6);
    car.displayDetails();

    Sedan sedan("Diesel", 1200, 4 ,3);
    sedan.displayDetails();

    return 0;
}