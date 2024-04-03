// 1. Package-delivery services, such as FedEx®
// , DHL® and UPS®
// , offer a number of
// different shipping options, each with specific costs associated. Create an inheritance
// hierarchy to represent various types of packages. Use class Package as the base class of
// the hierarchy, then include classes TwoDayPackage and OvernightPackage that derive
// from Package.
// Base class Package should include data members representing the name, address, city,
// state and ZIP code for both the sender and the recipient of the package, in addition to
// data members that store the weight (in ounces) and cost per ounce to ship the package.
// Package’s constructor should initialize these data members. Ensure that the weight and
// cost per ounce contain positive values. Package should provide a public member
// function calculateCost that returns a double indicating the cost associated with shipping
// the package. Package’s calculateCost function should determine the cost by multiplying
// the weight by the cost per ounce. Derived class TwoDayPackage should inherit the
// functionality of base class Package, but also include a data member that represents a flat
// fee that the shipping company charges for two-day-delivery service. TwoDayPackage’s
// constructor should receive a value to initialize this data member. TwoDayPackage
// should redefine member function calculateCost so that it computes the shipping cost by
// adding the flat fee to the weight-based cost calculated by base class Package’s
// calculateCost function. Class OvernightPackage should inherit directly from class
// Package and contain an additional data member representing an additional fee per ounce
// charged for overnight-delivery service. OvernightPackage should redefine member
// function calculateCost so that it adds the additional fee per ounce to the standard cost
// per ounce before calculating the shipping cost. Write a main program that creates objects
// of each type of Package and tests member function calculateCost.


// Answer:

#include <iostream>
#include <string>

using namespace std;

class Package {
protected:
    string sender_name;
    string sender_address;
    string sender_city;
    string sender_state;
    string sender_zip;
    string recipient_name;
    string recipient_address;
    string recipient_city;
    string recipient_state;
    string recipient_zip;
    double weight;
    double cost_per_ounce;

public:
    Package(const string& sender_name, const string& sender_address, const string& sender_city,
            const string& sender_state, const string& sender_zip,
            const string& recipient_name, const string& recipient_address, const string& recipient_city,
            const string& recipient_state, const string& recipient_zip,
            double weight, double cost_per_ounce)
            : sender_name(sender_name), sender_address(sender_address), sender_city(sender_city),
              sender_state(sender_state), sender_zip(sender_zip), recipient_name(recipient_name),
              recipient_address(recipient_address), recipient_city(recipient_city),
              recipient_state(recipient_state), recipient_zip(recipient_zip),
              weight(max(0.0, weight)), cost_per_ounce(max(0.0, cost_per_ounce)) {}

    double calculateCost() const {
        return weight * cost_per_ounce;
    }
};

class TwoDayPackage : public Package {
private:
    double flat_fee;

public:
    TwoDayPackage(const string& sender_name, const string& sender_address, const string& sender_city,
                  const string& sender_state, const string& sender_zip,
                  const string& recipient_name, const string& recipient_address, const string& recipient_city,
                  const string& recipient_state, const string& recipient_zip,
                  double weight, double cost_per_ounce, double flat_fee)
            : Package(sender_name, sender_address, sender_city, sender_state, sender_zip,
                      recipient_name, recipient_address, recipient_city, recipient_state, recipient_zip,
                      weight, cost_per_ounce), flat_fee(max(0.0, flat_fee)) {}

    double calculateCost() const {
        return Package::calculateCost() + flat_fee;
    }
};

class OvernightPackage : public Package {
private:
    double additional_fee_per_ounce;

public:
    OvernightPackage(const string& sender_name, const string& sender_address, const string& sender_city,
                     const string& sender_state, const string& sender_zip,
                     const string& recipient_name, const string& recipient_address, const string& recipient_city,
                     const string& recipient_state, const string& recipient_zip,
                     double weight, double cost_per_ounce, double additional_fee_per_ounce)
            : Package(sender_name, sender_address, sender_city, sender_state, sender_zip,
                      recipient_name, recipient_address, recipient_city, recipient_state, recipient_zip,
                      weight, cost_per_ounce), additional_fee_per_ounce(max(0.0, additional_fee_per_ounce)) {}

    double calculateCost() const {
        return weight * (cost_per_ounce + additional_fee_per_ounce);
    }
};

int main() {
    // Input for regular package
    cout << "Enter sender's name: ";
    string sender_name, sender_address, sender_city, sender_state, sender_zip;
    getline(cin, sender_name);
    cout << "Enter sender's address: ";
    getline(cin, sender_address);
    cout << "Enter sender's city: ";
    getline(cin, sender_city);
    cout << "Enter sender's state: ";
    getline(cin, sender_state);
    cout << "Enter sender's ZIP code: ";
    getline(cin, sender_zip);
    cout<<endl;

    cout << "Enter recipient's name: ";
    string recipient_name, recipient_address, recipient_city, recipient_state, recipient_zip;
    getline(cin, recipient_name);
    cout << "Enter recipient's address: ";
    getline(cin, recipient_address);
    cout << "Enter recipient's city: ";
    getline(cin, recipient_city);
    cout << "Enter recipient's state: ";
    getline(cin, recipient_state);
    cout << "Enter recipient's ZIP code: ";
    getline(cin, recipient_zip);
    cout << endl;

    double weight, cost_per_ounce;
    cout << "Enter weight (in ounces): ";
    cin >> weight;
    cout << "Enter cost per ounce: ";
    cin >> cost_per_ounce;
    cout << endl;

    Package package1(sender_name, sender_address, sender_city, sender_state, sender_zip,
                     recipient_name, recipient_address, recipient_city, recipient_state, recipient_zip,
                     weight, cost_per_ounce);

    // Input for two-day package
    double flat_fee;
    cout << "Enter flat fee for two-day delivery: ";
    cin >> flat_fee;

    TwoDayPackage two_day_package(sender_name, sender_address, sender_city, sender_state, sender_zip,
                                  recipient_name, recipient_address, recipient_city, recipient_state, recipient_zip,
                                  weight, cost_per_ounce, flat_fee);

    // Input for overnight package
    double additional_fee_per_ounce;
    cout << "Enter additional fee per ounce for overnight delivery: ";
    cin >> additional_fee_per_ounce;

    OvernightPackage overnight_package(sender_name, sender_address, sender_city, sender_state, sender_zip,
                                       recipient_name, recipient_address, recipient_city, recipient_state, recipient_zip,
                                       weight, cost_per_ounce, additional_fee_per_ounce);
    
    cout << endl;
    // Output calculated costs
    cout << "Cost of regular package: " << package1.calculateCost() << endl;
    cout << "Cost of two-day package: " << two_day_package.calculateCost() << endl;
    cout << "Cost of overnight package: " << overnight_package.calculateCost() << endl;

    return 0;
}

// Output-
// Enter sender's name: Afia Zaman
// Enter sender's address: Warm Springs blvd
// Enter sender's city: Fremont
// Enter sender's state: CA
// Enter sender's ZIP code: 94539

// Enter recipient's name: Naim Rahman
// Enter recipient's address: Jerome Ave.
// Enter recipient's city: Fremont
// Enter recipient's state: CA
// Enter recipient's ZIP code: 94434

// Enter weight (in ounces): 45
// Enter cost per ounce: 3

// Enter flat fee for two-day delivery: 4
// Enter additional fee per ounce for overnight delivery: 3

// Cost of regular package: 135
// Cost of two-day package: 139
// Cost of overnight package: 270

