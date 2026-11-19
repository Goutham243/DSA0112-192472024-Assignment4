
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Abstract base class
class Vehicle {
protected:
    string registrationNumber;
    double dailyRate;
    bool rented;

public:
    Vehicle(string reg, double rate)
        : registrationNumber(reg), dailyRate(rate), rented(false) {}

    virtual double calculateCharge(int days) const = 0;

    virtual void display() const = 0;

    void rent() {
        if (!rented) {
            rented = true;
            cout << registrationNumber << " rented successfully.\n";
        } else {
            cout << registrationNumber << " is already rented.\n";
        }
    }

    void returnVehicle(int bookedDays, int actualDays) {
        if (!rented) {
            cout << registrationNumber << " is not currently rented.\n";
            return;
        }

        double charge = calculateCharge(bookedDays);
        int lateDays = actualDays - bookedDays;

        if (lateDays > 0)
            charge += lateDays * dailyRate * 0.5;

        rented = false;

        cout << registrationNumber << " returned successfully.\n";
        cout << "Rental charge: Rs. " << charge << "\n";
        cout << "Late days: " << (lateDays > 0 ? lateDays : 0) << "\n";
    }

    virtual ~Vehicle() = default;
};

// Bicycle class
class Bicycle : public Vehicle {
public:
    Bicycle(string reg, double rate)
        : Vehicle(reg, rate) {}

    double calculateCharge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Bicycle: " << registrationNumber
             << " | Daily Rate: Rs. " << dailyRate << "\n";
    }
};

// Abstract intermediate class for motor vehicles
class MotorVehicle : public Vehicle {
protected:
    double fuelOrChargeLevel;
    string serviceDueDate;

public:
    MotorVehicle(string reg, double rate, double level, string date)
        : Vehicle(reg, rate),
          fuelOrChargeLevel(level),
          serviceDueDate(date) {}
};

// Two-wheeler class
class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string reg, double rate, double fuel, string date)
        : MotorVehicle(reg, rate, fuel, date) {}

    double calculateCharge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Two-Wheeler: " << registrationNumber
             << " | Fuel: " << fuelOrChargeLevel
             << " | Service Due: " << serviceDueDate << "\n";
    }
};

// Car class
class Car : public MotorVehicle {
protected:
    int seatingCapacity;

public:
    Car(string reg, double rate, double fuel,
        string date, int seats)
        : MotorVehicle(reg, rate, fuel, date),
          seatingCapacity(seats) {}

    double calculateCharge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Car: " << registrationNumber
             << " | Seats: " << seatingCapacity
             << " | Fuel: " << fuelOrChargeLevel
             << " | Service Due: " << serviceDueDate << "\n";
    }
};

// Electric car class
class ElectricCar : public Car {
private:
    double batteryCapacity;
    double energyUsedKWh;
    double ratePerKWh;

public:
    ElectricCar(string reg, double rate, double charge,
                string date, int seats, double battery,
                double energy, double electricityRate)
        : Car(reg, rate, charge, date, seats),
          batteryCapacity(battery),
          energyUsedKWh(energy),
          ratePerKWh(electricityRate) {}

    double calculateCharge(int days) const override {
        return dailyRate * days +
               energyUsedKWh * ratePerKWh;
    }

    void display() const override {
        cout << "Electric Car: " << registrationNumber
             << " | Seats: " << seatingCapacity
             << " | Battery: " << batteryCapacity << " kWh"
             << " | Service Due: " << serviceDueDate << "\n";
    }
};

// New vehicle type added without changing existing classes
class ElectricBus : public MotorVehicle {
private:
    double energyUsedKWh;
    double ratePerKWh;

public:
    ElectricBus(string reg, double rate, double charge,
                string date, double energy, double electricityRate)
        : MotorVehicle(reg, rate, charge, date),
          energyUsedKWh(energy),
          ratePerKWh(electricityRate) {}

    double calculateCharge(int days) const override {
        return dailyRate * days +
               energyUsedKWh * ratePerKWh;
    }

    void display() const override {
        cout << "Electric Bus: " << registrationNumber
             << " | Battery Level: " << fuelOrChargeLevel
             << " | Service Due: " << serviceDueDate << "\n";
    }
};

int main() {
    cout << fixed << setprecision(2);

    Bicycle bicycle("BIKE101", 100);
    TwoWheeler bike("BIKE202", 250, 80, "15-12-2026");
    Car car("CAR303", 1500, 60, "20-12-2026", 5);
    ElectricCar ev("EV404", 1800, 90, "25-12-2026",
                   5, 60, 20, 8);
    ElectricBus bus("BUS505", 3000, 85, "30-12-2026",
                    100, 8);

    // Array of base-class pointers
    Vehicle* fleet[] = {
        &bicycle, &bike, &car, &ev, &bus
    };

    int count = sizeof(fleet) / sizeof(fleet[0]);

    cout << "VEHICLE RENTAL FLEET\n\n";

    cout << "AVAILABLE VEHICLES:\n";
    for (int i = 0; i < count; i++)
        fleet[i]->display();

    cout << "\nRENTING VEHICLES:\n";
    for (int i = 0; i < count; i++)
        fleet[i]->rent();

    cout << "\nRETURNING VEHICLES:\n";

    bicycle.returnVehicle(2, 2);
    bike.returnVehicle(2, 3);
    car.returnVehicle(3, 3);
    ev.returnVehicle(2, 3);
    bus.returnVehicle(2, 2);

    cout << "\nADDING NEW VEHICLE TYPE:\n";
    bus.display();

    return 0;
}
