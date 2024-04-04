// 4.	Find the errors in the following class and explain how to correct them. Please test it in main function

// class Example{
//   public:
//     Example( int y = 10 ): data( y ){
//       // empty body
//     } // end Example constructor
//     int getIncrementedData() const{
//       return data++;
//     } // end function getIncrementedData
//     static int getCount(){
//       cout << "Data is " << data << endl;
//       return count;
//     } // end function getCount
//   private:
//     int data;
//     static int count;
// }; // end class Example

// Answer:

#include <iostream>
using namespace std;

class Example {
public:
    Example(int y = 10) : data(y) {
    } 
    int getIncrementedData() {
        return data++;
    } 

    static int getCount() {
        cout << "Count is " << count << endl;
        return count;
    } 

private:
    int data;
    static int count;
}; 

int Example::count = 0;

int main() {
    Example obj;
    cout << "Incremented data: " << obj.getIncrementedData() << endl;

    Example::getCount();

    return 0;
}

// Output-
// Incremented data: 10
// Count is 0
