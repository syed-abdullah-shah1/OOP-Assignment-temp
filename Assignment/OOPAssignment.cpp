#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n)
    {
        name = n;
    }

    virtual void showRole() = 0;

    virtual ~Person() {}

    string getName() const
    {
        return name;
    }
};

class User : public Person
{
protected:
    int userId;

public:
    User(string n, int id) : Person(n)
    {
        userId = id;
    }

    virtual void dashboard() = 0;

    virtual ~User() {}
};

class Buyer : public User
{
public:
    Buyer(string n, int id) : User(n, id) {}

    void showRole() override
    {
        cout << "\n========================================\n";
        cout << "              BUYER PANEL               \n";
        cout << "========================================\n";
        cout << "Buyer Name : " << name << endl;
        cout << "Buyer ID   : " << userId << endl;
    }

    void dashboard() override
    {
        cout << "Activity   : Viewing available vehicles\n";
        cout << "Features   : Search, Compare, Purchase\n";
    }
};

class Seller : public User
{
public:
    Seller(string n, int id) : User(n, id) {}

    void showRole() override
    {
        cout << "\n========================================\n";
        cout << "              SELLER PANEL              \n";
        cout << "========================================\n";
        cout << "Seller Name : " << name << endl;
        cout << "Seller ID   : " << userId << endl;
    }

    void dashboard() override
    {
        cout << "Activity    : Managing vehicle listings\n";
        cout << "Features    : Add, Update, Remove Vehicles\n";
    }
};

class Admin : public User
{
public:
    Admin(string n, int id) : User(n, id) {}

    void showRole() override
    {
        cout << "\n========================================\n";
        cout << "               ADMIN PANEL              \n";
        cout << "========================================\n";
        cout << "Admin Name : " << name << endl;
        cout << "Admin ID   : " << userId << endl;
    }

    void dashboard() override
    {
        cout << "Activity   : Monitoring complete system\n";
        cout << "Features   : Manage Users and Reports\n";
    }
};

class Vehicle
{
protected:
    string brand;
    double price;

public:
    Vehicle(string b, double p)
    {
        brand = b;
        price = p;
    }

    virtual void displayDetails() = 0;

    virtual double calculateTax() = 0;

    virtual ~Vehicle() {}

    double getPrice() const
    {
        return price;
    }

    string getBrand() const
    {
        return brand;
    }

    friend void compareVehicle(Vehicle &v1, Vehicle &v2);
};

class Engine
{
public:
    virtual void engineType() = 0;

    virtual ~Engine() {}
};

class Insurance
{
public:
    virtual void insuranceInfo() = 0;

    virtual ~Insurance() {}
};

class Car : public Vehicle, public Engine, public Insurance
{
    int seats;
    string color;

public:
    Car(string b, double p, int s, string c)
        : Vehicle(b, p)
    {
        seats = s;
        color = c;
    }

    void displayDetails() override
    {
        cout << "\n----------------------------------------\n";
        cout << "              CAR DETAILS               \n";
        cout << "----------------------------------------\n";
        cout << "Brand        : " << brand << endl;
        cout << "Color        : " << color << endl;
        cout << "Seats        : " << seats << endl;
        cout << "Price        : Rs. " << fixed << setprecision(0)
             << price << endl;
    }

    double calculateTax() override
    {
        return price * 0.12;
    }

    void engineType() override
    {
        cout << "Engine Type  : Petrol Engine\n";
    }

    void insuranceInfo() override
    {
        cout << "Insurance    : Full insurance available\n";
    }

    bool operator==(const Car &obj) const
    {
        return price == obj.price;
    }

    Car operator+(const Car &obj) const
    {
        return Car(
            brand + " & " + obj.brand,
            price + obj.price,
            seats + obj.seats,
            color + " Mix");
    }

    friend void showCarPrice(const Car &c);
};

class Bike : public Vehicle, public Engine
{
    bool sportsMode;
    int modelYear;

public:
    Bike(string b, double p, bool s, int y)
        : Vehicle(b, p)
    {
        sportsMode = s;
        modelYear = y;
    }

    void displayDetails() override
    {
        cout << "\n----------------------------------------\n";
        cout << "             BIKE DETAILS               \n";
        cout << "----------------------------------------\n";
        cout << "Brand        : " << brand << endl;
        cout << "Model Year   : " << modelYear << endl;

        if (sportsMode)
            cout << "Sports Mode  : Available\n";
        else
            cout << "Sports Mode  : Not Available\n";

        cout << "Price        : Rs. " << fixed << setprecision(0)
             << price << endl;
    }

