// 2. A supermarket chain has asked you to develop an automatic checkout system. All
// products are identifiable by means of a barcode and the product name. Groceries are
// either sold in packages or by weight. Packed goods have fixed prices. The price of
// groceries sold by weight is calculated by multiplying the weight by the current price per
// kilo.
// Develop the classes needed to represent the products first and organize them
// hierarchically. The Product class, which contains generic information on all products
// (barcode, name, etc.), can be used as a base class.
// a. The Product class contains two data members of type long used for storing
// barcodes and the product name. Define a constructor with parameters for
// both data members. Add default values for the parameters to provide a
// default constructor for the class. In addition to the access methods setCode()
// and getCode(), also define the methods scanner() and printer(). For test
// purposes, these methods will simply output product data on screen or read
// the data of a product from the keyboard.
// b. The next step involves developing special cases of the Product class. Define
// two classes derived from Product, PrepackedFood and FreshFood. In
// addition to the product data, the PrepackedFood class should contain the unit
// price and the FreshFood class should contain a weight and a price per kilo as
// data members.
// In both classes define a constructor with parameters providing default-values
// for all data members. Use both the base and member initializer.
// Define the access methods needed for the new data members. Also redefine
// the methods scanner() and printer() to take the new data members into
// consideration.
// c. Test the various classes in a main function that creates two objects each of
// the types Product, PrepackedFood and FreshFood. One object of each type
// is fully initialized in the object definition. Use the default constructor to
// create the other object. Test the get and set methods and the scanner()
// method and display the products on screen.

// Answer-

#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    Product(long barcode = 0, string name = "")
        : barcode(barcode), name(name) {}

    void setCode(long newBarcode) {
        barcode = newBarcode;
    }

    long getCode() const {
        return barcode;
    }

    void scanner() {
        cout << "Scanning Product: " << name << endl;
    }

    void printer() {
       cout << "Product Details - Barcode: " << barcode << ", Name: " << name << endl << endl;
    }

protected:
    long barcode;
    std::string name;
};

class PrepackedFood : public Product {
public:
    PrepackedFood(long barcode = 0, string name = "", double unitPrice = 0.0)
        : Product(barcode, name), unitPrice(unitPrice) {}

    void scanner() {
        cout << "Scanning PrepackedFood: " << name << endl;
    }

    void printer() {
       cout << "PrepackedFood Details - Barcode: " << barcode << ", Name: " << name << ", Unit Price: $" << unitPrice << endl << endl;
    }

private:
    double unitPrice;
};

class FreshFood : public Product {
public:
    FreshFood(long barcode = 0, string name = "", double weight = 0.0, double pricePerKilo = 0.0)
        : Product(barcode, name), weight(weight), pricePerKilo(pricePerKilo) {}

    void scanner() {
        cout << "Scanning FreshFood: " << name << endl;
    }

    void printer() {
        cout << "FreshFood Details - Barcode: " << barcode << ", Name: " << name << ", Weight: " << weight << "kg, Price Per Kilo: $" << pricePerKilo << endl << endl;
    }

private:
    double weight;
    double pricePerKilo;
};

int main() {
    Product product1(12345, "Milk");
    PrepackedFood prepackedFood1(23456, "Cookies", 2.99);
    FreshFood freshFood1(34567, "Apples", 1.5, 3.50);

    Product product2;
    PrepackedFood prepackedFood2;
    FreshFood freshFood2;

    product2.setCode(45678);
    prepackedFood2.setCode(56789);
    freshFood2.setCode(67890);

    product1.scanner();
    product1.printer();

    prepackedFood1.scanner();
    prepackedFood1.printer();

    freshFood1.scanner();
    freshFood1.printer();

    return 0;
}

// Output-
// Scanning Product: Milk
// Product Details - Barcode: 12345, Name: Milk

// Scanning PrepackedFood: Cookies
// PrepackedFood Details - Barcode: 23456, Name: Cookies, Unit Price: $2.99

// Scanning FreshFood: Apples
// FreshFood Details - Barcode: 34567, Name: Apples, Weight: 1.5kg, Price Per Kilo: $3.5