    double calculateTax() override
    {
        return price * 0.07;
    }

    void engineType() override
    {
        cout << "Engine Type  : Hybrid Engine\n";
    }

    Bike operator+(const Bike &obj) const
    {
        return Bike(
            brand + " & " + obj.brand,
            price + obj.price,
            sportsMode || obj.sportsMode,
            (modelYear > obj.modelYear) ? modelYear : obj.modelYear);
    }

    friend void bikeAccess(const Bike &b);
};

void compareVehicle(Vehicle &v1, Vehicle &v2)
{
    cout << "\n========================================\n";
    cout << "          VEHICLE COMPARISON            \n";
    cout << "========================================\n";

    cout << "First Vehicle  : " << v1.getBrand() << endl;
    cout << "Second Vehicle : " << v2.getBrand() << endl;

    if (v1.price > v2.price)
        cout << "Result : First vehicle is more expensive\n";

    else if (v1.price < v2.price)
        cout << "Result : Second vehicle is more expensive\n";

    else
        cout << "Result : Both vehicles have same price\n";
}

void showCarPrice(const Car &c)
{
    cout << "\nFriend Function Accessing Car Price\n";
    cout << "Car Price : Rs. " << fixed << setprecision(0)
         << c.price << endl;
}

void bikeAccess(const Bike &b)
{
    cout << "\nFriend Function Accessing Bike Price\n";
    cout << "Bike Price : Rs. " << fixed << setprecision(0)
         << b.price << endl;
}

void displayMenu()
{
    cout << "\n========================================\n";
    cout << "            SYSTEM FEATURES             \n";
    cout << "========================================\n";
    cout << "1. User Management\n";
    cout << "2. Vehicle Management\n";
    cout << "3. Vehicle Comparison\n";
    cout << "4. Tax Calculation\n";
    cout << "5. Operator Overloading\n";
    cout << "6. Friend Functions\n";
}

int main()
{
    cout << "\n****************************************\n";
    cout << "      VEHICLE MANAGEMENT SYSTEM         \n";
    cout << "****************************************\n";

    displayMenu();

    Buyer buyer1("Abdullah", 101);
    Seller seller1("Usman", 202);
    Admin admin1("Bilal", 303);

    vector<User *> users;

    users.push_back(&buyer1);
    users.push_back(&seller1);
    users.push_back(&admin1);

    cout << "\n========================================\n";
    cout << "             USER DETAILS               \n";
    cout << "========================================\n";

    for (User *u : users)
    {
        u->showRole();
        u->dashboard();
    }

    Car car1("Toyota Corolla", 4500000, 5, "White");
    Car car2("Honda Civic", 4500000, 4, "Silver");

    Bike bike1("Yamaha", 1200000, true, 2024);
    Bike bike2("Suzuki", 1000000, false, 2023);

    vector<Vehicle *> vehicles;

    vehicles.push_back(&car1);
    vehicles.push_back(&bike1);

    cout << "\n========================================\n";
    cout << "           VEHICLE DETAILS              \n";
    cout << "========================================\n";

    for (Vehicle *v : vehicles)
    {
        v->displayDetails();

        cout << "Tax Amount   : Rs. "
             << fixed << setprecision(0)
             << v->calculateTax() << endl;
    }

    cout << "\n========================================\n";
    cout << "            ENGINE DETAILS              \n";
    cout << "========================================\n";

    car1.engineType();
    car1.insuranceInfo();

    cout << endl;

    bike1.engineType();

    cout << "\n========================================\n";
    cout << "         OPERATOR OVERLOADING           \n";
    cout << "========================================\n";

    if (car1 == car2)
        cout << "Both cars have same price\n";
    else
        cout << "Cars have different prices\n";

    Car totalCar = car1 + car2;

    cout << "\nCombined Car Details\n";
    totalCar.displayDetails();

    Bike totalBike = bike1 + bike2;

    cout << "\nCombined Bike Details\n";
    totalBike.displayDetails();

    compareVehicle(car1, bike1);

    showCarPrice(car1);
    bikeAccess(bike1);

    cout << "\n========================================\n";
    cout << "        PROGRAM EXECUTED SUCCESSFULLY   \n";
    cout << "========================================\n";

    return 0;
}